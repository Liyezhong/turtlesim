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
/**        \file  rosap_exe/ipc-posix/apns/driving_information_skeleton_ipc_binding.h
 *        \brief  IPC binding of service skeleton for service 'driving_information'
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_BINDING_H_
#define ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "apns/driving_information_skeleton.h"
#include "apns/driving_information_skeleton_ipc_event_manager.h"
#include "apns/driving_information_skeleton_ipc_method_manager.h"
#include "ipc_binding/internal/aracom_ipc_binding_deployment.h"
#include "ipc_binding/internal/aracom_ipc_binding_provided_ipc_service_instance.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"
#include "ipc_binding/internal/ipc_protocol/message.h"

namespace apns {

/*!
 * \brief Parameterization of the IPC deployment information for service interface 'driving_informationSkeleton'.
 * \remark generated
 */
using driving_informationProvidedIpcDeployment = amsr::ipc_binding::internal::
    IpcServiceInterfaceDeploymentElement</* Abstract service interface reference */
                                         skeleton::driving_informationSkeleton,
                                         amsr::ipc_binding::internal::ipc_protocol::ServiceId(0U),
                                         amsr::ipc_binding::internal::IpcServiceInterfaceVersionTemplate<1U, 0U>>;

/*!
 * \brief Type alias for the server manager.
 */
using ServerManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ServerManagerType;

/*!
 * \brief Provided service interface deployment of service interface 'driving_information'.
 */
class driving_informationProvidedIpcServiceInstance final
    : public amsr::ipc_binding::internal::ProvidedIpcServiceInstance<driving_informationProvidedIpcDeployment,
                                                                     ServerManager,
                                                                     apns::internal::driving_informationSkeletonImplInterface> {
 public:
  /*!
   * \brief Type-alias for the Base class.
   */
  using Base = amsr::ipc_binding::internal::ProvidedIpcServiceInstance<driving_informationProvidedIpcDeployment,
                                                                       ServerManager,
                                                                       apns::internal::driving_informationSkeletonImplInterface>;

  /*!
   * \brief Constructor of ProvidedIpcServiceInstance for service 'driving_information'.
   *
   * \param skeleton Reference to the skeleton.
   * \param server_binding_manager Server binding manager.
   * \param instance_id The service instance id.
   */
  driving_informationProvidedIpcServiceInstance(ServiceInterfaceRef& skeleton,
                                   ServerManager& server_binding_manager,
                                   amsr::ipc_binding::internal::ipc_protocol::InstanceId instance_id)
      : Base{skeleton, server_binding_manager, instance_id}
, event_vehicle_speed_{*this} , event_vehicle_position_{*this} 
 {}

  /*!
   * \brief Realization to forward a method to the method managers.
   *
   * \param request The request, which is going to be dispatched to a method manager for deserialization
   * and processing.
   *
   * \return The forward status as an extensible struct.
   */
  amsr::ipc_binding::internal::ForwardOutput OnRequestReceived(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) override;

  /*!
   * \brief Realization to forward a fire & forget method to the method managers.
   *
   * \param request The request, which is going to be dispatched to a method manager for deserialization
   * and processing.
   *
   * \return The forward status as an extensible struct.
   */
  amsr::ipc_binding::internal::ForwardOutput OnRequestNoReturnReceived(amsr::ipc_binding::internal::ipc_protocol::RequestNoReturnMessage&& request) override;

  /*!
   * \brief Realization to forward a subscribe request from the client and forward it to the designated event / field notification manager.
   *
   * \param subscribe_request The subscription message header from the client.
   *
   * \return The forward status as an extensible structure.
   */
  amsr::ipc_binding::internal::ForwardSubscribeEventOutput OnSubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventMessageHeader const& subscribe_request) override;

  /*!
   * \brief Realization to forward an unsubscribe request from the client and forward it to the designated event / field notification manager.
   *
   * \param unsubscribe_request The unsubscription message header from the client.
   *
   * \return The forward status as an extensible structure.
   */
  amsr::ipc_binding::internal::ForwardOutput OnUnsubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::UnsubscribeEventMessageHeader const& unsubscribe_request) override;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Called by frontend skeleton on event notification for service event 'vehicle_speed'.
   * \param data Event sample of type speedtype
   */
  void SendEventvehicle_speed(const apns::speedtype& data) override;

  /*!
   * \brief Called by frontend skeleton on event notification for service event 'vehicle_position'.
   * \param data Event sample of type locationtype
   */
  void SendEventvehicle_position(const apns::locationtype& data) override;
  /* ---- /Events -------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
  /* ---- /Fields -------------------------------------------------------------------------------------------------- */

 private:
  /* ---- MethodManagers ------------------------------------------------------------------------------------------- */
  /* ---- /MethodManagers ------------------------------------------------------------------------------------------ */

  /* ---- EventManagers -------------------------------------------------------------------------------------------- */
  /*!
   * \brief Event manager for skeleton event 'vehicle_speed'
   */
  driving_informationSkeletonIpcEventManagervehicle_speed event_vehicle_speed_;

  /*!
   * \brief Event manager for skeleton event 'vehicle_position'
   */
  driving_informationSkeletonIpcEventManagervehicle_position event_vehicle_position_;

  /* ---- /EventManagers ------------------------------------------------------------------------------------------- */

  /* ---- FieldManagers -------------------------------------------------------------------------------------------- */
  /* ---- /FieldManagers ------------------------------------------------------------------------------------------- */
};

}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_SKELETON_IPC_BINDING_H_

