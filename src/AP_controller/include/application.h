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
 *        \brief  Main class representing the application.
 *
 *      \details  -
 *
 *********************************************************************************************************************/

#ifndef SRC_rosap_exe_APPLICATION_H_
#define SRC_rosap_exe_APPLICATION_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <ara/exec/application_client.h>
#include "ara/log/logging.h"
#include "osabstraction/process/process.h"
#include "vac/container/string_literals.h"
#include "ara/com/runtime.h"
#include "ara/com/types.h"
#include "ara/core/future.h"
#include "ara/log/logging.h"
//#include "ros/ros.h"
//#include "rosap_converter.h"
#include "LKA_controller.h"
/*!
 * \brief Namespace for the example application.
 */

/*!
 * \brief Main class representing the application.
 * \vprivate Example class for component internal use.
 */
class Application final {
 public:
  /*!
   * \brief Constructor of class Application.
   */
  Application();

  /*!
   * \brief Deleted copy constructor
   */
  Application(Application const&) = delete;

  /*!
   * \brief Default move constructor
   */
  Application(Application&& other) noexcept = delete;

  /*!
   * \brief Destructor of class Application.
   */
  ~Application();

  /*!
   * \brief Deleted copy assignment operator
   * \return Reference to application
   */
  Application& operator=(Application const&) & = delete;

  /*!
   * \brief Default move assignment operator
   * \return Reference to application
   */
  Application& operator=(Application&& other) & = delete;
  /*!
   * \brief Lifecycle method for run mode.
   * \return Error (Exit) code of application.
   */
  std::int8_t init();
  std::int8_t Run(std::shared_ptr<Application> iapptr);
    std::int8_t shutdown();
    std::atomic_bool exit_requested_{false};

    /*!
 * \brief Reporting the given application state
 * \param application_state The application state to report
 */
    void ReportApplicationState(ara::exec::ApplicationState application_state);

public:
  /*!
   * \brief Start threads given by information in handed over thread information.
   * \param thread_info The thread information array.
   * \return The process id of the started thread.
   * \error TemplateErrc::kThreadCreationFailed Naming the thread after creation has failed.
   */
  ara::core::Result<osabstraction::process::ProcessId> StartSignalHandlerThread();

  /*!
   * \brief Entry point of the thread receiving signals from the execution manager.
   */
  void SignalHandlerThread();



  /*!
   * \brief Logger instance.
   */
  ara::log::Logger& log_;

  /*!
   * \brief ApplicationClient instance
   */
  ara::exec::ApplicationClient application_client_;

  /*!
   * \brief Signal handler thread.
   */
  std::thread signal_handler_thread_{};

  /*!
   * \brief Flag to exit the application.
   */


  /*!
   * \brief Flag to mark if the application exit was triggered by a signal.
   */
  std::atomic_bool terminated_by_signal_{false};

  /*!
   * \brief Flag to indicate initialization error. Only used in main thread.
   */
  bool has_initialization_failed_{false};

    std::shared_ptr<LKA_controller> LKASWCptr;

//    std::shared_ptr<ToGoal_controller> ToGoptr;

//    std::shared_ptr<ros::AsyncSpinner> rosspinnerptr;


  /*!
   * \brief Friend test declarations
   */
  FRIEND_TEST(ApplicationTestFixture, RunWithoutSuccessfulInitialization);




};


#endif  // SRC_rosap_exe_APPLICATION_H_
