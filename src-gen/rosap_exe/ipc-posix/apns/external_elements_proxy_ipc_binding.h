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
/**        \file  rosap_exe/ipc-posix/apns/external_elements_proxy_ipc_binding.h
 *        \brief  Frame for IPC binding service instance class of service 'external_elements'
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_BINDING_H_
#define ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "apns/external_elements_proxy.h"
#include "apns/external_elements_proxy_ipc_event_manager.h"
#include "apns/external_elements_proxy_ipc_methods.h"
#include "ipc_binding/internal/aracom_ipc_binding_deployment.h"
#include "ipc_binding/internal/aracom_ipc_binding_required_ipc_service_instance.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"

namespace apns {

/*!
 * \brief Parameterization of the IPC deployment information for service interface 'external_elementsProxy'.
 */
using external_elementsRequiredIpcDeployment = amsr::ipc_binding::internal::
    IpcServiceInterfaceDeploymentElement</* Abstract service interface reference */
                                         proxy:: external_elementsProxy,
                                         /* Service ID */
                                         amsr::ipc_binding::internal::ipc_protocol::ServiceId(1U),
                                         /* Major and minor version of the service used. */
                                         amsr::ipc_binding::internal::IpcServiceInterfaceVersionTemplate<1U, 0U>>;

/*!
 * \brief Type alias for the client manager.
 */
using ClientManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ClientManagerType;

/*!
 * \brief Required service interface deployment of service interface 'external_elements'.
 */
