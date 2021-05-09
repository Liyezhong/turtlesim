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
/**        \file  AP_controller/ipc-posix/apns/external_elements_skeleton_ipc_method_manager.cpp
 *        \brief  IPC skeleton method de- /serialization handling for methods and field methods of service 'external_elements'
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
#include "apns/external_elements_skeleton_ipc_method_manager.h"
#include <algorithm>
#include <utility>
#include "apns/external_elements_skeleton_ipc_binding.h"
#include "ara/com/internal_com_exception.h"
#include "ipc_binding/internal/ipc_protocol/marshalling.h"
#include "ipc_binding/internal/serializer_base.h"

namespace apns {

/* ---- Field method 'laneGet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId
    external_elementsSkeletonIpcFieldManagerlaneGet::kMethodId;

/*!
 * \brief Context storage for the response path for method 'laneGet'.
 * An object of this type is assembled during the operator-call and is given to SendMethodResponse().
 */
class external_elementsIpcResponsePathInfoFieldManagerlaneGet final {
 public:
  /// Header from the request with client ID and session ID.
  const amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader& header_;
  /// Response type to be filled after processing.
  const apns::internal::fields::lane::Output& out_val_;
};

/*!
 * \brief This functor is given to the frontend. Any functor (generic part) can
 * then be stored.
 */
class external_elementsSkeletonIpcFunctorlaneGet final : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param method_manager A pointer to the binding-related method manager for forwarding the response after processing the method request.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method.
   * \param header The IPC request header which must be stored for assembling the response (in case this method is not fire & forget).
   * \param remote_session_id Remote session id.
   */
  external_elementsSkeletonIpcFunctorlaneGet(external_elementsSkeletonIpcFieldManagerlaneGet* method_manager,
                                                   skeleton::external_elementsSkeleton* skeleton, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id,amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header) :
                                                   ::amsr::socal::internal::PendingRequest{skeleton}, method_manager_{method_manager}, skeleton_{skeleton}, header_{header}, remote_session_id_{remote_session_id} {}

  /*!
   * \brief Operator is being called when method invocation is scheduled in the frontend.
   */
  void operator()() override {
    
    // Call frontend skeleton implementation and wait until asynchronous result is provided
    ara::core::Result<apns::internal::fields::lane::Output> const result{skeleton_->lane.Get().GetResult()};
    if (result.HasValue()) {
      // Assemble the response path information within the binding.
      // That's necessary if the binding has additional info to transport as in the case for the IPC binding.
      external_elementsIpcResponsePathInfoFieldManagerlaneGet const response{header_, result.Value()};
      // Forward the result to the response path of the binding.
      method_manager_->SendMethodResponse(response, remote_session_id_);
    } else {
      method_manager_->SerializeAndSendApplicationErrorMethodResponse(header_, remote_session_id_, result.Error());
    }
  }

 private:
  /*!
   * \brief Binding-related interface to signalize a response right after the method
   * call.
   */
  external_elementsSkeletonIpcFieldManagerlaneGet* method_manager_;

  /*!
   * \brief Pointer to the skeleton to invoke the queue in the method request.
   */
  skeleton::external_elementsSkeleton* skeleton_;
  /*!
   * \brief Buffer the IPC request header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header_;

  /*!
   * \brief Remote session id.
   */
  const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id_;
};

external_elementsSkeletonIpcFieldManagerlaneGet::external_elementsSkeletonIpcFieldManagerlaneGet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept
: skeleton_binding_instance_{skeleton_binding_instance},
  logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "External_elementsProxyIpcMethodManagerlaneGet") {}


void external_elementsSkeletonIpcFieldManagerlaneGet::HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;


  // Buffer the request header for the response route.
  const ipc_protocol::RequestMessageHeader request_header{request.GetMessageHeader()};

  // Create a functor to save the context for being able to invoke the skeleton method request asynchronously.
  std::unique_ptr<external_elementsSkeletonIpcFunctorlaneGet> functor{
      vac::language::make_unique<external_elementsSkeletonIpcFunctorlaneGet>(
          this, &skeleton_binding_instance_.GetSkeleton()
          , request.GetRemoteSessionId(), request_header
  )};

  // Pass payload to skeleton that decides when to process the method call based on the processing-mode.
  // The response path is then called by the skeleton.
  skeleton_binding_instance_.GetSkeleton().HandleMethodRequest(std::move(functor));
}

