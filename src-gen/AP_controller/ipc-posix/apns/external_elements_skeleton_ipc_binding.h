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
/**        \file  AP_controller/ipc-posix/apns/external_elements_skeleton_ipc_binding.h
 *        \brief  IPC binding of service skeleton for service 'external_elements'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_BINDING_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "apns/external_elements_skeleton.h"
#include "apns/external_elements_skeleton_ipc_event_manager.h"
#include "apns/external_elements_skeleton_ipc_method_manager.h"
#include "ipc_binding/internal/aracom_ipc_binding_deployment.h"
#include "ipc_binding/internal/aracom_ipc_binding_provided_ipc_service_instance.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"
#include "ipc_binding/internal/ipc_protocol/message.h"

namespace apns {

/*!
 * \brief Parameterization of the IPC deployment information for service interface 'external_elementsSkeleton'.
 * \remark generated
 */
using external_elementsProvidedIpcDeployment = amsr::ipc_binding::internal::
    IpcServiceInterfaceDeploymentElement</* Abstract service interface reference */
                                         skeleton::external_elementsSkeleton,
                                         amsr::ipc_binding::internal::ipc_protocol::ServiceId(1U),
                                         amsr::ipc_binding::internal::IpcServiceInterfaceVersionTemplate<1U, 0U>>;

/*!
 * \brief Type alias for the server manager.
 */
using ServerManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ServerManagerType;

/*!
 * \brief Provided service interface deployment of service interface 'external_elements'.
 */
class external_elementsProvidedIpcServiceInstance final
    : public amsr::ipc_binding::internal::ProvidedIpcServiceInstance<external_elementsProvidedIpcDeployment,
                                                                     ServerManager,
                                                                     apns::internal::external_elementsSkeletonImplInterface> {
 public:
  /*!
   * \brief Type-alias for the Base class.
   */
  using Base = amsr::ipc_binding::internal::ProvidedIpcServiceInstance<external_elementsProvidedIpcDeployment,
                                                                       ServerManager,
                                                                       apns::internal::external_elementsSkeletonImplInterface>;

  /*!
   * \brief Constructor of ProvidedIpcServiceInstance for service 'external_elements'.
   *
   * \param skeleton Reference to the skeleton.
   * \param server_binding_manager Server binding manager.
   * \param instance_id The service instance id.
   */
  external_elementsProvidedIpcServiceInstance(ServiceInterfaceRef& skeleton,
                                   ServerManager& server_binding_manager,
                                   amsr::ipc_binding::internal::ipc_protocol::InstanceId instance_id)
      : Base{skeleton, server_binding_manager, instance_id}

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
  /* ---- /Events -------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Called by the frontend skeleton on event notification for service field 'lane'.
   * \param data Current data for the field 'lane'.
   */
  void UpdateFieldlane(const apns::lanetype& data) override;
  /*!
   * \brief Called by the frontend skeleton on event notification for service field 'object'.
   * \param data Current data for the field 'object'.
   */
  void UpdateFieldobject(const apns::locationtype& data) override;
  /* ---- /Fields -------------------------------------------------------------------------------------------------- */

 private:
  /* ---- MethodManagers ------------------------------------------------------------------------------------------- */
  /* ---- /MethodManagers ------------------------------------------------------------------------------------------ */

  /* ---- EventManagers -------------------------------------------------------------------------------------------- */
  /* ---- /EventManagers ------------------------------------------------------------------------------------------- */

  /* ---- FieldManagers -------------------------------------------------------------------------------------------- */
  /* ---- Field 'lane' ---- */

  /*! Field method manager for method Get of skeleton field 'lane' */
  external_elementsSkeletonIpcFieldManagerlaneGet field_lane_get_;

  /*! Field method manager for method Set of skeleton field 'lane' */
  external_elementsSkeletonIpcFieldManagerlaneSet field_lane_set_;

  /*! Field notifier for the the skeleton field 'lane' */
  external_elementsSkeletonIpcFieldNotifierlane field_notifier_lane_;
  /* ---- Field 'object' ---- */

  /*! Field method manager for method Get of skeleton field 'object' */
  external_elementsSkeletonIpcFieldManagerobjectGet field_object_get_;

  /*! Field method manager for method Set of skeleton field 'object' */
  external_elementsSkeletonIpcFieldManagerobjectSet field_object_set_;

  /*! Field notifier for the the skeleton field 'object' */
  external_elementsSkeletonIpcFieldNotifierobject field_notifier_object_;
  /* ---- /FieldManagers ------------------------------------------------------------------------------------------- */
};

}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_BINDING_H_

