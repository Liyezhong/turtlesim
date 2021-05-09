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
/**        \file  rosap_exe/ipc-posix/apns/external_elements_proxy_ipc_methods.h
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_METHODS_H_
#define ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_METHODS_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <memory>
#include <sstream>
#include "apns/external_elements_types.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"
#include "ipc_binding/internal/ipc_protocol/message.h"
#include "ipc_binding/internal/methods/proxy_method_manager.h"
#include "ipc_binding/internal/methods/proxy_request_handler.h"
#include "ipc_binding/internal/methods/proxy_response_handler.h"

namespace apns {

// Forward-declaration for back-reference
class external_elementsRequiredIpcServiceInstance;

namespace ipc_binding {
namespace internal {


  namespace fields {

class laneGetErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit laneGetErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType error_code_value,
                                       ara::core::ErrorDomain::IdType error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType support_data,
                                       ara::core::ErrorDomain::StringType user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message{};
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:



  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief IPC Proxy method class for method 'laneGet'.
 * \details Handles IPC de-/serialization.
 * \remark generated
 */
class ProxylaneGet final
 : public amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::lane::Output>{
 public:
  /*!
   * \brief Type alias for the ProxyMethodManagerImplInterface.
   */
  using ProxyMethodManagerImplInterface = ProxylaneGet;

  /*!
   * \brief Type alias for the RequiredIpcServiceInstance.
   */
  using RequiredIpcServiceInstance = external_elementsRequiredIpcServiceInstance;

  /*!
   * \brief IPC method identifier for this method.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{1U};

  /*!
   * \brief Type alias for base class.
   */
  using Base = amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::lane::Output>;

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   */
  using ErrorCodeBuilder = laneGetErrorCodeBuilder;

  /*!
   * \brief Constructor sets a reference to the required service instance, for sending out
   * serialized packets.
   * \param proxy_binding Related required IPC service instance used.
   */
  explicit ProxylaneGet(RequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Serialization of service method 'laneGet'. If serialization is successful, the assembled request is transmitted to the corresponding IPC proxy instance.
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if the routing fails. 
   * \throws ::ara::com::InternalComException exception is set in the promise and then thrown when future.get() is called,
   * - if sufficient memory is not available (errc: insufficient_memory).
   * - if serialization has failed (errc: serialization_error).
   * \return ara::core::Future for return value of service method 'laneGet'
   * \trace SPEC-4980140
   * \trace SPEC-8053501
   */
  ara::core::Future<apns::internal::fields::lane::Output> HandleMethodRequest();

  /*!
   * \brief Deserialization of service method 'laneGet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response);

  /*!
   * \brief Handling of a request error replied for service method 'laneGet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  using Base::HandleMethodResponse;

  /*!
   * \brief Handling of an application error replied for service method 'laneGet'.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response);


 private:
  /*!
   * \brief Alias for IPC protocol session ID.
   */
  using SessionId = amsr::ipc_binding::internal::ipc_protocol::SessionId;


  /*!
   * \brief Deserialize response and set promise values in case a valid response with return code OK was received.
   * \tparam RootDeserializer Type of used root deserializer.
   * \param deserializer root deserializer with already consumed IPC protocol + message header.
   * \param session_id SessionId for the method response.
   */
  template <typename RootDeserializer>
  void HandleMethodResponseOk(RootDeserializer&& deserializer, SessionId const session_id);

  /*!
   * \brief To send method requests a link to the required service instance is used which provides a method for transmission.
   */
  RequiredIpcServiceInstance& ipc_proxy_instance_;
};

}  // namespace fields

  namespace fields {

class laneSetErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit laneSetErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType error_code_value,
                                       ara::core::ErrorDomain::IdType error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType support_data,
                                       ara::core::ErrorDomain::StringType user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message{};
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:



  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief IPC Proxy method class for method 'laneSet'.
 * \details Handles IPC de-/serialization.
 * \remark generated
 */
class ProxylaneSet final
 : public amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::lane::Output>{
 public:
  /*!
   * \brief Type alias for the ProxyMethodManagerImplInterface.
   */
  using ProxyMethodManagerImplInterface = ProxylaneSet;

  /*!
   * \brief Type alias for the RequiredIpcServiceInstance.
   */
  using RequiredIpcServiceInstance = external_elementsRequiredIpcServiceInstance;

  /*!
   * \brief IPC method identifier for this method.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{3U};

  /*!
   * \brief Type alias for base class.
   */
  using Base = amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::lane::Output>;

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   */
  using ErrorCodeBuilder = laneSetErrorCodeBuilder;

  /*!
   * \brief Constructor sets a reference to the required service instance, for sending out
   * serialized packets.
   * \param proxy_binding Related required IPC service instance used.
   */
  explicit ProxylaneSet(RequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Serialization of service method 'laneSet'. If serialization is successful, the assembled request is transmitted to the corresponding IPC proxy instance.
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if the routing fails. 
   * \throws ::ara::com::InternalComException exception is set in the promise and then thrown when future.get() is called,
   * - if sufficient memory is not available (errc: insufficient_memory).
   * - if serialization has failed (errc: serialization_error).
   * \param in_val Input argument of type apns::lanetype
   * \return ara::core::Future for return value of service method 'laneSet'
   * \trace SPEC-4980140
   * \trace SPEC-8053501
   */
  ara::core::Future<apns::internal::fields::lane::Output> HandleMethodRequest(const apns::lanetype& arg_in_val);

  /*!
   * \brief Deserialization of service method 'laneSet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response);

  /*!
   * \brief Handling of a request error replied for service method 'laneSet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  using Base::HandleMethodResponse;

  /*!
   * \brief Handling of an application error replied for service method 'laneSet'.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response);


 private:
  /*!
   * \brief Alias for IPC protocol session ID.
   */
  using SessionId = amsr::ipc_binding::internal::ipc_protocol::SessionId;


  /*!
   * \brief Deserialize response and set promise values in case a valid response with return code OK was received.
   * \tparam RootDeserializer Type of used root deserializer.
   * \param deserializer root deserializer with already consumed IPC protocol + message header.
   * \param session_id SessionId for the method response.
   */
  template <typename RootDeserializer>
  void HandleMethodResponseOk(RootDeserializer&& deserializer, SessionId const session_id);

  /*!
   * \brief To send method requests a link to the required service instance is used which provides a method for transmission.
   */
  RequiredIpcServiceInstance& ipc_proxy_instance_;
};

}  // namespace fields

  namespace fields {

class objectGetErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit objectGetErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType error_code_value,
                                       ara::core::ErrorDomain::IdType error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType support_data,
                                       ara::core::ErrorDomain::StringType user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message{};
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:



  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief IPC Proxy method class for method 'objectGet'.
 * \details Handles IPC de-/serialization.
 * \remark generated
 */
class ProxyobjectGet final
 : public amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::object::Output>{
 public:
  /*!
   * \brief Type alias for the ProxyMethodManagerImplInterface.
   */
  using ProxyMethodManagerImplInterface = ProxyobjectGet;

  /*!
   * \brief Type alias for the RequiredIpcServiceInstance.
   */
  using RequiredIpcServiceInstance = external_elementsRequiredIpcServiceInstance;

  /*!
   * \brief IPC method identifier for this method.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{4U};

  /*!
   * \brief Type alias for base class.
   */
  using Base = amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::object::Output>;

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   */
  using ErrorCodeBuilder = objectGetErrorCodeBuilder;

  /*!
   * \brief Constructor sets a reference to the required service instance, for sending out
   * serialized packets.
   * \param proxy_binding Related required IPC service instance used.
   */
  explicit ProxyobjectGet(RequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Serialization of service method 'objectGet'. If serialization is successful, the assembled request is transmitted to the corresponding IPC proxy instance.
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if the routing fails. 
   * \throws ::ara::com::InternalComException exception is set in the promise and then thrown when future.get() is called,
   * - if sufficient memory is not available (errc: insufficient_memory).
   * - if serialization has failed (errc: serialization_error).
   * \return ara::core::Future for return value of service method 'objectGet'
   * \trace SPEC-4980140
   * \trace SPEC-8053501
   */
  ara::core::Future<apns::internal::fields::object::Output> HandleMethodRequest();

  /*!
   * \brief Deserialization of service method 'objectGet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response);

  /*!
   * \brief Handling of a request error replied for service method 'objectGet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  using Base::HandleMethodResponse;

  /*!
   * \brief Handling of an application error replied for service method 'objectGet'.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response);


 private:
  /*!
   * \brief Alias for IPC protocol session ID.
   */
  using SessionId = amsr::ipc_binding::internal::ipc_protocol::SessionId;


  /*!
   * \brief Deserialize response and set promise values in case a valid response with return code OK was received.
   * \tparam RootDeserializer Type of used root deserializer.
   * \param deserializer root deserializer with already consumed IPC protocol + message header.
   * \param session_id SessionId for the method response.
   */
  template <typename RootDeserializer>
  void HandleMethodResponseOk(RootDeserializer&& deserializer, SessionId const session_id);

  /*!
   * \brief To send method requests a link to the required service instance is used which provides a method for transmission.
   */
  RequiredIpcServiceInstance& ipc_proxy_instance_;
};

}  // namespace fields

  namespace fields {

class objectSetErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit objectSetErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType error_code_value,
                                       ara::core::ErrorDomain::IdType error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType support_data,
                                       ara::core::ErrorDomain::StringType user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message{};
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:



  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief IPC Proxy method class for method 'objectSet'.
 * \details Handles IPC de-/serialization.
 * \remark generated
 */
class ProxyobjectSet final
 : public amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::object::Output>{
 public:
  /*!
   * \brief Type alias for the ProxyMethodManagerImplInterface.
   */
  using ProxyMethodManagerImplInterface = ProxyobjectSet;

  /*!
   * \brief Type alias for the RequiredIpcServiceInstance.
   */
  using RequiredIpcServiceInstance = external_elementsRequiredIpcServiceInstance;

  /*!
   * \brief IPC method identifier for this method.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{6U};

  /*!
   * \brief Type alias for base class.
   */
  using Base = amsr::ipc_binding::internal::methods::ProxyMethodManager<apns::internal::fields::object::Output>;

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   */
  using ErrorCodeBuilder = objectSetErrorCodeBuilder;

  /*!
   * \brief Constructor sets a reference to the required service instance, for sending out
   * serialized packets.
   * \param proxy_binding Related required IPC service instance used.
   */
  explicit ProxyobjectSet(RequiredIpcServiceInstance& proxy_binding);

  /*!
   * \brief Serialization of service method 'objectSet'. If serialization is successful, the assembled request is transmitted to the corresponding IPC proxy instance.
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if the routing fails. 
   * \throws ::ara::com::InternalComException exception is set in the promise and then thrown when future.get() is called,
   * - if sufficient memory is not available (errc: insufficient_memory).
   * - if serialization has failed (errc: serialization_error).
   * \param in_val Input argument of type apns::locationtype
   * \return ara::core::Future for return value of service method 'objectSet'
   * \trace SPEC-4980140
   * \trace SPEC-8053501
   */
  ara::core::Future<apns::internal::fields::object::Output> HandleMethodRequest(const apns::locationtype& arg_in_val);

  /*!
   * \brief Deserialization of service method 'objectSet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response);

  /*!
   * \brief Handling of a request error replied for service method 'objectSet'.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  using Base::HandleMethodResponse;

  /*!
   * \brief Handling of an application error replied for service method 'objectSet'.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   * \param response The response message forwarded to this MethodManager. This response message is going to be
   * deserialized.
   */
  void HandleMethodResponse(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response);


 private:
  /*!
   * \brief Alias for IPC protocol session ID.
   */
  using SessionId = amsr::ipc_binding::internal::ipc_protocol::SessionId;


  /*!
   * \brief Deserialize response and set promise values in case a valid response with return code OK was received.
   * \tparam RootDeserializer Type of used root deserializer.
   * \param deserializer root deserializer with already consumed IPC protocol + message header.
   * \param session_id SessionId for the method response.
   */
  template <typename RootDeserializer>
  void HandleMethodResponseOk(RootDeserializer&& deserializer, SessionId const session_id);

  /*!
   * \brief To send method requests a link to the required service instance is used which provides a method for transmission.
   */
  RequiredIpcServiceInstance& ipc_proxy_instance_;
};

}  // namespace fields

}  // namespace internal
}  // namespace ipc_binding
}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_PROXY_IPC_METHODS_H_