void external_elementsSkeletonIpcFieldManagerlaneGet::SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerlaneGet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id) {
  // Get method request return value from output structure
  const apns::internal::fields::lane::Output& out_val{response.out_val_};
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

             // Copy the information from the request to get the same client + session ID.
             ipc_protocol::ResponseMessageHeader header{response.header_};

  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::ResponseMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'out_val'
    // CppImplDataTypeStruct serialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/lanetype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_out_val{&serializer};
  // CppImplDataTypeValue serialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_k{&serializer_out_val};
    serializer_out_val_k.PushBack(out_val.k);
    serializer_out_val_k.Close();
  }
  // CppImplDataTypeValue serialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_b{&serializer_out_val};
    serializer_out_val_b.PushBack(out_val.b);
    serializer_out_val_b.Close();
  }
  serializer_out_val.Close();
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
    // Assemble the complete response message for transmission.
    amsr::ipc_binding::internal::ipc_protocol::LocalResponseMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteResponse(std::move(response_msg));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for method 'external_elements::laneGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization for method 'external_elements::laneGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

void external_elementsSkeletonIpcFieldManagerlaneGet::SerializeAndSendApplicationErrorMethodResponse(
    amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
    amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
    ara::core::ErrorCode const& error_code) {
  logger_.LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};

  // Copy the information from the request to get the same client + session ID.
  ipc_protocol::ApplicationErrorMessageHeader header{};
  header.service_id_ = request_header.service_id_;
  header.instance_id_ = request_header.instance_id_;
  header.major_version_ = request_header.major_version_;
  header.method_id_ = request_header.method_id_;
  header.client_id_ = request_header.client_id_;
  header.session_id_ = request_header.session_id_;

  // Creation of a buffer to serialize the generic protocol header, the ApplicationError header and the payload.
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Build C++ variant representing the ApApplicationError
    std::string user_message{error_code.UserMessage().ToString()};
    amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct error_struct{error_code.Domain().Id(), error_code.Value(),
                                                              error_code.SupportData(),
                                                              user_message.c_str()};
    amsr::someip_protocol::internal::serialization::ApApplicationError ap_application_error{};
    ap_application_error.emplace<amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct>(error_struct);

    // Serialize the ApApplicationError
    someip_marshalling::ApApplicationErrorSerializer<
        amsr::ipc_binding::internal::ApplicationErrorMessageHeaderSerializerBase>
        serializer{logger_, std::move(packet), header};
    std::pair<ipc_protocol::IpcPacket, common_marshalling::SerializerStatus> serialization_result{
        serializer.Serialize(ap_application_error)};

    packet = std::move(serialization_result.first);
    serialization_status = serialization_result.second;
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }

  if (serialization_status == common_marshalling::SerializerStatus::kOk) {
    // Assemble the complete application error response message for transmission.
    ipc_protocol::LocalApplicationErrorMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteApplicationError(std::move(response_msg));
  } else if (serialization_status == common_marshalling::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{
        "Memory allocation for ApApplicationError response of method 'external_elements::laneGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization of ApApplicationError of method 'external_elements::laneGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

/* ---- /Field method 'laneGet' ------------------------------------------- */

/* ---- Field method 'laneSet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId
    external_elementsSkeletonIpcFieldManagerlaneSet::kMethodId;

/*!
 * \brief Context storage for the response path for method 'laneSet'.
 * An object of this type is assembled during the operator-call and is given to SendMethodResponse().
 */
class external_elementsIpcResponsePathInfoFieldManagerlaneSet final {
 public:
  /// Header from the request with client ID and session ID.
  const amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader& header_;
  /// Response type to be filled after processing.
  const apns::internal::fields::lane::Output& out_val_;
};

/*!
 * \brief This functor is given to the frontend. Any functor (generic part) can
 * then be stored.
 */
class external_elementsSkeletonIpcFunctorlaneSet final : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param method_manager A pointer to the binding-related method manager for forwarding the response after processing the method request.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method.
   * \param header The IPC request header which must be stored for assembling the response (in case this method is not fire & forget).
   * \param in_val Create a snapshot of this method input argument for this functor.
   * \param remote_session_id Remote session id.
   */
  external_elementsSkeletonIpcFunctorlaneSet(external_elementsSkeletonIpcFieldManagerlaneSet* method_manager,
                                                   skeleton::external_elementsSkeleton* skeleton, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id,amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header,const apns::lanetype& arg_in_val) :
                                                   ::amsr::socal::internal::PendingRequest{skeleton}, method_manager_{method_manager}, skeleton_{skeleton}, header_{header}, remote_session_id_{remote_session_id}, arg_in_val_{arg_in_val} {}

  /*!
   * \brief Operator is being called when method invocation is scheduled in the frontend.
   */
  void operator()() override {
    apns::lanetype const& arg_in_val{arg_in_val_};
    
    // Call frontend skeleton implementation and wait until asynchronous result is provided
    ara::core::Result<apns::internal::fields::lane::Output> const result{skeleton_->lane.Set(arg_in_val).GetResult()};
    if (result.HasValue()) {
      // Assemble the response path information within the binding.
      // That's necessary if the binding has additional info to transport as in the case for the IPC binding.
      external_elementsIpcResponsePathInfoFieldManagerlaneSet const response{header_, result.Value()};
      // Forward the result to the response path of the binding.
      method_manager_->SendMethodResponse(response, remote_session_id_);
    } else {
      method_manager_->SerializeAndSendApplicationErrorMethodResponse(header_, remote_session_id_, result.Error());
    }
  }

 private:
  /*!
   * \brief Binding-related interface to signalize a response right after the method
   * call.
   */
  external_elementsSkeletonIpcFieldManagerlaneSet* method_manager_;

  /*!
   * \brief Pointer to the skeleton to invoke the queue in the method request.
   */
  skeleton::external_elementsSkeleton* skeleton_;
  /*!
   * \brief Buffer the IPC request header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header_;

  /*!
   * \brief Remote session id.
   */
  const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id_;

  /*!
   * \brief Storing context of method argument 'in_val' in this functor for processing at any time.
   */
  const apns::lanetype arg_in_val_;
};

external_elementsSkeletonIpcFieldManagerlaneSet::external_elementsSkeletonIpcFieldManagerlaneSet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept
: skeleton_binding_instance_{skeleton_binding_instance},
  logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "External_elementsProxyIpcMethodManagerlaneSet") {}

