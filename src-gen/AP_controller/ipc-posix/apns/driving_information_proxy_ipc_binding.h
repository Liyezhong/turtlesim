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
/**        \file  AP_controller/ipc-posix/apns/driving_information_proxy_ipc_binding.h
 *        \brief  Frame for IPC binding service instance class of service 'driving_information'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_BINDING_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "apns/driving_information_proxy.h"
#include "apns/driving_information_proxy_ipc_event_manager.h"
#include "apns/driving_information_proxy_ipc_methods.h"
#include "ipc_binding/internal/aracom_ipc_binding_deployment.h"
#include "ipc_binding/internal/aracom_ipc_binding_required_ipc_service_instance.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"

namespace apns {

/*!
 * \brief Parameterization of the IPC deployment information for service interface 'driving_informationProxy'.
 */
using driving_informationRequiredIpcDeployment = amsr::ipc_binding::internal::
    IpcServiceInterfaceDeploymentElement</* Abstract service interface reference */
                                         proxy:: driving_informationProxy,
                                         /* Service ID */
                                         amsr::ipc_binding::internal::ipc_protocol::ServiceId(0U),
                                         /* Major and minor version of the service used. */
                                         amsr::ipc_binding::internal::IpcServiceInterfaceVersionTemplate<1U, 0U>>;

/*!
 * \brief Type alias for the client manager.
 */
using ClientManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ClientManagerType;

/*!
 * \brief Required service interface deployment of service interface 'driving_information'.
 */
class driving_informationRequiredIpcServiceInstance final
    : public amsr::ipc_binding::internal::RequiredIpcServiceInstance<driving_informationRequiredIpcDeployment,
                                                                     ClientManager,
                                                                     apns::internal::driving_informationProxyImplInterface> {
 public:
  /*!
   * \brief Type-alias for the Base class.
   */
  using Base = amsr::ipc_binding::internal::RequiredIpcServiceInstance<driving_informationRequiredIpcDeployment,
                                                                       ClientManager,
                                                                       apns::internal::driving_informationProxyImplInterface>;

  /*!
   * \brief Constructor of RequiredIpcServiceInstance for service 'driving_information'.
   * \param client_binding_manager Client binding manager.
   * \param service_instance_id The service instance id.
   */
   driving_informationRequiredIpcServiceInstance(
      ClientManager& client_binding_manager,
      const amsr::ipc_binding::internal::ipc_protocol::InstanceId service_instance_id)
      : Base{client_binding_manager, service_instance_id}
, event_vehicle_speed_{*this} , event_vehicle_position_{*this} 
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

  /*!
   * \brief Get the event manager object for event 'vehicle_speed'
   */
  driving_informationProxyIpcEventManagervehicle_speed* GetEventManagervehicle_speed() override {
    return &event_vehicle_speed_;
  }

  /*!
   * \brief Get the event manager object for event 'vehicle_position'
   */
  driving_informationProxyIpcEventManagervehicle_position* GetEventManagervehicle_position() override {
    return &event_vehicle_position_;
  }

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- /Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
  /* ---- /Fields --------------------------------------------------------------------------------------------------- */

 private:
  /* ---- Methods ------------------------------------------------------------------------------------------ */
  /* ---- /Methods ------------------------------------------------------------------------------------------ */

  /* ---- EventManagers -------------------------------------------------------------------------------------------- */

  /*!
   * \brief Event manager for proxy event 'vehicle_speed'
   */
  driving_informationProxyIpcEventManagervehicle_speed event_vehicle_speed_;

  /*!
   * \brief Event manager for proxy event 'vehicle_position'
   */
  driving_informationProxyIpcEventManagervehicle_position event_vehicle_position_;
  /* ---- /EventManagers -------------------------------------------------------------------------------------------- */

  /* ---- Fields ------------------------------------------------------------------------------------------ */
  /* ---- /Fields ------------------------------------------------------------------------------------------ */
};

}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_PROXY_IPC_BINDING_H_

