/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file
 *        \brief  Entry point of the example application.
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <csignal>

#include "ara/core/abort.h"
#include "ara/core/result.h"

#include "include/application.h"
#include "commandlineparser/command_line_parser.h"
#include "include/rosap_converter_swc.h"
using vac::container::operator""_sv;

namespace {
/*!
 * \brief Initializes the signal handling.
 * \return void.
 */
void InitializeSignalHandling() noexcept {
  bool success{true};
  sigset_t signals;

  /* Block all signals except the SIGABRT, SIGBUS, SIGFPE, SIGILL, SIGSEGV signals because blocking them will lead to
   * undefined behavior. Their default handling shall not be changed (dependent on underlying POSIX environment, usually
   * process is killed and a dump file is written). Signal mask will be inherited by subsequent threads. */

  success = success && (0 == sigfillset(&signals));
  success = success && (0 == sigdelset(&signals, SIGABRT));
  success = success && (0 == sigdelset(&signals, SIGBUS));
  success = success && (0 == sigdelset(&signals, SIGFPE));
  success = success && (0 == sigdelset(&signals, SIGILL));
  success = success && (0 == sigdelset(&signals, SIGSEGV));
  success = success && (0 == pthread_sigmask(SIG_SETMASK, &signals, nullptr));

  if (!success) {
    ara::core::Abort("InitializeSignalHandling failed.");
  }
}

}  // namespace
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
        /*ara::log::Logger& logger_ctx{
                ara::log::CreateLogger(apns::config::kContextIdTulClientMethodInvocator, "Context for tultle client")};
*/
//        logger_ctx.LogError() << "No configuration file path provided\n";
        exit(EXIT_FAILURE);
    }
    return args;
}






/*!
 * \brief Entry Point of the process.
 * \return zero when successfully executed
 */
int main(int argc, char** argv){
  /* Initialize signal handling. */
  InitializeSignalHandling();
    CommandLineArguments args = ParseArguments(argc, argv);
  /* Initialize logging. */
  ara::core::Result<void> result{ara::log::Initialize()};
  if (!result.HasValue()) {
    std::cerr << "Logging initialization failed.";
    std::cerr << "Result contains: " << result.Error().Message() << ", " << result.Error().UserMessage();
  }

  /* Create the application object. */
//    ros::init(argc, argv, "AP_actuator");
  Application app;
    std::shared_ptr<Application> apptr{&app};
    app.init();
    app.ReportApplicationState(ara::exec::ApplicationState::kRunning);

    app.Run(apptr);
    app.ReportApplicationState(ara::exec::ApplicationState::kTerminating);

    app.shutdown();
  return 0;
}
