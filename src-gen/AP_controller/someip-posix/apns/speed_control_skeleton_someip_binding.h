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
/**        \file  AP_controller/someip-posix/apns/speed_control_skeleton_someip_binding.h
 *        \brief  SOME/IP binding of service skeleton for service 'speed_control'
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

#ifndef AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_BINDING_H_
#define AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <utility>
#include "apns/speed_control_skeleton.h"
#include "apns/speed_control_skeleton_impl_interface.h"
#include "apns/speed_control_skeleton_resource_manager.h"
#include "apns/speed_control_skeleton_someip_event_manager.h"
#include "apns/speed_control_skeleton_someip_methods.h"
#include "ara/core/promise.h"
#include "someip_binding/internal/aracom_someip_binding_server_manager_interface.h"
#include "someip_binding/internal/aracom_someip_skeleton_interface.h"

namespace apns {
namespace someip_binding {
namespace internal {
/*!
 * \brief SOME/IP skeleton binding of Service 'speed_control'.
 * \details Handles serialization and deserialization of all method calls, events, etc.
 * \remark generated
 */
class speed_controlSkeletonSomeIpBinding final :
    public apns::internal::speed_controlSkeletonImplInterface,
    public amsr::someip_binding::internal::AraComSomeIpSkeletonInterface {
 public:
  /*!
   * \brief Type alias for used skeleton frontend.
   */
  using SkeletonFrontend = skeleton::speed_controlSkeleton;
  /*!
   * \brief Generated SOME/IP related service ID.
   */
  static constexpr amsr::someip_protocol::internal::ServiceId kServiceId{0x579U};

  /*!
   * \brief SOME/IP major version of this service interface deployment.
   */
  static constexpr amsr::someip_protocol::internal::MajorVersion kMajorVersion{1U};

  /*!
   * \brief Constructor
   * \param instance_id SOME/IP service instance ID offered by this skeleton.
   * \param someip_binding_server_manager Reference to the related SOME/IP transport binding manager.
   * \param resource_manager Reference to service skeleton specific resource manager.
   * \param skeleton Reference to the related frontend skeleton.
   */
  speed_controlSkeletonSomeIpBinding(amsr::someip_protocol::internal::InstanceId instance_id,
                                                        amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager,
                                                        resources::speed_controlSkeletonResourceManager& resource_manager,
                                                        skeleton::speed_controlSkeleton& skeleton);

  /*!
   * \brief Default destructor must de-register the implementation from the AraComSomeIpBinding.
   */
  ~speed_controlSkeletonSomeIpBinding();

  /*!
   * \brief Get the SkeletonId this SkeletonImplInterface can handle.
   * \returns The SkeletonId this SkeletonImplInterface can handle.
   */
  ::amsr::socal::internal::SkeletonId GetSkeletonId() const override {
    return skeleton::speed_controlSkeleton::GetSkeletonIdStatic();
  }

  /*!
   * \brief Getter for accessing the related frontend skeleton.
   */
  SkeletonFrontend& GetSkeleton() const noexcept { return skeleton_; }

  /*!
   * \brief Receive handler for method requests.
   *
   * \param header Deserialized SOME/IP header.
   * \param deserializer Root deserializer holding the packet buffer.
   */
  void HandleMethodRequest(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Forward a prepared packet to the AraComSomeIpBinding.
   * \param packet the serialized response packet.
   */
  void SendMethodResponse(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /*!
   * \brief Send a SOME/IP error response packet. Used in case of:
   *  - Infrastructural checks failed (protocol version, return code, message type)
   *  - Deserialization failed
   *  - Serialization of method responses failed
   *  - Service / Method is not implemented.
   *
   * \tparam ReturnCode The error return code as template parameter to make a compile-time check.
   * \param request_header The unmodified SOME/IP header.
   */
  template <typename amsr::someip_protocol::internal::ReturnCode ReturnCode>
  void SendErrorResponse(const amsr::someip_protocol::internal::SomeIpMessageHeader& request_header) {
    static_assert((ReturnCode >= amsr::someip_protocol::internal::SomeIpReturnCode::kNotOk) &&
                      (ReturnCode <= amsr::someip_protocol::internal::SomeIpReturnCode::kRangeServiceErrorsEnd),
                  "Return code for errors must be in the range of 0x01 .. 0x5E.");
    someip_binding_server_manager_.SendErrorResponse(ReturnCode, instance_id_, request_header);
  }

  /*!
   * \brief Send an error response if the SOME/IP request is malformed. This method is invoked
   * when the return code of the error response is only known during runtime.
   * \param return_code The return code to send.
   * \param request_header The header taken from the request.
   */
  void SendErrorResponse(const amsr::someip_protocol::internal::ReturnCode return_code,
                         const amsr::someip_protocol::internal::SomeIpMessageHeader& request_header) {
    someip_binding_server_manager_.SendErrorResponse(return_code, instance_id_, request_header);
  }

  /*!
   * \brief Send an event notification
   * \param packet SOME/IP packet with header and payload.
   */
  void SendEventNotification(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Called by frontend skeleton on event notification for service event 'LKA_speed'.
   * \param data Event sample of type speedtype
   */
  void SendEventLKA_speed(const apns::speedtype& data) override;

  /*!
   * \brief Called by frontend skeleton on event notification for service event 'ToGoal_speed'.
   * \param data Event sample of type speedtype
   */
  void SendEventToGoal_speed(const apns::speedtype& data) override;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

 private:
  /** SOME/IP instance ID offered by this skeleton */
  amsr::someip_protocol::internal::InstanceId instance_id_;

  /** Related SOME/IP binding */
  amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager_;

  /** Related service skeleton specific resource manager */
  resources::speed_controlSkeletonResourceManager& resource_manager_;

  /** Reference to the related frontend skeleton */
  skeleton::speed_controlSkeleton& skeleton_;

  /* ---- Methods ------------------------------------------------------------------------------------------ */
  /* ---- Event manager -------------------------------------------------------------------------------------------- */
  /** Event manager for skeleton event 'LKA_speed' */
  speed_controlSkeletonSomeIpEventManagerLKA_speed event_manager_LKA_speed_;

  /** Event manager for skeleton event 'ToGoal_speed' */
  speed_controlSkeletonSomeIpEventManagerToGoal_speed event_manager_ToGoal_speed_;

  /* ---- Field manager -------------------------------------------------------------------------------------------- */
};

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_BINDING_H_