/*!
 * \brief Deserializer for argument 'in_val' (AsrPath: /turtlesim/ServiceDesign/datatype/lanetype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementslaneSetin_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementslaneSetin_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementslaneSetin_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementslaneSetin_valDeserializer") {}

/*!
 * \brief Deserialize argument 'in_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::lanetype, bool> Deserialize() {
  return Deserializein_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_k_type, bool> Deserializein_val_k(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'k'
    bool deserialization_ok{true};
  
  apns::lanetype::_k_type in_val_k{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val_k{parent};
  deserialization_ok &= deserializer__in_val_k.PopFront(in_val_k) > 0U;
    return std::make_pair(in_val_k, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::lanetype::_b_type, bool> Deserializein_val_b(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'b'
    bool deserialization_ok{true};
  
  apns::lanetype::_b_type in_val_b{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val_b{parent};
  deserialization_ok &= deserializer__in_val_b.PopFront(in_val_b) > 0U;
    return std::make_pair(in_val_b, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'in_val' (/turtlesim/ServiceDesign/datatype/lanetype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::lanetype, bool> Deserializein_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'in_val'
  bool deserialization_ok{true};

apns::lanetype in_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__in_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::lanetype::_k_type, bool> ret_k{Deserializein_val_k(&deserializer__in_val)};
  deserialization_ok &= ret_k.second;
  in_val.k = ret_k.first;
  const std::pair<apns::lanetype::_b_type, bool> ret_b{Deserializein_val_b(&deserializer__in_val)};
  deserialization_ok &= ret_b.second;
  in_val.b = ret_b.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'in_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(in_val, deserialization_ok);
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



void external_elementsSkeletonIpcFieldManagerlaneSet::HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Overall deserialization result
  bool deserialization_ok{true};

  // Move the packet ownership to this scope for deserialization.
  ipc_protocol::IpcPacket packet{request.GetPacket()};

  // Create one root deserializer
  common_marshalling::Deserializer<ipc_marshalling::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};
  // Use the RequestMessageHeaderDeserializer to deserialize the protocol header and method request header.
  ipc_marshalling::RequestMessageHeaderDeserializer<ipc_marshalling::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  // Allocate input argument value(s) that shall be deserialized
  apns::lanetype arg_in_val{};

  // Deserialize the method parameter(s) from payload
  if(deserialization_ok) {
    // Deserialize argument 'in_val'
    external_elementslaneSetin_valDeserializer<typename std::decay<decltype(deserializer)>::type> arg_in_val_deserializer{&deserializer};
std::pair<apns::lanetype, bool> ret_in_val{arg_in_val_deserializer.Deserialize()};
    // Get deserialized value and update overall deserialization result
    arg_in_val = ret_in_val.first;
    deserialization_ok &= ret_in_val.second;
  }

  // Buffer the request header for the response route.
  const ipc_protocol::RequestMessageHeader request_header{request.GetMessageHeader()};

  // Create a functor to save the context for being able to invoke the skeleton method request asynchronously.
  std::unique_ptr<external_elementsSkeletonIpcFunctorlaneSet> functor{
      vac::language::make_unique<external_elementsSkeletonIpcFunctorlaneSet>(
          this, &skeleton_binding_instance_.GetSkeleton()
          , request.GetRemoteSessionId(), request_header
    , arg_in_val
    )};

  // Pass payload to skeleton that decides when to process the method call based on the processing-mode.
  // The response path is then called by the skeleton.
  skeleton_binding_instance_.GetSkeleton().HandleMethodRequest(std::move(functor));
}

void external_elementsSkeletonIpcFieldManagerlaneSet::SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerlaneSet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id) {
  // Get method request return value from output structure
  const apns::internal::fields::lane::Output& out_val{response.out_val_};
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

             // Copy the information from the request to get the same client + session ID.
             ipc_protocol::ResponseMessageHeader header{response.header_};

  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::ResponseMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'out_val'
    // CppImplDataTypeStruct serialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/lanetype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_out_val{&serializer};
  // CppImplDataTypeValue serialization for element 'k' (/turtlesim/ServiceDesign/datatype/lanetype/k)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_k{&serializer_out_val};
    serializer_out_val_k.PushBack(out_val.k);
    serializer_out_val_k.Close();
  }
  // CppImplDataTypeValue serialization for element 'b' (/turtlesim/ServiceDesign/datatype/lanetype/b)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_b{&serializer_out_val};
    serializer_out_val_b.PushBack(out_val.b);
    serializer_out_val_b.Close();
  }
  serializer_out_val.Close();
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
    // Assemble the complete response message for transmission.
    amsr::ipc_binding::internal::ipc_protocol::LocalResponseMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteResponse(std::move(response_msg));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for method 'external_elements::laneSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization for method 'external_elements::laneSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

void external_elementsSkeletonIpcFieldManagerlaneSet::SerializeAndSendApplicationErrorMethodResponse(
    amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
    amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
    ara::core::ErrorCode const& error_code) {
  logger_.LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};

  // Copy the information from the request to get the same client + session ID.
  ipc_protocol::ApplicationErrorMessageHeader header{};
  header.service_id_ = request_header.service_id_;
  header.instance_id_ = request_header.instance_id_;
  header.major_version_ = request_header.major_version_;
  header.method_id_ = request_header.method_id_;
  header.client_id_ = request_header.client_id_;
  header.session_id_ = request_header.session_id_;

  // Creation of a buffer to serialize the generic protocol header, the ApplicationError header and the payload.
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Build C++ variant representing the ApApplicationError
    std::string user_message{error_code.UserMessage().ToString()};
    amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct error_struct{error_code.Domain().Id(), error_code.Value(),
                                                              error_code.SupportData(),
                                                              user_message.c_str()};
    amsr::someip_protocol::internal::serialization::ApApplicationError ap_application_error{};
    ap_application_error.emplace<amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct>(error_struct);

    // Serialize the ApApplicationError
    someip_marshalling::ApApplicationErrorSerializer<
        amsr::ipc_binding::internal::ApplicationErrorMessageHeaderSerializerBase>
        serializer{logger_, std::move(packet), header};
    std::pair<ipc_protocol::IpcPacket, common_marshalling::SerializerStatus> serialization_result{
        serializer.Serialize(ap_application_error)};

    packet = std::move(serialization_result.first);
    serialization_status = serialization_result.second;
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }

  if (serialization_status == common_marshalling::SerializerStatus::kOk) {
    // Assemble the complete application error response message for transmission.
    ipc_protocol::LocalApplicationErrorMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteApplicationError(std::move(response_msg));
  } else if (serialization_status == common_marshalling::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{
        "Memory allocation for ApApplicationError response of method 'external_elements::laneSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization of ApApplicationError of method 'external_elements::laneSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

/* ---- /Field method 'laneSet' ------------------------------------------- */

