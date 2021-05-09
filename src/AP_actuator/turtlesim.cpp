/*
 * Copyright (c) 2009, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <QApplication>

#include <ros/ros.h>

#include "include/turtle_frame.h"

turtlesim::TurtleFrame* Framept{NULL} ;
/*apinclude*/
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>

#include "ara/core/future.h"
#include "ara/log/logging.h"

#ifdef ENABLE_EXEC_MANAGER
#include "ara/exec/application_client.h"
#endif

#include "commandlineparser/command_line_parser.h"
#include "include/logging_cfg.h"

#include "vac/memory/optional.h"
#include "vac/memory/three_phase_allocator.h"
#include "include/AP_actuator_swc.h"

/*
#include "include/turtle_someip_client.h"
*/

#ifdef PERSISTENCY_ON
#include "persistency/persistency_calculator_client.h"
#endif

#ifdef ENABLE_EXEC_MANAGER
using ApplicationClient = ara::exec::ApplicationClient;
using ApplicationState = ara::exec::ApplicationState;
#endif

#ifdef ENABLE_DIAG_MANAGER
#include "amsr/diag/lib_ara_diag.h"
#include "diagnostics/diagnostic_calculator_application.h"
#endif


/* Forward declarations */
void Initialize_Signalhandler(void);
void SignalHandler(void);
#ifdef ENABLE_DIAG_MANAGER
void run_diagnostic_application(diagnostics::DiagnosticCalculatorApplication& app);
#endif


/**
 * \brief Container for command line arguments.
 */
struct CommandLineArguments {
    /**
     * \brief Path to configuration file.
     */
    std::string cfg_path_;
    /**
     * \brief Enables the applicationstate report to the executionmanager if true.
     */
    bool enable_em_;
};

/**
 * \brief Flag to identify whether the application was requested to terminate, i.e., has received a SIGTERM
 */
std::atomic_bool exit_requested(false);

/**
 * \brief Vector to store all threads spawned by this application.
 */
std::vector<std::thread> threads;

/**
 * \brief Prints the usage message.
 *
 * \param argc argument count
 * \param argv command line arguments
 */
static void Usage(const int argc, char* argv[]) {
    if (argc > 0) {
        std::cerr << "usage: " << argv[0] << R"( [-h] [-d] -c <config file path>
           -h                            Print this message and exit.
           -c <config file path>         Specify the location of the configuration file.
           -d                            Disabling the applicationstate report to the executionmanager.
        )";
    } else {
        std::cerr << "usage: calculatorClient "
                  << R"( [-h] [-d] -c <config file path>
           -h                            Print this message and exit.
           -c <config file path>         Specify the location of the configuration file.
           -d                            Disabling the applicationstate report to the executionmanager.
        )";
    }
}

/**
 * \brief Parses command line arguments.
 *
 * \param argc Command line argument count.
 * \param argv Array of pointers to command line arguments.
 * \return Parsed arguments.
 */
static CommandLineArguments ParseArguments(int argc, char* argv[]) {
    CommandLineArguments args;
    args.cfg_path_ = "/vitis/turtlesim/install/opt/AP_actuator/etc/application.json";
    args.enable_em_ = true;

    apns::commandlineparser::CommandLineParser parser(argc, argv, "hc:d");
    for (auto& it : parser) {
        switch (it.GetOption()) {
            case 'h':
                Usage(argc, argv);
                exit(EXIT_SUCCESS);
                break;
            case 'c':
                args.cfg_path_ = it.GetOptionArgument();
                break;
            case 'd':
                args.enable_em_ = false;
                break;
            default:
                Usage(argc, argv);
                exit(EXIT_FAILURE);
                break;
        }
    }
    if (args.cfg_path_ == "") {
        ara::log::Logger& logger_ctx{
                ara::log::CreateLogger(apns::config::kContextIdTulClientMethodInvocator, "Context for atua client")};

        logger_ctx.LogError() << "No configuration file path provided\n";
        exit(EXIT_FAILURE);
    }
    return args;
}

class TurtleApp : public QApplication
{
public:
  ros::NodeHandlePtr nh_;

  TurtleApp(int& argc, char** argv)
    : QApplication(argc, argv)
  {
    ros::init(argc, argv, "AP_actuator", ros::init_options::NoSigintHandler);
    nh_.reset(new ros::NodeHandle);
  }

  int exec()
  {
    turtlesim::TurtleFrame frame;
      Framept=&frame;
    frame.show();
/*      apns::AP_actuator_swc::FindService();*/

      QApplication::exec();

      return 0;
  }
};


