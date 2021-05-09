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
/**        \file  AP_actuator/someip-posix/apns/speed_control_proxy_someip_binding.cpp
 *        \brief  SOME/IP proxy binding of service 'speed_control'
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_someip
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_proxy_someip_binding.h"
#include <utility>
#include "apns/speed_control_proxy.h"

namespace apns {
namespace someip_binding {
namespace internal {

constexpr amsr::someip_protocol::internal::ServiceId speed_controlProxySomeIpBinding::kServiceId;
constexpr amsr::someip_protocol::internal::MajorVersion speed_controlProxySomeIpBinding::kMajorVersion;

speed_controlProxySomeIpBinding::speed_controlProxySomeIpBinding(
    const amsr::someip_protocol::internal::InstanceId instance_id,
    amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& someip_binding_client_manager,
    resources::speed_controlProxyResourceManager& resource_manager)
    : instance_id_(instance_id),
      client_id_(someip_binding_client_manager.GetNextClientId()),
      someip_binding_client_manager_(someip_binding_client_manager),
      resource_manager_(resource_manager),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "speed_controlProxySomeIpBinding"),
      event_manager_LKA_speed_(*this),
      event_manager_ToGoal_speed_(*this){}

void speed_controlProxySomeIpBinding::Initialize() {
  // Register this proxy binding for method responses and event notifications.
  someip_binding_client_manager_.RegisterProxyBinding(
      std::make_tuple(speed_controlProxySomeIpBinding::kServiceId, instance_id_, client_id_),
      shared_from_this());
}

void speed_controlProxySomeIpBinding::DeInitialize() {
  someip_binding_client_manager_.DeRegisterProxyBinding(
      std::make_tuple(speed_controlProxySomeIpBinding::kServiceId, instance_id_, client_id_));
}

bool speed_controlProxySomeIpBinding::SendMethodRequest(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  return someip_binding_client_manager_.SendMethodRequest(instance_id_, std::move(packet));
}

void speed_controlProxySomeIpBinding::SubscribeEvent(
    const amsr::someip_protocol::internal::EventId event_id, amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager) {
  std::pair<EventSubscriptionsMap::iterator, bool> insert_pair{event_subscriptions_.end(), false};
  {
    // Protect concurrent modification of event_subscriptions_
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Subscribe to event
    insert_pair = event_subscriptions_.emplace(event_id, event_manager);
  }

  if (insert_pair.second) {
    someip_binding_client_manager_.SubscribeEvent(speed_controlProxySomeIpBinding::kServiceId, instance_id_, event_id);
  } else {
    logger_.LogWarn([&event_id](ara::log::LogStream& s) {
                    s << "Event with ID " << event_id << " already subscribed! Subscription is dropped."; },
                    __func__, __LINE__);
  }
}

void speed_controlProxySomeIpBinding::UnsubscribeEvent(const amsr::someip_protocol::internal::EventId event_id) {
  amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager{nullptr};
  {
    // Protect concurrent modification of event_subscriptions_
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event by ID
    EventSubscriptionsMap::const_iterator it{event_subscriptions_.find(event_id)};

    if (it != event_subscriptions_.end()) {
      // Store related event handler for later notification of subscription state update
      event_manager = it->second;

      // Delete route and unsubscribe from event
      event_subscriptions_.erase(it);
    }
  }

  /* Notify the related event manager about subscription state update.
   * Done outside of event_subscriptions_lock_ due to possible dead-locks in case the event
   * subscription state update handler directly calls SubscribeEvent API. A possible unexpected
   * event notification in case of a Subscribe call between lock_guard and handler call is accepted. */
  if (event_manager != nullptr) {
    someip_binding_client_manager_.UnsubscribeEvent(speed_controlProxySomeIpBinding::kServiceId, instance_id_, event_id);
    event_manager->HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState::kNotSubscribed);
  } else {
    logger_.LogWarn([&event_id](ara::log::LogStream& s) {
                    s << "No subscription active for event with SOME/IP event ID " << event_id << " active. Unsubscription is dropped."; },
                    __func__, __LINE__);
  }
}