/* ---- Field method 'objectGet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId
    external_elementsSkeletonIpcFieldManagerobjectGet::kMethodId;

/*!
 * \brief Context storage for the response path for method 'objectGet'.
 * An object of this type is assembled during the operator-call and is given to SendMethodResponse().
 */
class external_elementsIpcResponsePathInfoFieldManagerobjectGet final {
 public:
  /// Header from the request with client ID and session ID.
  const amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader& header_;
  /// Response type to be filled after processing.
  const apns::internal::fields::object::Output& out_val_;
};

/*!
 * \brief This functor is given to the frontend. Any functor (generic part) can
 * then be stored.
 */
class external_elementsSkeletonIpcFunctorobjectGet final : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param method_manager A pointer to the binding-related method manager for forwarding the response after processing the method request.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method.
   * \param header The IPC request header which must be stored for assembling the response (in case this method is not fire & forget).
   * \param remote_session_id Remote session id.
   */
  external_elementsSkeletonIpcFunctorobjectGet(external_elementsSkeletonIpcFieldManagerobjectGet* method_manager,
                                                   skeleton::external_elementsSkeleton* skeleton, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id,amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header) :
                                                   ::amsr::socal::internal::PendingRequest{skeleton}, method_manager_{method_manager}, skeleton_{skeleton}, header_{header}, remote_session_id_{remote_session_id} {}

  /*!
   * \brief Operator is being called when method invocation is scheduled in the frontend.
   */
  void operator()() override {
    
    // Call frontend skeleton implementation and wait until asynchronous result is provided
    ara::core::Result<apns::internal::fields::object::Output> const result{skeleton_->object.Get().GetResult()};
    if (result.HasValue()) {
      // Assemble the response path information within the binding.
      // That's necessary if the binding has additional info to transport as in the case for the IPC binding.
      external_elementsIpcResponsePathInfoFieldManagerobjectGet const response{header_, result.Value()};
      // Forward the result to the response path of the binding.
      method_manager_->SendMethodResponse(response, remote_session_id_);
    } else {
      method_manager_->SerializeAndSendApplicationErrorMethodResponse(header_, remote_session_id_, result.Error());
    }
  }

 private:
  /*!
   * \brief Binding-related interface to signalize a response right after the method
   * call.
   */
  external_elementsSkeletonIpcFieldManagerobjectGet* method_manager_;

  /*!
   * \brief Pointer to the skeleton to invoke the queue in the method request.
   */
  skeleton::external_elementsSkeleton* skeleton_;
  /*!
   * \brief Buffer the IPC request header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header_;

  /*!
   * \brief Remote session id.
   */
  const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id_;
};

