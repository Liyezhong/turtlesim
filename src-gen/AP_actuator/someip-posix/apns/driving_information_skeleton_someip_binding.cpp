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
/**        \file  AP_actuator/someip-posix/apns/driving_information_skeleton_someip_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'driving_information'
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
#include "apns/driving_information_skeleton_someip_binding.h"
#include "apns/driving_information.h"
#include "someip-protocol/internal/marshalling.h"

namespace apns {
namespace someip_binding {
namespace internal {

/*!
 * \brief Generated SOME/IP related service ID.
 */
constexpr amsr::someip_protocol::internal::ServiceId driving_informationSkeletonSomeIpBinding::kServiceId;

/*!
 * \brief SOME/IP major version of this service interface deployment.
 */
constexpr amsr::someip_protocol::internal::MajorVersion driving_informationSkeletonSomeIpBinding::kMajorVersion;

driving_informationSkeletonSomeIpBinding::driving_informationSkeletonSomeIpBinding(
    amsr::someip_protocol::internal::InstanceId instance_id,
    amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager,
    resources::driving_informationSkeletonResourceManager& resource_manager,
    skeleton::driving_informationSkeleton& skeleton)
    : instance_id_(instance_id),
      someip_binding_server_manager_(someip_binding_server_manager),
      resource_manager_(resource_manager),
      skeleton_(skeleton) ,
      event_manager_vehicle_speed_(*this, resource_manager_.GetEventvehicle_speedTxBufferAllocator()),
      event_manager_vehicle_position_(*this, resource_manager_.GetEventvehicle_positionTxBufferAllocator()){
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = driving_informationSkeletonSomeIpBinding::kServiceId;
  // Register this skeleton binding for method requests and event requests in the AraComSomeIpBinding.
  someip_binding_server_manager_.RegisterSkeletonBinding(std::make_tuple(service_id, instance_id_), this);
}

driving_informationSkeletonSomeIpBinding::~driving_informationSkeletonSomeIpBinding() {
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = driving_informationSkeletonSomeIpBinding::kServiceId;
  someip_binding_server_manager_.DeRegisterSkeletonBinding(std::make_tuple(service_id, instance_id_));
}

void driving_informationSkeletonSomeIpBinding::HandleMethodRequest(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&&) {
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

void driving_informationSkeletonSomeIpBinding::SendMethodResponse(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendMethodResponse(instance_id_, std::move(packet));
}

void driving_informationSkeletonSomeIpBinding::SendEventNotification(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendEventNotification(instance_id_, std::move(packet));
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* Event 'vehicle_speed' */
void driving_informationSkeletonSomeIpBinding::SendEventvehicle_speed(const apns::speedtype& data) {
  event_manager_vehicle_speed_.Send(data);
}

/* Event 'vehicle_position' */
void driving_informationSkeletonSomeIpBinding::SendEventvehicle_position(const apns::locationtype& data) {
  event_manager_vehicle_position_.Send(data);
}
/* ---- Fields ----------------------------------------------------------------------------------------------------- */

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