void speed_controlProxySomeIpBinding::HandleMethodResponse(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&&) {
  // Get method ID from header
  const amsr::someip_protocol::internal::MethodId method_id{header.method_id_};

  // Based on the method id -> static dispatching to the method request/response manager
  switch (method_id) {
    default: {
      logger_.LogError([&method_id](ara::log::LogStream& s) {
                        s << "Method response handling implementation for SOME/IP method ID " << method_id
                        << " is missing. Please re-configure."; },
                        __func__, __LINE__);
      break;
    }
  }
}

void speed_controlProxySomeIpBinding::HandleEventNotification(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) {
  // We need at least two things to assign the response to its request:
  // The method / event ID and the session ID.
  const amsr::someip_protocol::internal::MethodId event_id{header.method_id_};

  amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager{nullptr};
  {
    // Protect concurrent modification of event_subscriptions_ container.
    // Required in case of concurrent reception of new event notifications by reactor and Subscribe/Unsubscribe by Application
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event subscription and call event notification handler
    EventSubscriptionsMap::const_iterator it{event_subscriptions_.find(event_id)};
    if (it != event_subscriptions_.end()) {
      event_manager = it->second;
    }
  }

  /* Call event notification handler. Explicitly done outside of event_subscriptions_lock_ to avoid
   * potential dead-locks in case application handler calls other event subscribe/unsubscribe APIs.
   * A possible unexpected event notification in case of Unsubscribe call between lock_guard and handler
   * call is accepted. */
  if (event_manager != nullptr) {
    event_manager->HandleEventNotification(std::move(deserializer));
  }
}

void speed_controlProxySomeIpBinding::HandleEventSubscriptionStateUpdate(
    const amsr::someip_protocol::internal::MethodId event_id, const ::ara::com::SubscriptionState state) {

  amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager{nullptr};
  {
    // Protect concurrent modification of event_subscriptions_ container.
    // Required in case of concurrent subscription state update by reactor and Subscribe/Unsubscribe by Application
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event subscription and call subscription state update handler
    EventSubscriptionsMap::const_iterator it{event_subscriptions_.find(event_id)};
    if (it != event_subscriptions_.end()) {
      event_manager = it->second;
    }
  }

  /* Call event subscription state change handler. Explicitly done outside of event_subscriptions_lock_ to avoid
   * potential dead-locks in case application handler calls other event subscribe/unsubscribe APIs. A possible
   * unexpected state change update in case of Unsubscribe call between lock_guard and handler call is accepted. */
  if (event_manager != nullptr) {
    event_manager->HandleEventSubscriptionStateUpdate(state);
  }
}

void speed_controlProxySomeIpBinding::HandleMethodResponseBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {

  // Get method ID from header
  const amsr::someip_protocol::internal::MethodId method_id{header.method_id_};

  // Based on the method id -> static dispatching to the method request/response manager
  switch (method_id) {
    default: {
      logger_.LogError([&method_id](ara::log::LogStream& s) {
        s << "Method response handling implementation for SOME/IP method ID " << method_id
        << " is missing. Please re-configure."; }, __func__, __LINE__);
      break;
    }
  }
}

void speed_controlProxySomeIpBinding::HandleEventNotificationBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {
  // We need at least two things to assign the response to its request:
  // The method / event ID and the session ID.
  const amsr::someip_protocol::internal::MethodId event_id{header.method_id_};

  amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager{nullptr};
  {
    // Protect concurrent modification of event_subscriptions_ container.
    // Required in case of concurrent reception of new event notifications by reactor and Subscribe/Unsubscribe by Application
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event subscription and call event notification handler
    EventSubscriptionsMap::const_iterator it{event_subscriptions_.find(event_id)};
    if (it != event_subscriptions_.end()) {
      event_manager = it->second;
    }
  }

  /* Call event notification handler. Explicitly done outside of event_subscriptions_lock_ to avoid
   * potential dead-locks in case application handler calls other event subscribe/unsubscribe APIs.
   * A possible unexpected event notification in case of Unsubscribe call between lock_guard and handler
   * call is accepted. */
  if (event_manager != nullptr) {
    event_manager->HandleBufferOverflow(header);
  }
}
}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