int main(int argc, char** argv)
{

    // Initialize signal handler to ensure all signals are blocked for all child processes
//    Initialize_Signalhandler();

    // Initialize logging framework
    ara::core::Result<void> result{ara::log::Initialize()};

  /*  ara::core::Result<void> result { ara::log::Initialize("./etc/logging_config.json") };

    if (!result.HasValue()) {
        std::cerr << "Logging initialization failed.";
        std::cerr << "Result contains: " << result.Error().Message() << ", "
                  << result.Error().UserMessage();
    }*/
    // Create logger in the allocation phase
    ara::log::Logger &logger_ctx { ara::log::CreateLogger(
            apns::config::kContextIdTulClientMethodInvocator,
            "Context for actuator method invocation") };
    logger_ctx.LogInfo() << "Starting try atuator Client";

    CommandLineArguments args = ParseArguments(argc, argv);

#ifdef ENABLE_EXEC_MANAGER
    vac::memory::optional<ApplicationClient> app_client;
    if (args.enable_em_) {
        // Instantiate the ApplicationClient
        app_client.emplace();
    }
#endif
// Loading config file and initialize runtime
    logger_ctx.LogInfo() << "Initializing runtime...";
    apns::AP_actuator_swc::Initialize(args.cfg_path_);

    // Set allocation phase to 'steady' after all memory resources are initialized and allocated
    logger_ctx.LogDebug() << __FUNCTION__
                          << " Setting AllocationPhaseManager::AllocationPhase to 'steady'.";
    vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
            vac::memory::AllocationPhaseManager::AllocationPhase::steady);


//    apns::AP_actuator_swc::FindService();


#ifdef ENABLE_EXEC_MANAGER
    if (args.enable_em_ && app_client.has_value()) {
        // Report application state to execution management
        logger_ctx.LogInfo() << "Reporting application state kRunning.";
        app_client->ReportApplicationState(ApplicationState::kRunning);
    }
#endif
  TurtleApp app(argc, argv);
    logger_ctx.LogInfo() << "qt app exec";
   app.exec();
    logger_ctx.LogInfo() << "qt app not exec";

/*    apns::AP_actuator_swc::UnsubscribeToEvents();*/

    logger_ctx.LogInfo() << "Finished client operation";
    std::this_thread::sleep_for(std::chrono::seconds(5));
#ifdef ENABLE_EXEC_MANAGER
    if (args.enable_em_ && app_client.has_value()) {
        // Report application state to execution management
        logger_ctx.LogInfo() << "Reporting application state kTerminating.";
        app_client->ReportApplicationState(ApplicationState::kTerminating);
    }
#endif
    logger_ctx.LogInfo() << "Terminating";

    // Set allocation phase to 'deallocation' before destroying and deallocating all memory resources
    logger_ctx.LogDebug() << __FUNCTION__
                          << " Setting AllocationPhaseManager::AllocationPhase to 'deallocation'";
    vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
            vac::memory::AllocationPhaseManager::AllocationPhase::deallocation);

    return 0;
}


/**
 * \brief  Function to initialize the calculator client
 */
void Initialize_Signalhandler(void) {
    /* Block all signals for this thread. Signal mask will be inherited by subsequent threads. */
    sigset_t signals1;
    sigfillset(&signals1);
    pthread_sigmask(SIG_SETMASK, &signals1, NULL);
    /* spawn a new signal handler thread*/
    threads.emplace_back(SignalHandler);
}

/**
 * \brief Signal handler function for SIGTERM
 */
void SignalHandler(void) {
    sigset_t signal_set;
    int sig = -1;
    sigemptyset(&signal_set); /* Empty the set of signals */
    sigaddset(&signal_set, SIGTERM); /* Add only SIGTERM to set */

    while (sig != SIGTERM) {
        sigwait(&signal_set, &sig);
        // We hope that the program is terminated after initialization of logging has finished, so we can call this API.
        // Otherwise a segfault will be created
        ara::log::Logger &logger_ctx { ara::log::CreateLogger(
                apns::config::kContextIdTulClientMethodInvocator,
                "Context for calculator method invocation") };
        logger_ctx.LogInfo() << "Received signal number:" << sig;
    }
    ara::log::Logger &logger_ctx { ara::log::CreateLogger(
            apns::config::kContextIdTulClientMethodInvocator,
            "Context for calculator method invocation") };
    logger_ctx.LogInfo() << "Received signal SIGTERM";
    exit_requested = true;
}
//#ifdef ENABLE_DIAG_MANAGER
//void run_diagnostic_application(diagnostics::DiagnosticCalculatorApplication& app) { app.Run(); }
//#endif