class external_elementsRequiredIpcServiceInstance final
    : public amsr::ipc_binding::internal::RequiredIpcServiceInstance<external_elementsRequiredIpcDeployment,
                                                                     ClientManager,
                                                                     apns::internal::external_elementsProxyImplInterface> {
 public:
  /*!
   * \brief Type-alias for the Base class.
   */
  using Base = amsr::ipc_binding::internal::RequiredIpcServiceInstance<external_elementsRequiredIpcDeployment,
                                                                       ClientManager,
                                                                       apns::internal::external_elementsProxyImplInterface>;

  /*!
   * \brief Constructor of RequiredIpcServiceInstance for service 'external_elements'.
   * \param client_binding_manager Client binding manager.
   * \param service_instance_id The service instance id.
   */
   external_elementsRequiredIpcServiceInstance(
      ClientManager& client_binding_manager,
      const amsr::ipc_binding::internal::ipc_protocol::InstanceId service_instance_id)
      : Base{client_binding_manager, service_instance_id}

  ,
      field_lane_get_{*this}
  ,
      field_lane_set_{*this}
  ,
      field_notifier_lane_{*this}
  ,
      field_object_get_{*this}
  ,
      field_object_set_{*this}
  ,
      field_notifier_object_{*this}
 {}

  /*!
   * \brief The reception path is realized for a concrete service interface deployment.
   * \remark Reception path: PacketRouter -> RequiredServiceInstance -> MethodManager
   * \param response Response message to be forwarded.
   * \return Whether this response could be forwarded or not.
   */
  amsr::ipc_binding::internal::ForwardOutput OnResponseReceived(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) override;

  /*!
   * \brief The reception path is realized for a concrete service interface deployment.
   * \remark Reception path: PacketRouter -> RequiredServiceInstance -> EventManager
   * \param notification Notification message to be forwarded.
   * \return True if this notification could be forwarded, false otherwise.
   */
  amsr::ipc_binding::internal::ForwardOutput OnNotificationReceived(amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr notification) override;

  /*!
   * \brief The reception path is realized for a concrete service interface deployment.
   * \remark Reception path: PacketRouter -> RequiredServiceInstance -> MethodManager
   * \param message Application error message to be forwarded.
   * \return Whether this application error could be forwarded or not.
   */
  amsr::ipc_binding::internal::ForwardOutput OnApplicationErrorReceived(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response) override;

  /*!
  * \brief The reception path is realized for a concrete service interface deployment.
  * \remark Reception path: PacketRouter -> RequiredServiceInstance -> MethodManager
  * \param message Request error message to be forwarded.
  * \return Whether this response could be forwarded or not.
  */
  void OnErrorResponseReceived(amsr::ipc_binding::internal::ipc_protocol::ErrorResponseMessage&& response) override;

  /*!
   * \brief Forward function to forward a subscription ACK from the the skeleton to the proxy.
   *
   * \trace SPEC-5951439 (Call SubscriptionStateChangeHandler with kSubscribed)
   *
   * \param ack_response The ACK response forwarded to this required service instance sink.
   *
   * \return true if the concrete LocalClientSink accepts the subscribe ACK, false if the client id in message header is different then of this instance.
   */
  amsr::ipc_binding::internal::ForwardOutput OnSubscribeAckReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventAckMessageHeader const& ack_response) override;

  /*!
   * \brief Forward function to forward an unsubscription message to a provided service instance.
   *
   * \trace SPEC-5951482 (Call SubscriptionStateChangeHandler with kSubscriptionPending)
   *
   * \param nack_response The NACK response forwarded to this required service instance sink.
   *
   * \return true if the concrete LocalClientSink accepts the subscribe NACK, false if the client id in message header is different then of this instance.
   */
  amsr::ipc_binding::internal::ForwardOutput OnSubscribeNAckReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventNAckMessageHeader const& nack_response) override;

  /*!
   * \brief Notify subscription state update when the provided service goes down.
   *
   * \trace SPEC-5951482 (Call SubscriptionStateChangeHandler with kSubscriptionPending)
   */
  void OnServiceInstanceDown() override;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- /Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Realized getter for the field 'lane' on IPC level.
   * \return a future object
   */
  ara::core::Future<proxy::fields::lane::FieldType> FieldlaneMethodGet() override {
    return field_lane_get_.HandleMethodRequest();
  }

  /*!
   * \brief Realized setter for the field 'lane' on IPC level.
   * \param value Field value of type lanetype
   * \return a future object that contains the value after the promise is served.
   */
  ara::core::Future<proxy::fields::lane::FieldType> FieldlaneMethodSet(const apns::lanetype& value) override {
    return field_lane_set_.HandleMethodRequest(value);
  }

  /*!
   * \brief Get the field notifier object for field 'lane'.
   */
  external_elementsProxyIpcFieldNotifierlane* GetFieldNotifierlane() override { return &field_notifier_lane_; }
  /*!
   * \brief Realized getter for the field 'object' on IPC level.
   * \return a future object
   */
  ara::core::Future<proxy::fields::object::FieldType> FieldobjectMethodGet() override {
    return field_object_get_.HandleMethodRequest();
  }

  /*!
   * \brief Realized setter for the field 'object' on IPC level.
   * \param value Field value of type locationtype
   * \return a future object that contains the value after the promise is served.
   */
  ara::core::Future<proxy::fields::object::FieldType> FieldobjectMethodSet(const apns::locationtype& value) override {
    return field_object_set_.HandleMethodRequest(value);
  }

  /*!
   * \brief Get the field notifier object for field 'object'.
   */
  external_elementsProxyIpcFieldNotifierobject* GetFieldNotifierobject() override { return &field_notifier_object_; }
  /* ---- /Fields --------------------------------------------------------------------------------------------------- */

 private:
  /* ---- Methods ------------------------------------------------------------------------------------------ */
  /* ---- /Methods ------------------------------------------------------------------------------------------ */

  /* ---- EventManagers -------------------------------------------------------------------------------------------- */
  /* ---- /EventManagers -------------------------------------------------------------------------------------------- */

  /* ---- Fields ------------------------------------------------------------------------------------------ */

  /* ---- Field 'lane' ---- */

  /*!
   * \brief Field method manager for method Get of proxy field 'lane'.
   */
   ipc_binding::internal::fields::ProxylaneGet field_lane_get_;

  /*!
   * \brief Field method manager for method Set of proxy field 'lane'.
   */
  ipc_binding::internal::fields::ProxylaneSet field_lane_set_;
  /*!
   * \brief Field notifier for the the proxy field 'lane'
   */
  external_elementsProxyIpcFieldNotifierlane field_notifier_lane_;

  /* ---- Field 'object' ---- */

  /*!
   * \brief Field method manager for method Get of proxy field 'object'.
   */
   ipc_binding::internal::fields::ProxyobjectGet field_object_get_;

  /*!
   * \brief Field method manager for method Set of proxy field 'object'.
   */
  ipc_binding::internal::fields::ProxyobjectSet field_object_set_;
  /*!
   * \brief Field notifier for the the proxy field 'object'
   */
  external_elementsProxyIpcFieldNotifierobject field_notifier_object_;
  /* ---- /Fields ------------------------------------------------------------------------------------------ */
};

}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_BINDING_H_

