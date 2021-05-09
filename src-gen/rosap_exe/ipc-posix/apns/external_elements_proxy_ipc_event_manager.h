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
/**        \file  rosap_exe/ipc-posix/apns/external_elements_proxy_ipc_event_manager.h
 *        \brief  IPC proxy event handling for events and field notifications of service 'external_elements'
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_EVENT_MANAGER_H_
#define ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <mutex>
#include "apns/external_elements_common.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "ipc_binding/internal/ipc_protocol/message.h"
#include "ipc_binding/internal/service_proxy_ipc_event_interface.h"
#include "socal/internal/proxy_event.h"
#include "socal/internal/proxy_impl_event.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {

// Forward-declaration for back-reference
class external_elementsRequiredIpcServiceInstance;


/*!
 * \brief IPC Proxy event manager for event 'lane'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class external_elementsProxyIpcFieldNotifierlane final : public amsr::ipc_binding::internal::ServiceProxyIpcEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<apns::lanetype> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the IPC proxy binding used for event subscription handling.
   */
  explicit external_elementsProxyIpcFieldNotifierlane(external_elementsRequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Subscribe to the event 'lane'
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
   * \brief Unsubscribe from the event 'lane'
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
  external_elementsRequiredIpcServiceInstance& proxy_binding_;

  /** The related frontend service event used to notify about new events. */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
  /** For field notifiers there is a flag necessary to filter out the initial field value once received. */
  std::atomic<bool> initial_value_received_{false};
};


/*!
 * \brief IPC Proxy event manager for event 'object'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class external_elementsProxyIpcFieldNotifierobject final : public amsr::ipc_binding::internal::ServiceProxyIpcEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<apns::locationtype> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the IPC proxy binding used for event subscription handling.
   */
  explicit external_elementsProxyIpcFieldNotifierobject(external_elementsRequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Subscribe to the event 'object'
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
   * \brief Unsubscribe from the event 'object'
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
  static constexpr amsr::ipc_binding::internal::ipc_protocol::EventId kEventId{5U};

 private:
  /** Proxy binding used for event subscription handling */
  external_elementsRequiredIpcServiceInstance& proxy_binding_;

  /** The related frontend service event used to notify about new events. */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;
  /** For field notifiers there is a flag necessary to filter out the initial field value once received. */
  std::atomic<bool> initial_value_received_{false};
};


}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_EVENT_MANAGER_H_

