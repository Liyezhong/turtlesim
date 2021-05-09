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
/**        \file  AP_controller/ipc-posix/apns/external_elements_skeleton_ipc_event_manager.h
 *        \brief  IPC skeleton event handling for events and field notifications of service 'external_elements'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_EVENT_MANAGER_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include "apns/external_elements.h"
#include "apns/external_elements_skeleton.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"
#include "ipc_binding/internal/ipc_protocol/message.h"
#include "socal/internal/session_handler.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {

// Forward-declaration for back-reference
class external_elementsProvidedIpcServiceInstance;

/* ---- Field notifier 'lane' ------------------------------------------- */
/*!
 * \brief IPC Skeleton event manager for event 'lane'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldNotifierlane final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related IPC skeleton binding to be used
   */
  explicit external_elementsSkeletonIpcFieldNotifierlane(
      external_elementsProvidedIpcServiceInstance& skeleton_binding);

  /*!
   * \brief Send a event sample of skeleton event 'lane'.
   *
   * \trace SPEC-4981292
   * \param data Event sample of type lanetype
   */
  void Send(const apns::lanetype& data);

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
  external_elementsProvidedIpcServiceInstance& skeleton_binding_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::ipc_binding::internal::ipc_protocol::SessionId> next_session_id_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

/* ---- Field notifier 'object' ------------------------------------------- */
/*!
 * \brief IPC Skeleton event manager for event 'object'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldNotifierobject final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related IPC skeleton binding to be used
   */
  explicit external_elementsSkeletonIpcFieldNotifierobject(
      external_elementsProvidedIpcServiceInstance& skeleton_binding);

  /*!
   * \brief Send a event sample of skeleton event 'object'.
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
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{5U};

 private:
  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
   amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /** Skeleton binding for event transmission */
  external_elementsProvidedIpcServiceInstance& skeleton_binding_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::ipc_binding::internal::ipc_protocol::SessionId> next_session_id_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_EVENT_MANAGER_H_