external_elementsSkeletonIpcFieldManagerobjectGet::external_elementsSkeletonIpcFieldManagerobjectGet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept
: skeleton_binding_instance_{skeleton_binding_instance},
  logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "External_elementsProxyIpcMethodManagerobjectGet") {}


void external_elementsSkeletonIpcFieldManagerobjectGet::HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;


  // Buffer the request header for the response route.
  const ipc_protocol::RequestMessageHeader request_header{request.GetMessageHeader()};

  // Create a functor to save the context for being able to invoke the skeleton method request asynchronously.
  std::unique_ptr<external_elementsSkeletonIpcFunctorobjectGet> functor{
      vac::language::make_unique<external_elementsSkeletonIpcFunctorobjectGet>(
          this, &skeleton_binding_instance_.GetSkeleton()
          , request.GetRemoteSessionId(), request_header
  )};

  // Pass payload to skeleton that decides when to process the method call based on the processing-mode.
  // The response path is then called by the skeleton.
  skeleton_binding_instance_.GetSkeleton().HandleMethodRequest(std::move(functor));
}

void external_elementsSkeletonIpcFieldManagerobjectGet::SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerobjectGet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id) {
  // Get method request return value from output structure
  const apns::internal::fields::object::Output& out_val{response.out_val_};
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

             // Copy the information from the request to get the same client + session ID.
             ipc_protocol::ResponseMessageHeader header{response.header_};

  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::ResponseMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'out_val'
    // CppImplDataTypeStruct serialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/locationtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_out_val{&serializer};
  // CppImplDataTypeValue serialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_x{&serializer_out_val};
    serializer_out_val_x.PushBack(out_val.x);
    serializer_out_val_x.Close();
  }
  // CppImplDataTypeValue serialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_y{&serializer_out_val};
    serializer_out_val_y.PushBack(out_val.y);
    serializer_out_val_y.Close();
  }
  // CppImplDataTypeValue serialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_theta{&serializer_out_val};
    serializer_out_val_theta.PushBack(out_val.theta);
    serializer_out_val_theta.Close();
  }
  serializer_out_val.Close();
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
    // Assemble the complete response message for transmission.
    amsr::ipc_binding::internal::ipc_protocol::LocalResponseMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteResponse(std::move(response_msg));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for method 'external_elements::objectGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization for method 'external_elements::objectGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

