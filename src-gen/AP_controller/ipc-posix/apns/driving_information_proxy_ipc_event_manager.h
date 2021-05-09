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
/**        \file  AP_controller/ipc-posix/apns/driving_information_proxy_ipc_event_manager.h
 *        \brief  IPC proxy event handling for events and field notifications of service 'driving_information'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_EVENT_MANAGER_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <mutex>
#include "apns/driving_information_common.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "ipc_binding/internal/ipc_protocol/message.h"
#include "ipc_binding/internal/service_proxy_ipc_event_interface.h"
#include "socal/internal/proxy_event.h"
#include "socal/internal/proxy_impl_event.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {

// Forward-declaration for back-reference
class driving_informationRequiredIpcServiceInstance;


/*!
 * \brief IPC Proxy event manager for event 'vehicle_speed'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class driving_informationProxyIpcEventManagervehicle_speed final : public amsr::ipc_binding::internal::ServiceProxyIpcEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<apns::speedtype> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the IPC proxy binding used for event subscription handling.
   */
  explicit driving_informationProxyIpcEventManagervehicle_speed(driving_informationRequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Subscribe to the event 'vehicle_speed'
   *
   * \trace SPEC-5951482 (Call SubscriptionStateChangeHandler with kSubscriptionPending)
   *
   * \param service_event Related frontend event object. Used for notification handling
   * \param cache_policy Update policy of the event cache
   * \param cache_size Size limit of the event cache
   * \return true if subscription is successful, otherwise false.
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  bool Subscribe(::amsr::socal::internal::ProxyEventBase* service_event, ::ara::com::EventCacheUpdatePolicy cache_policy,
                 std::size_t cache_size);

  /*!
   * \brief Unsubscribe from the event 'vehicle_speed'
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  void Unsubscribe();

  /*!
   * \brief Handle a received event notification
   *
   * \param notification_msg Notification message structure
   *
   * \trace SPEC-5951439 (Call SubscriptionStateChangeHandler with kSubscribed)
   * \trace SPEC-4980149
   */
  void HandleEventNotification(amsr::ipc_binding::internal::ipc_protocol::NotificationMessage& notification_msg) override;

  /*!
   * \brief Handle an update of the subscription state of the event.
   * \param state the updated event subscription state.
   */
  void HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state);

  /*!
   * \brief IPC event identifier for this event.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{1U};

 private:
  /** Proxy binding used for event subscription handling */
  driving_informationRequiredIpcServiceInstance& proxy_binding_;

  /** The related frontend service event used to notify about new events. */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};


/*!
 * \brief IPC Proxy event manager for event 'vehicle_position'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class driving_informationProxyIpcEventManagervehicle_position final : public amsr::ipc_binding::internal::ServiceProxyIpcEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<apns::locationtype> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the IPC proxy binding used for event subscription handling.
   */
  explicit driving_informationProxyIpcEventManagervehicle_position(driving_informationRequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Subscribe to the event 'vehicle_position'
   *
   * \trace SPEC-5951482 (Call SubscriptionStateChangeHandler with kSubscriptionPending)
   *
   * \param service_event Related frontend event object. Used for notification handling
   * \param cache_policy Update policy of the event cache
   * \param cache_size Size limit of the event cache
   * \return true if subscription is successful, otherwise false.
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  bool Subscribe(::amsr::socal::internal::ProxyEventBase* service_event, ::ara::com::EventCacheUpdatePolicy cache_policy,
                 std::size_t cache_size);

  /*!
   * \brief Unsubscribe from the event 'vehicle_position'
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  void Unsubscribe();

  /*!
   * \brief Handle a received event notification
   *
   * \param notification_msg Notification message structure
   *
   * \trace SPEC-5951439 (Call SubscriptionStateChangeHandler with kSubscribed)
   * \trace SPEC-4980149
   */
  void HandleEventNotification(amsr::ipc_binding::internal::ipc_protocol::NotificationMessage& notification_msg) override;

  /*!
   * \brief Handle an update of the subscription state of the event.
   * \param state the updated event subscription state.
   */
  void HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state);

  /*!
   * \brief IPC event identifier for this event.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{2U};

 private:
  /** Proxy binding used for event subscription handling */
  driving_informationRequiredIpcServiceInstance& proxy_binding_;

  /** The related frontend service event used to notify about new events. */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
};


}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_EVENT_MANAGER_H_

