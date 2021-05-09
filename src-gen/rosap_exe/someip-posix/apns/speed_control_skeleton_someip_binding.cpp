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
/**        \file  rosap_exe/someip-posix/apns/speed_control_skeleton_someip_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'speed_control'
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
#include "apns/speed_control_skeleton_someip_binding.h"
#include "apns/speed_control.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {
namespace someip_binding {
namespace internal {

/*!
 * \brief Generated SOME/IP related service ID.
 */
constexpr amsr::someip_protocol::internal::ServiceId speed_controlSkeletonSomeIpBinding::kServiceId;

/*!
 * \brief SOME/IP major version of this service interface deployment.
 */
constexpr amsr::someip_protocol::internal::MajorVersion speed_controlSkeletonSomeIpBinding::kMajorVersion;

speed_controlSkeletonSomeIpBinding::speed_controlSkeletonSomeIpBinding(
    amsr::someip_protocol::internal::InstanceId instance_id,
    amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager,
    resources::speed_controlSkeletonResourceManager& resource_manager,
    skeleton::speed_controlSkeleton& skeleton)
    : instance_id_(instance_id),
      someip_binding_server_manager_(someip_binding_server_manager),
      resource_manager_(resource_manager),
      skeleton_(skeleton) ,
      event_manager_LKA_speed_(*this, resource_manager_.GetEventLKA_speedTxBufferAllocator()),
      event_manager_ToGoal_speed_(*this, resource_manager_.GetEventToGoal_speedTxBufferAllocator()){
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = speed_controlSkeletonSomeIpBinding::kServiceId;
  // Register this skeleton binding for method requests and event requests in the AraComSomeIpBinding.
  someip_binding_server_manager_.RegisterSkeletonBinding(std::make_tuple(service_id, instance_id_), this);
}

speed_controlSkeletonSomeIpBinding::~speed_controlSkeletonSomeIpBinding() {
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = speed_controlSkeletonSomeIpBinding::kServiceId;
  someip_binding_server_manager_.DeRegisterSkeletonBinding(std::make_tuple(service_id, instance_id_));
}

void speed_controlSkeletonSomeIpBinding::HandleMethodRequest(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&&) {
  // Get method ID from header
  const amsr::someip_protocol::internal::MethodId method_id{header.method_id_};

  // Based on the method id -> static dispatching to the method request/response manager
  switch (method_id) {
    default: {
      // Method implementation is missing.
      SendErrorResponse<amsr::someip_protocol::internal::SomeIpReturnCode::kUnknownMethod>(header);
      break;
    }
  }
}

void speed_controlSkeletonSomeIpBinding::SendMethodResponse(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendMethodResponse(instance_id_, std::move(packet));
}

void speed_controlSkeletonSomeIpBinding::SendEventNotification(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendEventNotification(instance_id_, std::move(packet));
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* Event 'someip_lka_speed' */
void speed_controlSkeletonSomeIpBinding::SendEventLKA_speed(const apns::speedtype& data) {
  event_manager_LKA_speed_.Send(data);
}

/* Event 'Someip_ToGoal_speed' */
void speed_controlSkeletonSomeIpBinding::SendEventToGoal_speed(const apns::speedtype& data) {
  event_manager_ToGoal_speed_.Send(data);
}
/* ---- Fields ----------------------------------------------------------------------------------------------------- */

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