void external_elementsSkeletonIpcFieldManagerobjectGet::SerializeAndSendApplicationErrorMethodResponse(
    amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
    amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
    ara::core::ErrorCode const& error_code) {
  logger_.LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};

  // Copy the information from the request to get the same client + session ID.
  ipc_protocol::ApplicationErrorMessageHeader header{};
  header.service_id_ = request_header.service_id_;
  header.instance_id_ = request_header.instance_id_;
  header.major_version_ = request_header.major_version_;
  header.method_id_ = request_header.method_id_;
  header.client_id_ = request_header.client_id_;
  header.session_id_ = request_header.session_id_;

  // Creation of a buffer to serialize the generic protocol header, the ApplicationError header and the payload.
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Build C++ variant representing the ApApplicationError
    std::string user_message{error_code.UserMessage().ToString()};
    amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct error_struct{error_code.Domain().Id(), error_code.Value(),
                                                              error_code.SupportData(),
                                                              user_message.c_str()};
    amsr::someip_protocol::internal::serialization::ApApplicationError ap_application_error{};
    ap_application_error.emplace<amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct>(error_struct);

    // Serialize the ApApplicationError
    someip_marshalling::ApApplicationErrorSerializer<
        amsr::ipc_binding::internal::ApplicationErrorMessageHeaderSerializerBase>
        serializer{logger_, std::move(packet), header};
    std::pair<ipc_protocol::IpcPacket, common_marshalling::SerializerStatus> serialization_result{
        serializer.Serialize(ap_application_error)};

    packet = std::move(serialization_result.first);
    serialization_status = serialization_result.second;
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }

  if (serialization_status == common_marshalling::SerializerStatus::kOk) {
    // Assemble the complete application error response message for transmission.
    ipc_protocol::LocalApplicationErrorMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteApplicationError(std::move(response_msg));
  } else if (serialization_status == common_marshalling::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{
        "Memory allocation for ApApplicationError response of method 'external_elements::objectGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization of ApApplicationError of method 'external_elements::objectGet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

/* ---- /Field method 'objectGet' ------------------------------------------- */

/* ---- Field method 'objectSet' ------------------------------------------- */

constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId
    external_elementsSkeletonIpcFieldManagerobjectSet::kMethodId;

/*!
 * \brief Context storage for the response path for method 'objectSet'.
 * An object of this type is assembled during the operator-call and is given to SendMethodResponse().
 */
class external_elementsIpcResponsePathInfoFieldManagerobjectSet final {
 public:
  /// Header from the request with client ID and session ID.
  const amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader& header_;
  /// Response type to be filled after processing.
  const apns::internal::fields::object::Output& out_val_;
};

/*!
 * \brief This functor is given to the frontend. Any functor (generic part) can
 * then be stored.
 */
class external_elementsSkeletonIpcFunctorobjectSet final : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param method_manager A pointer to the binding-related method manager for forwarding the response after processing the method request.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method.
   * \param header The IPC request header which must be stored for assembling the response (in case this method is not fire & forget).
   * \param in_val Create a snapshot of this method input argument for this functor.
   * \param remote_session_id Remote session id.
   */
  external_elementsSkeletonIpcFunctorobjectSet(external_elementsSkeletonIpcFieldManagerobjectSet* method_manager,
                                                   skeleton::external_elementsSkeleton* skeleton, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id,amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header,const apns::locationtype& arg_in_val) :
                                                   ::amsr::socal::internal::PendingRequest{skeleton}, method_manager_{method_manager}, skeleton_{skeleton}, header_{header}, remote_session_id_{remote_session_id}, arg_in_val_{arg_in_val} {}

  /*!
   * \brief Operator is being called when method invocation is scheduled in the frontend.
   */
  void operator()() override {
    apns::locationtype const& arg_in_val{arg_in_val_};
    
    // Call frontend skeleton implementation and wait until asynchronous result is provided
    ara::core::Result<apns::internal::fields::object::Output> const result{skeleton_->object.Set(arg_in_val).GetResult()};
    if (result.HasValue()) {
      // Assemble the response path information within the binding.
      // That's necessary if the binding has additional info to transport as in the case for the IPC binding.
      external_elementsIpcResponsePathInfoFieldManagerobjectSet const response{header_, result.Value()};
      // Forward the result to the response path of the binding.
      method_manager_->SendMethodResponse(response, remote_session_id_);
    } else {
      method_manager_->SerializeAndSendApplicationErrorMethodResponse(header_, remote_session_id_, result.Error());
    }
  }

 private:
  /*!
   * \brief Binding-related interface to signalize a response right after the method
   * call.
   */
  external_elementsSkeletonIpcFieldManagerobjectSet* method_manager_;

  /*!
   * \brief Pointer to the skeleton to invoke the queue in the method request.
   */
  skeleton::external_elementsSkeleton* skeleton_;
  /*!
   * \brief Buffer the IPC request header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader header_;

  /*!
   * \brief Remote session id.
   */
  const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id_;

  /*!
   * \brief Storing context of method argument 'in_val' in this functor for processing at any time.
   */
  const apns::locationtype arg_in_val_;
};

external_elementsSkeletonIpcFieldManagerobjectSet::external_elementsSkeletonIpcFieldManagerobjectSet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept
: skeleton_binding_instance_{skeleton_binding_instance},
  logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "External_elementsProxyIpcMethodManagerobjectSet") {}

