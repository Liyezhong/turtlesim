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
/**        \file  rosap_exe/ipc-posix/apns/speed_control_skeleton_ipc_event_manager.cpp
 *        \brief  IPC skeleton event handling for events and field notifications of service 'speed_control'
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_skeleton_ipc_event_manager.h"
#include <memory>
#include <utility>
#include "apns/speed_control_skeleton_ipc_binding.h"
#include "ipc_binding/internal/ipc_protocol/marshalling.h"

namespace apns {

/* ---- Event 'LKA_speed' ------------------------------------------- */

speed_controlSkeletonIpcEventManagerLKA_speed::speed_controlSkeletonIpcEventManagerLKA_speed(
    speed_controlProvidedIpcServiceInstance& skeleton_binding)
    : skeleton_binding_(skeleton_binding),
      logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "speed_controlSkeletonIpcEventManagerLKA_speed") {}

void speed_controlSkeletonIpcEventManagerLKA_speed::Send(const apns::speedtype& data) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::NotificationMessageHeader header{};
  header.service_id_ = speed_controlProvidedIpcDeployment::kDeployment.service_id_;
  header.instance_id_ = skeleton_binding_.GetInstanceId();
  header.major_version_ = speed_controlProvidedIpcDeployment::kDeployment.service_interface_version_.major_version_;
  header.event_id_ = kEventId;
  header.session_id_ = next_session_id_;

  ++next_session_id_;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::NotificationMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'data'
    // CppImplDataTypeStruct serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_data{&serializer};
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_data)> serializer_data_l_vel{&serializer_data};
    serializer_data_l_vel.PushBack(data.l_vel);
    serializer_data_l_vel.Close();
  }
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_data)> serializer_data_a_vel{&serializer_data};
    serializer_data_a_vel.PushBack(data.a_vel);
    serializer_data_a_vel.Close();
  }
  serializer_data.Close();
}

    // Close IPC header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


  if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kOk) {
    ipc_protocol::IpcPacketShared packet_shared{packet.release()};
    amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr message{std::make_shared<ipc_protocol::NotificationMessage>(header, packet_shared)};
    skeleton_binding_.RouteNotification(message);
  }
}

ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> speed_controlSkeletonIpcEventManagerLKA_speed::HandleEventSubscription() {
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> init_field;
  return init_field;
}

/* ---- Event 'ToGoal_speed' ------------------------------------------- */

speed_controlSkeletonIpcEventManagerToGoal_speed::speed_controlSkeletonIpcEventManagerToGoal_speed(
    speed_controlProvidedIpcServiceInstance& skeleton_binding)
    : skeleton_binding_(skeleton_binding),
      logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "speed_controlSkeletonIpcEventManagerToGoal_speed") {}

void speed_controlSkeletonIpcEventManagerToGoal_speed::Send(const apns::speedtype& data) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::NotificationMessageHeader header{};
  header.service_id_ = speed_controlProvidedIpcDeployment::kDeployment.service_id_;
  header.instance_id_ = skeleton_binding_.GetInstanceId();
  header.major_version_ = speed_controlProvidedIpcDeployment::kDeployment.service_interface_version_.major_version_;
  header.event_id_ = kEventId;
  header.session_id_ = next_session_id_;

  ++next_session_id_;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::NotificationMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'data'
    // CppImplDataTypeStruct serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_data{&serializer};
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_data)> serializer_data_l_vel{&serializer_data};
    serializer_data_l_vel.PushBack(data.l_vel);
    serializer_data_l_vel.Close();
  }
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_data)> serializer_data_a_vel{&serializer_data};
    serializer_data_a_vel.PushBack(data.a_vel);
    serializer_data_a_vel.Close();
  }
  serializer_data.Close();
}

    // Close IPC header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


  if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kOk) {
    ipc_protocol::IpcPacketShared packet_shared{packet.release()};
    amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr message{std::make_shared<ipc_protocol::NotificationMessage>(header, packet_shared)};
    skeleton_binding_.RouteNotification(message);
  }
}

ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> speed_controlSkeletonIpcEventManagerToGoal_speed::HandleEventSubscription() {
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> init_field;
  return init_field;
}


}  // namespace apns

