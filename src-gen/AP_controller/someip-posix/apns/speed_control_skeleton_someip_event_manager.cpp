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
/**        \file  AP_controller/someip-posix/apns/speed_control_skeleton_someip_event_manager.cpp
 *        \brief  SOME/IP skeleton event handling for events and field notifications of service 'speed_control'
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
#include "apns/speed_control_skeleton_someip_event_manager.h"
#include <algorithm>
#include <utility>
#include "apns/speed_control_skeleton_someip_binding.h"
#include "ara/com/internal_com_exception.h"
#include "someip_daemon_client/internal/someip_daemon_client.h"

namespace apns {
namespace someip_binding {
namespace internal {

/* ---- Event 'LKA_speed' ------------------------------------------- */

speed_controlSkeletonSomeIpEventManagerLKA_speed::speed_controlSkeletonSomeIpEventManagerLKA_speed(
    speed_controlSkeletonSomeIpBinding& skeleton_binding, amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator)
    : skeleton_binding_(skeleton_binding),
      tx_buffer_allocator_(tx_buffer_allocator),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "speed_controlSkeletonSomeIpEventManagerLKA_speed") {}

void speed_controlSkeletonSomeIpEventManagerLKA_speed::Send(const apns::speedtype& data) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  const amsr::someip_protocol::internal::SessionId session_id{GetSessionHandler()};
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& session{this->GetSessionHandler()};
  ++session;

  // Fill SOME/IP header with data for the request
  amsr::someip_protocol::internal::SomeIpMessageHeader header{};
  header.service_id_ = speed_controlSkeletonSomeIpBinding::kServiceId;
  header.method_id_ = 0xB26DU;
  header.client_id_ = 0U;
  header.session_id_ = session_id;
  header.message_type_ = amsr::someip_protocol::internal::SomeIpMessageType::kNotification;
  header.protocol_version_ = amsr::someip_protocol::internal::kProtocolVersion;
  header.interface_version_ = 1U;
  header.return_code_ = amsr::someip_protocol::internal::SomeIpReturnCode::kOk;
  header.length_ = 0U;  // Set right after payload serialization is complete

  // Allocate memory for packet serialization
  constexpr std::size_t alloc_size{amsr::someip_protocol::internal::kHeaderSize};
  amsr::com_common::internal::memory::MemoryBufferPtr packet{tx_buffer_allocator_.Allocate(alloc_size)};
  using DefaultSerializationPolicy = someip_marshalling::BEPayloadNoLengthFieldMemoryBufferPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize SOME/IP header
    someip_marshalling::SomeIpHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'data'
    // CppImplDataTypeStruct serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer)> serializer_data{&serializer};
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer_data)> serializer_data_l_vel{&serializer_data};
    serializer_data_l_vel.PushBack(data.l_vel);
    serializer_data_l_vel.Close();
  }
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer_data)> serializer_data_a_vel{&serializer_data};
    serializer_data_a_vel.PushBack(data.a_vel);
    serializer_data_a_vel.Close();
  }
  serializer_data.Close();
}

    // Close SOME/IP header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


  if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kOk) {
    // Send packet to the SkeletonBinding, which forwards the packet together with the instance id to AraComSomeIpBinding.
    skeleton_binding_.SendEventNotification(std::move(packet));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for event notification of 'speed_control::LKA_speed' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // Memory allocation was ok, but serialization failed.
    const char* error_msg{"Serialization of event notification of 'speed_control::LKA_speed' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}
/* ---- Event 'ToGoal_speed' ------------------------------------------- */

speed_controlSkeletonSomeIpEventManagerToGoal_speed::speed_controlSkeletonSomeIpEventManagerToGoal_speed(
    speed_controlSkeletonSomeIpBinding& skeleton_binding, amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator)
    : skeleton_binding_(skeleton_binding),
      tx_buffer_allocator_(tx_buffer_allocator),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "speed_controlSkeletonSomeIpEventManagerToGoal_speed") {}

void speed_controlSkeletonSomeIpEventManagerToGoal_speed::Send(const apns::speedtype& data) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  const amsr::someip_protocol::internal::SessionId session_id{GetSessionHandler()};
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& session{this->GetSessionHandler()};
  ++session;

  // Fill SOME/IP header with data for the request
  amsr::someip_protocol::internal::SomeIpMessageHeader header{};
  header.service_id_ = speed_controlSkeletonSomeIpBinding::kServiceId;
  header.method_id_ = 0xB26EU;
  header.client_id_ = 0U;
  header.session_id_ = session_id;
  header.message_type_ = amsr::someip_protocol::internal::SomeIpMessageType::kNotification;
  header.protocol_version_ = amsr::someip_protocol::internal::kProtocolVersion;
  header.interface_version_ = 1U;
  header.return_code_ = amsr::someip_protocol::internal::SomeIpReturnCode::kOk;
  header.length_ = 0U;  // Set right after payload serialization is complete

  // Allocate memory for packet serialization
  constexpr std::size_t alloc_size{amsr::someip_protocol::internal::kHeaderSize};
  amsr::com_common::internal::memory::MemoryBufferPtr packet{tx_buffer_allocator_.Allocate(alloc_size)};
  using DefaultSerializationPolicy = someip_marshalling::BEPayloadNoLengthFieldMemoryBufferPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize SOME/IP header
    someip_marshalling::SomeIpHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'data'
    // CppImplDataTypeStruct serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer)> serializer_data{&serializer};
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer_data)> serializer_data_l_vel{&serializer_data};
    serializer_data_l_vel.PushBack(data.l_vel);
    serializer_data_l_vel.Close();
  }
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  // CppImplDataTypeValue serialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
  {
    ::amsr::com_common::internal::serialization::Serializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, decltype(serializer_data)> serializer_data_a_vel{&serializer_data};
    serializer_data_a_vel.PushBack(data.a_vel);
    serializer_data_a_vel.Close();
  }
  serializer_data.Close();
}

    // Close SOME/IP header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


  if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kOk) {
    // Send packet to the SkeletonBinding, which forwards the packet together with the instance id to AraComSomeIpBinding.
    skeleton_binding_.SendEventNotification(std::move(packet));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for event notification of 'speed_control::ToGoal_speed' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // Memory allocation was ok, but serialization failed.
    const char* error_msg{"Serialization of event notification of 'speed_control::ToGoal_speed' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

