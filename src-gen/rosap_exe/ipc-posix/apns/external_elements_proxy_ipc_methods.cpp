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
/**        \file  rosap_exe/ipc-posix/apns/external_elements_proxy_ipc_methods.cpp
 *        \brief  IPC proxy method de- /serialization handling for methods and field methods of service 'external_elements'
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
#include "apns/external_elements_proxy_ipc_methods.h"
#include <utility>
#include "apns/external_elements_proxy_ipc_binding.h"
#include "ara/com/com_error_domain.h"
#include "ipc_binding/internal/ipc_protocol/marshalling.h"
#include "someip-protocol/internal/ap_application_error_marshalling.h"

namespace apns {
namespace ipc_binding {
namespace internal {


  namespace fields {
/* ---- Field method 'laneGet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId ProxylaneGet::kMethodId;

ProxylaneGet::ProxylaneGet(
    external_elementsRequiredIpcServiceInstance& ipc_proxy_instance)
    : Base{"external_elementsProxyIpclaneGet"},
      ipc_proxy_instance_{ipc_proxy_instance} {}

ara::core::Future<apns::internal::fields::lane::Output> ProxylaneGet::HandleMethodRequest() {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  const ipc_protocol::SessionId session_id{GetSessionHandler()};
  typename Base::Session& session{this->GetSessionHandler()};
  ++session;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::RequestMessageHeader header{};
  header.service_id_ = ipc_proxy_instance_.GetServiceId();
  header.instance_id_ = ipc_proxy_instance_.GetInstanceId();
  header.major_version_ = ipc_proxy_instance_.GetMajorVersion();
  header.method_id_ = kMethodId;
  header.client_id_ = ipc_proxy_instance_.GetClientId();
  header.session_id_ = session_id;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::RequestMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Close IPC header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


    amsr::ipc_binding::internal::methods::ProxyRequestHandler<apns::internal::fields::lane::Output> request_handler{session_id, GetLogger()};
    return request_handler.HandleSerializedMethodRequest(ipc_proxy_instance_, serialization_status, std::move(packet), GetPendingRequestMap(), header);
}

void ProxylaneGet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  ipc_protocol::ResponseMessageHeader const& header{response.GetMessageHeader()};
  ipc_protocol::SessionId const session_id{header.session_id_};

  // Move the ownership of the packet to this scope for deserialization of the serialized byte stream.
  ipc_protocol::IpcPacket packet{response.GetPacket()};

  // Root deserializer
  common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};

  // Deserialize protocol header and response header
  ipc_marshaller::ResponseMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  HandleMethodResponseOk(std::move(header_deserializer), session_id);
}

void ProxylaneGet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& ) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

}

/*!
 * \brief Deserializer for argument 'out_val' (AsrPath: /turtlesim/ServiceDesign/datatype/lanetype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementslaneGetout_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementslaneGetout_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementslaneGetout_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementslaneGetout_valDeserializer") {}

/*!
 * \brief Deserialize argument 'out_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::lanetype, bool> Deserialize() {
  return Deserializeout_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_k_type, bool> Deserializeout_val_k(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'k'
    bool deserialization_ok{true};
  
  apns::lanetype::_k_type out_val_k{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_k{parent};
  deserialization_ok &= deserializer__out_val_k.PopFront(out_val_k) > 0U;
    return std::make_pair(out_val_k, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_b_type, bool> Deserializeout_val_b(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'b'
    bool deserialization_ok{true};
  
  apns::lanetype::_b_type out_val_b{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_b{parent};
  deserialization_ok &= deserializer__out_val_b.PopFront(out_val_b) > 0U;
    return std::make_pair(out_val_b, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/lanetype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::lanetype, bool> Deserializeout_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'out_val'
  bool deserialization_ok{true};

apns::lanetype out_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__out_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::lanetype::_k_type, bool> ret_k{Deserializeout_val_k(&deserializer__out_val)};
  deserialization_ok &= ret_k.second;
  out_val.k = ret_k.first;
  const std::pair<apns::lanetype::_b_type, bool> ret_b{Deserializeout_val_b(&deserializer__out_val)};
  deserialization_ok &= ret_b.second;
  out_val.b = ret_b.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'out_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(out_val, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};




template <typename RootDeserializer>
void ProxylaneGet::HandleMethodResponseOk(RootDeserializer&& deserializer,  amsr::ipc_binding::internal::ipc_protocol::SessionId const session_id) {
  // Overall deserialization result
  bool deserialization_ok{true};
  
  // Deserialized output argument value(s)
  apns::lanetype arg_out_val{};
  
  // Deserialize method return value(s)
  if (deserialization_ok) {
    // Deserialize argument 'out_val'
  external_elementslaneGetout_valDeserializer<typename std::decay<RootDeserializer>::type> arg_out_val_deserializer{&deserializer};
  std::pair<apns::lanetype, bool> ret_out_val{arg_out_val_deserializer.Deserialize()};// Get deserialized value and update overall deserialization result
  arg_out_val = ret_out_val.first;
    deserialization_ok &= ret_out_val.second;
  }
  
  if (deserialization_ok) {
  
  // Build response output struct and set value of promise to notify user
  apns::internal::fields::lane::Output ret{arg_out_val};
  response_handler_.HandleMethodResponse(session_id, std::move(ret), Base::GetPendingRequestMap(), Base::GetLogger());} else {
    GetLogger().LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for method 'laneGet'";}, __func__, __LINE__);
  response_handler_.HandleMethodResponse(session_id,
                       {::ara::com::ComErrc::network_binding_failure, "Deserialization error occurred for method 'laneGet'"},
                       Base::GetPendingRequestMap(), Base::GetLogger());
  }

}


/* ---- /Field method 'laneGet' ------------------------------------------- */

}  // namespace fields

  namespace fields {
/* ---- Field method 'laneSet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId ProxylaneSet::kMethodId;

ProxylaneSet::ProxylaneSet(
    external_elementsRequiredIpcServiceInstance& ipc_proxy_instance)
    : Base{"external_elementsProxyIpclaneSet"},
      ipc_proxy_instance_{ipc_proxy_instance} {}

ara::core::Future<apns::internal::fields::lane::Output> ProxylaneSet::HandleMethodRequest(const apns::lanetype& arg_in_val) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  const ipc_protocol::SessionId session_id{GetSessionHandler()};
  typename Base::Session& session{this->GetSessionHandler()};
  ++session;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::RequestMessageHeader header{};
  header.service_id_ = ipc_proxy_instance_.GetServiceId();
  header.instance_id_ = ipc_proxy_instance_.GetInstanceId();
  header.major_version_ = ipc_proxy_instance_.GetMajorVersion();
  header.method_id_ = kMethodId;
  header.client_id_ = ipc_proxy_instance_.GetClientId();
  header.session_id_ = session_id;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::RequestMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'in_val'
    // CppImplDataTypeStruct serialization for element 'in_val' (/turtlesim/ServiceDesign/datatype/lanetype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_in_val{&serializer};
  // CppImplDataTypeValue serialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_in_val)> serializer_in_val_k{&serializer_in_val};
    serializer_in_val_k.PushBack(arg_in_val.k);
    serializer_in_val_k.Close();
  }
  // CppImplDataTypeValue serialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_in_val)> serializer_in_val_b{&serializer_in_val};
    serializer_in_val_b.PushBack(arg_in_val.b);
    serializer_in_val_b.Close();
  }
  serializer_in_val.Close();
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


    amsr::ipc_binding::internal::methods::ProxyRequestHandler<apns::internal::fields::lane::Output> request_handler{session_id, GetLogger()};
    return request_handler.HandleSerializedMethodRequest(ipc_proxy_instance_, serialization_status, std::move(packet), GetPendingRequestMap(), header);
}

void ProxylaneSet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  ipc_protocol::ResponseMessageHeader const& header{response.GetMessageHeader()};
  ipc_protocol::SessionId const session_id{header.session_id_};

  // Move the ownership of the packet to this scope for deserialization of the serialized byte stream.
  ipc_protocol::IpcPacket packet{response.GetPacket()};

  // Root deserializer
  common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};

  // Deserialize protocol header and response header
  ipc_marshaller::ResponseMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  HandleMethodResponseOk(std::move(header_deserializer), session_id);
}

void ProxylaneSet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& ) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

}

/*!
 * \brief Deserializer for argument 'out_val' (AsrPath: /turtlesim/ServiceDesign/datatype/lanetype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementslaneSetout_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementslaneSetout_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementslaneSetout_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementslaneSetout_valDeserializer") {}

/*!
 * \brief Deserialize argument 'out_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::lanetype, bool> Deserialize() {
  return Deserializeout_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_k_type, bool> Deserializeout_val_k(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'k'
    bool deserialization_ok{true};
  
  apns::lanetype::_k_type out_val_k{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_k{parent};
  deserialization_ok &= deserializer__out_val_k.PopFront(out_val_k) > 0U;
    return std::make_pair(out_val_k, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_b_type, bool> Deserializeout_val_b(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'b'
    bool deserialization_ok{true};
  
  apns::lanetype::_b_type out_val_b{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_b{parent};
  deserialization_ok &= deserializer__out_val_b.PopFront(out_val_b) > 0U;
    return std::make_pair(out_val_b, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/lanetype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::lanetype, bool> Deserializeout_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'out_val'
  bool deserialization_ok{true};

apns::lanetype out_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__out_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::lanetype::_k_type, bool> ret_k{Deserializeout_val_k(&deserializer__out_val)};
  deserialization_ok &= ret_k.second;
  out_val.k = ret_k.first;
  const std::pair<apns::lanetype::_b_type, bool> ret_b{Deserializeout_val_b(&deserializer__out_val)};
  deserialization_ok &= ret_b.second;
  out_val.b = ret_b.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'out_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(out_val, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};




template <typename RootDeserializer>
void ProxylaneSet::HandleMethodResponseOk(RootDeserializer&& deserializer,  amsr::ipc_binding::internal::ipc_protocol::SessionId const session_id) {
  // Overall deserialization result
  bool deserialization_ok{true};
  
  // Deserialized output argument value(s)
  apns::lanetype arg_out_val{};
  
  // Deserialize method return value(s)
  if (deserialization_ok) {
    // Deserialize argument 'out_val'
  external_elementslaneSetout_valDeserializer<typename std::decay<RootDeserializer>::type> arg_out_val_deserializer{&deserializer};
  std::pair<apns::lanetype, bool> ret_out_val{arg_out_val_deserializer.Deserialize()};// Get deserialized value and update overall deserialization result
  arg_out_val = ret_out_val.first;
    deserialization_ok &= ret_out_val.second;
  }
  
  if (deserialization_ok) {
  
  // Build response output struct and set value of promise to notify user
  apns::internal::fields::lane::Output ret{arg_out_val};
  response_handler_.HandleMethodResponse(session_id, std::move(ret), Base::GetPendingRequestMap(), Base::GetLogger());} else {
    GetLogger().LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for method 'laneSet'";}, __func__, __LINE__);
  response_handler_.HandleMethodResponse(session_id,
                       {::ara::com::ComErrc::network_binding_failure, "Deserialization error occurred for method 'laneSet'"},
                       Base::GetPendingRequestMap(), Base::GetLogger());
  }

}


/* ---- /Field method 'laneSet' ------------------------------------------- */

}  // namespace fields

  namespace fields {
/* ---- Field method 'objectGet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId ProxyobjectGet::kMethodId;

ProxyobjectGet::ProxyobjectGet(
    external_elementsRequiredIpcServiceInstance& ipc_proxy_instance)
    : Base{"external_elementsProxyIpcobjectGet"},
      ipc_proxy_instance_{ipc_proxy_instance} {}

ara::core::Future<apns::internal::fields::object::Output> ProxyobjectGet::HandleMethodRequest() {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  const ipc_protocol::SessionId session_id{GetSessionHandler()};
  typename Base::Session& session{this->GetSessionHandler()};
  ++session;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::RequestMessageHeader header{};
  header.service_id_ = ipc_proxy_instance_.GetServiceId();
  header.instance_id_ = ipc_proxy_instance_.GetInstanceId();
  header.major_version_ = ipc_proxy_instance_.GetMajorVersion();
  header.method_id_ = kMethodId;
  header.client_id_ = ipc_proxy_instance_.GetClientId();
  header.session_id_ = session_id;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::RequestMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Close IPC header serializer
    header_serializer.Close();

    // Transfer back the packet ownership
    packet = serializer.Close();
    // Determine final serialization result
    serialization_status = std::max(serialization_status, serializer.GetStatus());
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }


    amsr::ipc_binding::internal::methods::ProxyRequestHandler<apns::internal::fields::object::Output> request_handler{session_id, GetLogger()};
    return request_handler.HandleSerializedMethodRequest(ipc_proxy_instance_, serialization_status, std::move(packet), GetPendingRequestMap(), header);
}

void ProxyobjectGet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  ipc_protocol::ResponseMessageHeader const& header{response.GetMessageHeader()};
  ipc_protocol::SessionId const session_id{header.session_id_};

  // Move the ownership of the packet to this scope for deserialization of the serialized byte stream.
  ipc_protocol::IpcPacket packet{response.GetPacket()};

  // Root deserializer
  common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};

  // Deserialize protocol header and response header
  ipc_marshaller::ResponseMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  HandleMethodResponseOk(std::move(header_deserializer), session_id);
}

void ProxyobjectGet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& ) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

}

/*!
 * \brief Deserializer for argument 'out_val' (AsrPath: /turtlesim/ServiceDesign/datatype/locationtype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementsobjectGetout_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementsobjectGetout_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementsobjectGetout_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementsobjectGetout_valDeserializer") {}

/*!
 * \brief Deserialize argument 'out_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::locationtype, bool> Deserialize() {
  return Deserializeout_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_x_type, bool> Deserializeout_val_x(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'x'
    bool deserialization_ok{true};
  
  apns::locationtype::_x_type out_val_x{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_x{parent};
  deserialization_ok &= deserializer__out_val_x.PopFront(out_val_x) > 0U;
    return std::make_pair(out_val_x, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_y_type, bool> Deserializeout_val_y(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'y'
    bool deserialization_ok{true};
  
  apns::locationtype::_y_type out_val_y{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_y{parent};
  deserialization_ok &= deserializer__out_val_y.PopFront(out_val_y) > 0U;
    return std::make_pair(out_val_y, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_theta_type, bool> Deserializeout_val_theta(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'theta'
    bool deserialization_ok{true};
  
  apns::locationtype::_theta_type out_val_theta{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_theta{parent};
  deserialization_ok &= deserializer__out_val_theta.PopFront(out_val_theta) > 0U;
    return std::make_pair(out_val_theta, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/locationtype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::locationtype, bool> Deserializeout_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'out_val'
  bool deserialization_ok{true};

apns::locationtype out_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__out_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::locationtype::_x_type, bool> ret_x{Deserializeout_val_x(&deserializer__out_val)};
  deserialization_ok &= ret_x.second;
  out_val.x = ret_x.first;
  const std::pair<apns::locationtype::_y_type, bool> ret_y{Deserializeout_val_y(&deserializer__out_val)};
  deserialization_ok &= ret_y.second;
  out_val.y = ret_y.first;
  const std::pair<apns::locationtype::_theta_type, bool> ret_theta{Deserializeout_val_theta(&deserializer__out_val)};
  deserialization_ok &= ret_theta.second;
  out_val.theta = ret_theta.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'out_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(out_val, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};




template <typename RootDeserializer>
void ProxyobjectGet::HandleMethodResponseOk(RootDeserializer&& deserializer,  amsr::ipc_binding::internal::ipc_protocol::SessionId const session_id) {
  // Overall deserialization result
  bool deserialization_ok{true};
  
  // Deserialized output argument value(s)
  apns::locationtype arg_out_val{};
  
  // Deserialize method return value(s)
  if (deserialization_ok) {
    // Deserialize argument 'out_val'
  external_elementsobjectGetout_valDeserializer<typename std::decay<RootDeserializer>::type> arg_out_val_deserializer{&deserializer};
  std::pair<apns::locationtype, bool> ret_out_val{arg_out_val_deserializer.Deserialize()};// Get deserialized value and update overall deserialization result
  arg_out_val = ret_out_val.first;
    deserialization_ok &= ret_out_val.second;
  }
  
  if (deserialization_ok) {
  
  // Build response output struct and set value of promise to notify user
  apns::internal::fields::object::Output ret{arg_out_val};
  response_handler_.HandleMethodResponse(session_id, std::move(ret), Base::GetPendingRequestMap(), Base::GetLogger());} else {
    GetLogger().LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for method 'objectGet'";}, __func__, __LINE__);
  response_handler_.HandleMethodResponse(session_id,
                       {::ara::com::ComErrc::network_binding_failure, "Deserialization error occurred for method 'objectGet'"},
                       Base::GetPendingRequestMap(), Base::GetLogger());
  }

}


/* ---- /Field method 'objectGet' ------------------------------------------- */

}  // namespace fields

  namespace fields {
/* ---- Field method 'objectSet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId ProxyobjectSet::kMethodId;

ProxyobjectSet::ProxyobjectSet(
    external_elementsRequiredIpcServiceInstance& ipc_proxy_instance)
    : Base{"external_elementsProxyIpcobjectSet"},
      ipc_proxy_instance_{ipc_proxy_instance} {}

ara::core::Future<apns::internal::fields::object::Output> ProxyobjectSet::HandleMethodRequest(const apns::locationtype& arg_in_val) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

  const ipc_protocol::SessionId session_id{GetSessionHandler()};
  typename Base::Session& session{this->GetSessionHandler()};
  ++session;

  // Assemble the request header based on the information from the deployment.
  ipc_protocol::RequestMessageHeader header{};
  header.service_id_ = ipc_proxy_instance_.GetServiceId();
  header.instance_id_ = ipc_proxy_instance_.GetInstanceId();
  header.major_version_ = ipc_proxy_instance_.GetMajorVersion();
  header.method_id_ = kMethodId;
  header.client_id_ = ipc_proxy_instance_.GetClientId();
  header.session_id_ = session_id;


  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::RequestMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'in_val'
    // CppImplDataTypeStruct serialization for element 'in_val' (/turtlesim/ServiceDesign/datatype/locationtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_in_val{&serializer};
  // CppImplDataTypeValue serialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_in_val)> serializer_in_val_x{&serializer_in_val};
    serializer_in_val_x.PushBack(arg_in_val.x);
    serializer_in_val_x.Close();
  }
  // CppImplDataTypeValue serialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_in_val)> serializer_in_val_y{&serializer_in_val};
    serializer_in_val_y.PushBack(arg_in_val.y);
    serializer_in_val_y.Close();
  }
  // CppImplDataTypeValue serialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_in_val)> serializer_in_val_theta{&serializer_in_val};
    serializer_in_val_theta.PushBack(arg_in_val.theta);
    serializer_in_val_theta.Close();
  }
  serializer_in_val.Close();
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


    amsr::ipc_binding::internal::methods::ProxyRequestHandler<apns::internal::fields::object::Output> request_handler{session_id, GetLogger()};
    return request_handler.HandleSerializedMethodRequest(ipc_proxy_instance_, serialization_status, std::move(packet), GetPendingRequestMap(), header);
}

void ProxyobjectSet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  ipc_protocol::ResponseMessageHeader const& header{response.GetMessageHeader()};
  ipc_protocol::SessionId const session_id{header.session_id_};

  // Move the ownership of the packet to this scope for deserialization of the serialized byte stream.
  ipc_protocol::IpcPacket packet{response.GetPacket()};

  // Root deserializer
  common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};

  // Deserialize protocol header and response header
  ipc_marshaller::ResponseMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  HandleMethodResponseOk(std::move(header_deserializer), session_id);
}

void ProxyobjectSet::HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& ) {
  GetLogger().LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

}

/*!
 * \brief Deserializer for argument 'out_val' (AsrPath: /turtlesim/ServiceDesign/datatype/locationtype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementsobjectSetout_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementsobjectSetout_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementsobjectSetout_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementsobjectSetout_valDeserializer") {}

/*!
 * \brief Deserialize argument 'out_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::locationtype, bool> Deserialize() {
  return Deserializeout_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_x_type, bool> Deserializeout_val_x(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'x'
    bool deserialization_ok{true};
  
  apns::locationtype::_x_type out_val_x{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_x{parent};
  deserialization_ok &= deserializer__out_val_x.PopFront(out_val_x) > 0U;
    return std::make_pair(out_val_x, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_y_type, bool> Deserializeout_val_y(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'y'
    bool deserialization_ok{true};
  
  apns::locationtype::_y_type out_val_y{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_y{parent};
  deserialization_ok &= deserializer__out_val_y.PopFront(out_val_y) > 0U;
    return std::make_pair(out_val_y, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_theta_type, bool> Deserializeout_val_theta(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'theta'
    bool deserialization_ok{true};
  
  apns::locationtype::_theta_type out_val_theta{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val_theta{parent};
  deserialization_ok &= deserializer__out_val_theta.PopFront(out_val_theta) > 0U;
    return std::make_pair(out_val_theta, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/locationtype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::locationtype, bool> Deserializeout_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'out_val'
  bool deserialization_ok{true};

apns::locationtype out_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__out_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__out_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::locationtype::_x_type, bool> ret_x{Deserializeout_val_x(&deserializer__out_val)};
  deserialization_ok &= ret_x.second;
  out_val.x = ret_x.first;
  const std::pair<apns::locationtype::_y_type, bool> ret_y{Deserializeout_val_y(&deserializer__out_val)};
  deserialization_ok &= ret_y.second;
  out_val.y = ret_y.first;
  const std::pair<apns::locationtype::_theta_type, bool> ret_theta{Deserializeout_val_theta(&deserializer__out_val)};
  deserialization_ok &= ret_theta.second;
  out_val.theta = ret_theta.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'out_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(out_val, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};




template <typename RootDeserializer>
void ProxyobjectSet::HandleMethodResponseOk(RootDeserializer&& deserializer,  amsr::ipc_binding::internal::ipc_protocol::SessionId const session_id) {
  // Overall deserialization result
  bool deserialization_ok{true};
  
  // Deserialized output argument value(s)
  apns::locationtype arg_out_val{};
  
  // Deserialize method return value(s)
  if (deserialization_ok) {
    // Deserialize argument 'out_val'
  external_elementsobjectSetout_valDeserializer<typename std::decay<RootDeserializer>::type> arg_out_val_deserializer{&deserializer};
  std::pair<apns::locationtype, bool> ret_out_val{arg_out_val_deserializer.Deserialize()};// Get deserialized value and update overall deserialization result
  arg_out_val = ret_out_val.first;
    deserialization_ok &= ret_out_val.second;
  }
  
  if (deserialization_ok) {
  
  // Build response output struct and set value of promise to notify user
  apns::internal::fields::object::Output ret{arg_out_val};
  response_handler_.HandleMethodResponse(session_id, std::move(ret), Base::GetPendingRequestMap(), Base::GetLogger());} else {
    GetLogger().LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for method 'objectSet'";}, __func__, __LINE__);
  response_handler_.HandleMethodResponse(session_id,
                       {::ara::com::ComErrc::network_binding_failure, "Deserialization error occurred for method 'objectSet'"},
                       Base::GetPendingRequestMap(), Base::GetLogger());
  }

}


/* ---- /Field method 'objectSet' ------------------------------------------- */

}  // namespace fields
}  // namespace internal
}  // namespace ipc_binding
}  // namespace apns

