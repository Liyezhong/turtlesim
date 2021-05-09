/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  rosap_exe/ipc-posix/apns/driving_information_skeleton_ipc_event_manager.h
 *        \brief  IPC skeleton event handling for events and field notifications of service 'driving_information'
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_ipc
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_EVENT_MANAGER_H_
#define ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include "apns/driving_information.h"
#include "apns/driving_information_skeleton.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"
#include "ipc_binding/internal/ipc_protocol/message.h"
#include "socal/internal/session_handler.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {

// Forward-declaration for back-reference
class driving_informationProvidedIpcServiceInstance;

/* ---- Event 'vehicle_speed' ------------------------------------------- */
/*!
 * \brief IPC Skeleton event manager for event 'vehicle_speed'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class driving_informationSkeletonIpcEventManagervehicle_speed final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related IPC skeleton binding to be used
   */
  explicit driving_informationSkeletonIpcEventManagervehicle_speed(
      driving_informationProvidedIpcServiceInstance& skeleton_binding);

  /*!
   * \brief Send a event sample of skeleton event 'vehicle_speed'.
   *
   * \trace SPEC-4981292
   * \param data Event sample of type speedtype
   */
  void Send(const apns::speedtype& data);

  /*!
   * \brief Called on a reception of a new subscription request.
   * \details In case of normal events, nothing is done. In case of field events, initial field notification is sent.
   * \return Initial field event notification message in case of field notification, or empty optional in case of normal events.
   */
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> HandleEventSubscription();

  /*!
   * \brief IPC event identifier for this event.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{1U};

 private:
  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
   amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /** Skeleton binding for event transmission */
  driving_informationProvidedIpcServiceInstance& skeleton_binding_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::ipc_binding::internal::ipc_protocol::SessionId> next_session_id_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

/* ---- Event 'vehicle_position' ------------------------------------------- */
/*!
 * \brief IPC Skeleton event manager for event 'vehicle_position'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class driving_informationSkeletonIpcEventManagervehicle_position final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related IPC skeleton binding to be used
   */
  explicit driving_informationSkeletonIpcEventManagervehicle_position(
      driving_informationProvidedIpcServiceInstance& skeleton_binding);

  /*!
   * \brief Send a event sample of skeleton event 'vehicle_position'.
   *
   * \trace SPEC-4981292
   * \param data Event sample of type locationtype
   */
  void Send(const apns::locationtype& data);

  /*!
   * \brief Called on a reception of a new subscription request.
   * \details In case of normal events, nothing is done. In case of field events, initial field notification is sent.
   * \return Initial field event notification message in case of field notification, or empty optional in case of normal events.
   */
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> HandleEventSubscription();

  /*!
   * \brief IPC event identifier for this event.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{2U};

 private:
  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
   amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /** Skeleton binding for event transmission */
  driving_informationProvidedIpcServiceInstance& skeleton_binding_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::ipc_binding::internal::ipc_protocol::SessionId> next_session_id_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_EVENT_MANAGER_H_

