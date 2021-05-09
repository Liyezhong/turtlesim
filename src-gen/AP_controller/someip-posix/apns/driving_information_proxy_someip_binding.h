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
/**        \file  AP_controller/someip-posix/apns/driving_information_proxy_someip_binding.h
 *        \brief  SOME/IP binding of service proxy for service 'driving_information'
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

#ifndef AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_PROXY_SOMEIP_BINDING_H_
#define AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_PROXY_SOMEIP_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <memory>
#include <tuple>
#include "apns/driving_information_proxy.h"
#include "apns/driving_information_proxy_internal.h"
#include "apns/driving_information_proxy_resource_manager.h"
#include "apns/driving_information_proxy_someip_event_manager.h"
#include "apns/driving_information_proxy_someip_methods.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "someip_binding/internal/aracom_someip_binding_client_manager_interface.h"
#include "someip_binding/internal/aracom_someip_proxy_interface.h"
#include "someip_binding/internal/service_proxy_someip_event_interface.h"

namespace apns {
namespace someip_binding {
namespace internal {


/*!
 * \brief SOME/IP proxy binding of Service 'driving_information'.
 * \details Handles serialization and deserialization of all method calls, events, etc.
 * \remark generated
 */
class driving_informationProxySomeIpBinding final : public apns::internal::driving_informationProxyImplInterface,
                                                            public amsr::someip_binding::internal::AraComSomeIpProxyInterface,
                                                            public std::enable_shared_from_this<driving_informationProxySomeIpBinding> {
 public:
  /*!
   * \brief Generated SOME/IP related service ID.
   */
  static constexpr amsr::someip_protocol::internal::ServiceId kServiceId{0x57AU};

  /*!
   * \brief SOME/IP major version of this service interface deployment.
   */
  static constexpr amsr::someip_protocol::internal::MajorVersion kMajorVersion{1U};

  /*!
   * \brief Constructor
   * \param instance_id SOME/IP instance identifier to be used
   * \param someip_binding_client_manager Reference to the related SOME/IP transport binding manager
   * \param resource_manager Reference to service proxy specific resource manager
   */
  driving_informationProxySomeIpBinding(const amsr::someip_protocol::internal::InstanceId instance_id,
                                                      amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& someip_binding_client_manager,
                                                      resources::driving_informationProxyResourceManager& resource_manager);

  /*!
   * \brief Destructor.
   */
  virtual ~driving_informationProxySomeIpBinding() = default;

  /*!
   * \brief Requests the proxy-binding instance in the AraComSomeIpBinding.
   */
  void Initialize() override;

  /*!
   * \brief Releases the proxy-binding instance in the AraComSomeIpBinding.
   */
  void DeInitialize() override;

  /*!
   * \brief Get the ProxyId this ProxyImplInterface can handle.
   * \returns The ProxyId this ProxyImplInterface can handle.
   */
  ::amsr::socal::internal::ProxyId GetProxyId() const override { return proxy::driving_informationProxy::GetProxyIdStatic(); }

  /*!
   * \brief Receive handler for method responses.
   * \details At the point of this method call from AraComSomeIpBinding, we only have to dispatch method id and session
   * id and look in the correct pending request container, to serve the promise.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   *
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if SOME/IP return code was kUnknownService
   *
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   */
  void HandleMethodResponse(const amsr::someip_protocol::internal::SomeIpMessageHeader& header,
                            amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Receive handler for event notifications.
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   *
   * \trace SPEC-4980079
   */
  void HandleEventNotification(const amsr::someip_protocol::internal::SomeIpMessageHeader& header,
                               amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Handle an update of the subscription state of the event
   * \param event_id The event identifier
   * \param state The updated event subscription state
   */
  void HandleEventSubscriptionStateUpdate(const amsr::someip_protocol::internal::EventId event_id, const ::ara::com::SubscriptionState state) override;

  /*!
   * \brief Receive buffer overflow handler for method responses.
   *
   * \param header SOME/IP header.
   */
  void HandleMethodResponseBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Receive buffer overflow handler for event notifications.
   *
   * \param header SOME/IP header.
   */
  void HandleEventNotificationBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Forward a prepared packet to the AraComSomeIpBinding.
   *
   * \param packet the serialized packet from the method.
   *
   * \return true if the transmission has been started and false otherwise.
   */
  bool SendMethodRequest(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /*!
   * \brief Subscribe to an event
   * \param event_id The SOME/IP event ID to subscribe to
   * \param event_manager The related event manager instance subscribing to the event
   *
   * \throws ::ara::com::InternalComException If SOME/IP daemon is not running (errc: backend_not_available).
   */
  void SubscribeEvent(const amsr::someip_protocol::internal::EventId event_id,
                      amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager);

  /*!
   * \brief Unsubscribe from an event
   * \param event_id The SOME/IP event ID to unsubscribe from
   *
   * \throws ::ara::com::InternalComException If SOME/IP daemon is not running (errc: backend_not_available).
   */
  void UnsubscribeEvent(const amsr::someip_protocol::internal::EventId event_id);

  /*!
   * \brief Getter for accessing the SOME/IP binding.
   */
  amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& GetBinding() { return someip_binding_client_manager_; }

  /*!
   * \brief Getter for the client id, that was assigned on construction of this object.
   */
  amsr::someip_protocol::internal::ClientId GetClientId() const { return client_id_; }

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Get the event manager object for event 'vehicle_speed'
   */
  driving_informationProxySomeIpEventManagervehicle_speed* GetEventManagervehicle_speed() override {
    return &event_manager_vehicle_speed_;
  }

  /*!
   * \brief Get the event manager object for event 'vehicle_position'
   */
  driving_informationProxySomeIpEventManagervehicle_position* GetEventManagervehicle_position() override {
    return &event_manager_vehicle_position_;
  }

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
 private:
  /** Subscribed events with the related event manager */
  using EventSubscriptionsMap =
      std::map<amsr::someip_protocol::internal::EventId, amsr::someip_binding::internal::ServiceProxySomeIpEventInterface*>;

  /** SOME/IP instance ID used by this binding. */
  amsr::someip_protocol::internal::InstanceId instance_id_;

  /** SOME/IP related client ID used by this concrete proxy instance. */
  amsr::someip_protocol::internal::ClientId client_id_;

  /** Related SOME/IP binding */
  amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& someip_binding_client_manager_;

  /** Related service proxy specific resource manager */
  resources::driving_informationProxyResourceManager& resource_manager_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;

  /** Event subscriptions */
  EventSubscriptionsMap event_subscriptions_;

  /** Mutex for protection of event_subscriptions_ */
  std::mutex event_subscriptions_lock_;

  /* ---- Methods ------------------------------------------------------------------------------------------ */

  /* ---- Event manager -------------------------------------------------------------------------------------------- */

  /** Event  manager for proxy event 'vehicle_speed' */
  driving_informationProxySomeIpEventManagervehicle_speed event_manager_vehicle_speed_;

  /** Event  manager for proxy event 'vehicle_position' */
  driving_informationProxySomeIpEventManagervehicle_position event_manager_vehicle_position_;

  /* ---- Field method/event manager ------------------------------------------------------------------------------- */
};

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_PROXY_SOMEIP_BINDING_H_