/*!
 * \brief Deserializer for argument 'in_val' (AsrPath: /turtlesim/ServiceDesign/datatype/locationtype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class external_elementsobjectSetin_valDeserializer {
 public:
  /*!
   * \brief Constructor for external_elementsobjectSetin_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit external_elementsobjectSetin_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "external_elementsobjectSetin_valDeserializer") {}

/*!
 * \brief Deserialize argument 'in_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::locationtype, bool> Deserialize() {
  return Deserializein_val<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_x_type, bool> Deserializein_val_x(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'x'
    bool deserialization_ok{true};
  
  apns::locationtype::_x_type in_val_x{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val_x{parent};
  deserialization_ok &= deserializer__in_val_x.PopFront(in_val_x) > 0U;
    return std::make_pair(in_val_x, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_y_type, bool> Deserializein_val_y(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'y'
    bool deserialization_ok{true};
  
  apns::locationtype::_y_type in_val_y{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val_y{parent};
  deserialization_ok &= deserializer__in_val_y.PopFront(in_val_y) > 0U;
    return std::make_pair(in_val_y, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_theta_type, bool> Deserializein_val_theta(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'theta'
    bool deserialization_ok{true};
  
  apns::locationtype::_theta_type in_val_theta{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val_theta{parent};
  deserialization_ok &= deserializer__in_val_theta.PopFront(in_val_theta) > 0U;
    return std::make_pair(in_val_theta, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'in_val' (/turtlesim/ServiceDesign/datatype/locationtype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::locationtype, bool> Deserializein_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'in_val'
  bool deserialization_ok{true};

apns::locationtype in_val{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__in_val{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__in_val.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::locationtype::_x_type, bool> ret_x{Deserializein_val_x(&deserializer__in_val)};
  deserialization_ok &= ret_x.second;
  in_val.x = ret_x.first;
  const std::pair<apns::locationtype::_y_type, bool> ret_y{Deserializein_val_y(&deserializer__in_val)};
  deserialization_ok &= ret_y.second;
  in_val.y = ret_y.first;
  const std::pair<apns::locationtype::_theta_type, bool> ret_theta{Deserializein_val_theta(&deserializer__in_val)};
  deserialization_ok &= ret_theta.second;
  in_val.theta = ret_theta.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'in_val'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(in_val, deserialization_ok);
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



void external_elementsSkeletonIpcFieldManagerobjectSet::HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Overall deserialization result
  bool deserialization_ok{true};

  // Move the packet ownership to this scope for deserialization.
  ipc_protocol::IpcPacket packet{request.GetPacket()};

  // Create one root deserializer
  common_marshalling::Deserializer<ipc_marshalling::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};
  // Use the RequestMessageHeaderDeserializer to deserialize the protocol header and method request header.
  ipc_marshalling::RequestMessageHeaderDeserializer<ipc_marshalling::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};

  // Allocate input argument value(s) that shall be deserialized
  apns::locationtype arg_in_val{};

  // Deserialize the method parameter(s) from payload
  if(deserialization_ok) {
    // Deserialize argument 'in_val'
    external_elementsobjectSetin_valDeserializer<typename std::decay<decltype(deserializer)>::type> arg_in_val_deserializer{&deserializer};
std::pair<apns::locationtype, bool> ret_in_val{arg_in_val_deserializer.Deserialize()};
    // Get deserialized value and update overall deserialization result
    arg_in_val = ret_in_val.first;
    deserialization_ok &= ret_in_val.second;
  }

  // Buffer the request header for the response route.
  const ipc_protocol::RequestMessageHeader request_header{request.GetMessageHeader()};

  // Create a functor to save the context for being able to invoke the skeleton method request asynchronously.
  std::unique_ptr<external_elementsSkeletonIpcFunctorobjectSet> functor{
      vac::language::make_unique<external_elementsSkeletonIpcFunctorobjectSet>(
          this, &skeleton_binding_instance_.GetSkeleton()
          , request.GetRemoteSessionId(), request_header
    , arg_in_val
    )};

  // Pass payload to skeleton that decides when to process the method call based on the processing-mode.
  // The response path is then called by the skeleton.
  skeleton_binding_instance_.GetSkeleton().HandleMethodRequest(std::move(functor));
}

void external_elementsSkeletonIpcFieldManagerobjectSet::SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerobjectSet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id) {
  // Get method request return value from output structure
  const apns::internal::fields::object::Output& out_val{response.out_val_};
    namespace common_marshalling = ::amsr::com_common::internal::serialization;

  // Default SOME/IP marshalling namespace
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};
  // Shortening
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshalling = ipc_protocol::serialization;

             // Copy the information from the request to get the same client + session ID.
             ipc_protocol::ResponseMessageHeader header{response.header_};

  // Creation of a buffer to serialize the generic protocol header, the request header and the payload.
  // VECTOR Next Line AutosarC++17_10-A18.5.2: MD_ARACOM_AutosarC++17_10-A18.5.2_use_of_new
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  using DefaultSerializationPolicy = ipc_protocol::serialization::DefaultIpcPolicy;

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Create root serializer
    common_marshalling::Serializer<DefaultSerializationPolicy> serializer{std::move(packet)};

    // Serialize IPC header
    ipc_marshalling::ResponseMessageHeaderSerializer<DefaultSerializationPolicy, decltype(serializer)> header_serializer{&serializer, header};

    // Serialize argument 'out_val'
    // CppImplDataTypeStruct serialization for element 'out_val' (/turtlesim/ServiceDesign/datatype/locationtype)
{
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeSerializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer)> serializer_out_val{&serializer};
  // CppImplDataTypeValue serialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_x{&serializer_out_val};
    serializer_out_val_x.PushBack(out_val.x);
    serializer_out_val_x.Close();
  }
  // CppImplDataTypeValue serialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_y{&serializer_out_val};
    serializer_out_val_y.PushBack(out_val.y);
    serializer_out_val_y.Close();
  }
  // CppImplDataTypeValue serialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
  {
    ::amsr::com_common::internal::serialization::Serializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, decltype(serializer_out_val)> serializer_out_val_theta{&serializer_out_val};
    serializer_out_val_theta.PushBack(out_val.theta);
    serializer_out_val_theta.Close();
  }
  serializer_out_val.Close();
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
    // Assemble the complete response message for transmission.
    amsr::ipc_binding::internal::ipc_protocol::LocalResponseMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteResponse(std::move(response_msg));
  } else if (serialization_status == ::amsr::com_common::internal::serialization::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{"Memory allocation for method 'external_elements::objectSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization for method 'external_elements::objectSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

void external_elementsSkeletonIpcFieldManagerobjectSet::SerializeAndSendApplicationErrorMethodResponse(
    amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
    amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
    ara::core::ErrorCode const& error_code) {
  logger_.LogDebug([](ara::log::LogStream&) {}, __func__, __LINE__);

  // Shortening
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

  common_marshalling::SerializerStatus serialization_status{common_marshalling::SerializerStatus::kOk};

  // Copy the information from the request to get the same client + session ID.
  ipc_protocol::ApplicationErrorMessageHeader header{};
  header.service_id_ = request_header.service_id_;
  header.instance_id_ = request_header.instance_id_;
  header.major_version_ = request_header.major_version_;
  header.method_id_ = request_header.method_id_;
  header.client_id_ = request_header.client_id_;
  header.session_id_ = request_header.session_id_;

  // Creation of a buffer to serialize the generic protocol header, the ApplicationError header and the payload.
  ipc_protocol::IpcPacket packet{new ipc_protocol::PacketBuffer{}};

  // Successfully allocated memory for packet serialization?
  if (packet != nullptr) {
    // Build C++ variant representing the ApApplicationError
    std::string user_message{error_code.UserMessage().ToString()};
    amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct error_struct{error_code.Domain().Id(), error_code.Value(),
                                                              error_code.SupportData(),
                                                              user_message.c_str()};
    amsr::someip_protocol::internal::serialization::ApApplicationError ap_application_error{};
    ap_application_error.emplace<amsr::someip_protocol::internal::serialization::ApApplicationErrorStruct>(error_struct);

    // Serialize the ApApplicationError
    someip_marshalling::ApApplicationErrorSerializer<
        amsr::ipc_binding::internal::ApplicationErrorMessageHeaderSerializerBase>
        serializer{logger_, std::move(packet), header};
    std::pair<ipc_protocol::IpcPacket, common_marshalling::SerializerStatus> serialization_result{
        serializer.Serialize(ap_application_error)};

    packet = std::move(serialization_result.first);
    serialization_status = serialization_result.second;
  } else {
    serialization_status = common_marshalling::SerializerStatus::kBadAllocationException;
  }

  if (serialization_status == common_marshalling::SerializerStatus::kOk) {
    // Assemble the complete application error response message for transmission.
    ipc_protocol::LocalApplicationErrorMessage response_msg{header, std::move(packet), remote_session_id};
    skeleton_binding_instance_.RouteApplicationError(std::move(response_msg));
  } else if (serialization_status == common_marshalling::SerializerStatus::kBadAllocationException) {
    // Memory allocation failed.
    const char* error_msg{
        "Memory allocation for ApApplicationError response of method 'external_elements::objectSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::insufficient_memory, error_msg);
  } else {
    // During serialization an error occurred
    const char* error_msg{"Serialization of ApApplicationError of method 'external_elements::objectSet' failed."};
    logger_.LogError([&error_msg](ara::log::LogStream& s) { s << error_msg; }, __func__, __LINE__);
    throw ::ara::com::InternalComException(::ara::com::InternalComErrc::serialization_error, error_msg);
  }
}

/* ---- /Field method 'objectSet' ------------------------------------------- */


}  // namespace apns

