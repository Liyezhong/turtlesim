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
/**        \file  AP_controller/ipc-posix/apns/external_elements_skeleton_ipc_method_manager.h
 *        \brief  SOME/IP skeleton method de- /serialization handling for methods and field methods of service 'external_elements'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_METHOD_MANAGER_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_METHOD_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <mutex>
#include "ara/core/error_code.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "ipc_binding/internal/ipc_protocol/message.h"

namespace apns {

// Forward declaration to avoid include.
class external_elementsProvidedIpcServiceInstance;

// Forward declaration avoid include.
class external_elementsIpcResponsePathInfoFieldManagerlaneGet;

/*!
 * \brief IPC Skeleton method manager for method 'laneGet'.
 * \details Handles IPC de-/serialization + request / response forwarding.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldManagerlaneGet final {
 public:
  /*!
   * \brief Ctor sets the reference to the provided IPC service instance to send out method responses.
   *
   * \param skeleton_binding_instance A reference to the provided IPC service instance.
   */
  explicit external_elementsSkeletonIpcFieldManagerlaneGet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept;

  /*!
   * \brief IPC method identifier for the method 'laneGet'. This attribute is used for
   * dispatching in the provided IPC service instances.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{1U};

  /*!
   * \brief Deserialization of service method 'laneGet'.
   * \details Stores the request into the map and calls the frontend.
   *
   * \param request Incoming method request to be deserialized and processed.
   */
  void HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request);

  /*!
   * \brief Send out a method response, after the method has been processed by the skeleton frontend.
   *
   * \param response This structure holds information from the request (IPC header info) for the response.
   * \param remote_session_id Remote session id
   */
  void SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerlaneGet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id);

  /*!
   * \brief Serialize and send an ApplicationError method response in case the skeleton implementation returned an error.
   *
   * \param request_header Header from the request including client ID and session ID.
   * \param remote_session_id Remote session id
   * \param error_code Error code returned by the skeleton implementation.
   */
  void SerializeAndSendApplicationErrorMethodResponse(
      amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
      amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
      ara::core::ErrorCode const& error_code);

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

 private:
  /** Reference to send method responses */
  external_elementsProvidedIpcServiceInstance& skeleton_binding_instance_;

  /** Mutex for method requests from multiple threads */
  std::mutex pending_lock_;

  /** Logger for tracing and debugging. */
  amsr::com_common::internal::logging::AraComLogger logger_;
};
// Forward declaration avoid include.
class external_elementsIpcResponsePathInfoFieldManagerlaneSet;

/*!
 * \brief IPC Skeleton method manager for method 'laneSet'.
 * \details Handles IPC de-/serialization + request / response forwarding.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldManagerlaneSet final {
 public:
  /*!
   * \brief Ctor sets the reference to the provided IPC service instance to send out method responses.
   *
   * \param skeleton_binding_instance A reference to the provided IPC service instance.
   */
  explicit external_elementsSkeletonIpcFieldManagerlaneSet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept;

  /*!
   * \brief IPC method identifier for the method 'laneSet'. This attribute is used for
   * dispatching in the provided IPC service instances.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{3U};

  /*!
   * \brief Deserialization of service method 'laneSet'.
   * \details Stores the request into the map and calls the frontend.
   *
   * \param request Incoming method request to be deserialized and processed.
   */
  void HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request);

  /*!
   * \brief Send out a method response, after the method has been processed by the skeleton frontend.
   *
   * \param response This structure holds information from the request (IPC header info) for the response.
   * \param remote_session_id Remote session id
   */
  void SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerlaneSet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id);

  /*!
   * \brief Serialize and send an ApplicationError method response in case the skeleton implementation returned an error.
   *
   * \param request_header Header from the request including client ID and session ID.
   * \param remote_session_id Remote session id
   * \param error_code Error code returned by the skeleton implementation.
   */
  void SerializeAndSendApplicationErrorMethodResponse(
      amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
      amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
      ara::core::ErrorCode const& error_code);

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

 private:
  /** Reference to send method responses */
  external_elementsProvidedIpcServiceInstance& skeleton_binding_instance_;

  /** Mutex for method requests from multiple threads */
  std::mutex pending_lock_;

  /** Logger for tracing and debugging. */
  amsr::com_common::internal::logging::AraComLogger logger_;
};
// Forward declaration avoid include.
class external_elementsIpcResponsePathInfoFieldManagerobjectGet;

/*!
 * \brief IPC Skeleton method manager for method 'objectGet'.
 * \details Handles IPC de-/serialization + request / response forwarding.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldManagerobjectGet final {
 public:
  /*!
   * \brief Ctor sets the reference to the provided IPC service instance to send out method responses.
   *
   * \param skeleton_binding_instance A reference to the provided IPC service instance.
   */
  explicit external_elementsSkeletonIpcFieldManagerobjectGet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept;

  /*!
   * \brief IPC method identifier for the method 'objectGet'. This attribute is used for
   * dispatching in the provided IPC service instances.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{4U};

  /*!
   * \brief Deserialization of service method 'objectGet'.
   * \details Stores the request into the map and calls the frontend.
   *
   * \param request Incoming method request to be deserialized and processed.
   */
  void HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request);

  /*!
   * \brief Send out a method response, after the method has been processed by the skeleton frontend.
   *
   * \param response This structure holds information from the request (IPC header info) for the response.
   * \param remote_session_id Remote session id
   */
  void SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerobjectGet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id);

  /*!
   * \brief Serialize and send an ApplicationError method response in case the skeleton implementation returned an error.
   *
   * \param request_header Header from the request including client ID and session ID.
   * \param remote_session_id Remote session id
   * \param error_code Error code returned by the skeleton implementation.
   */
  void SerializeAndSendApplicationErrorMethodResponse(
      amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
      amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
      ara::core::ErrorCode const& error_code);

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

 private:
  /** Reference to send method responses */
  external_elementsProvidedIpcServiceInstance& skeleton_binding_instance_;

  /** Mutex for method requests from multiple threads */
  std::mutex pending_lock_;

  /** Logger for tracing and debugging. */
  amsr::com_common::internal::logging::AraComLogger logger_;
};
// Forward declaration avoid include.
class external_elementsIpcResponsePathInfoFieldManagerobjectSet;

/*!
 * \brief IPC Skeleton method manager for method 'objectSet'.
 * \details Handles IPC de-/serialization + request / response forwarding.
 * \remark generated
 */
class external_elementsSkeletonIpcFieldManagerobjectSet final {
 public:
  /*!
   * \brief Ctor sets the reference to the provided IPC service instance to send out method responses.
   *
   * \param skeleton_binding_instance A reference to the provided IPC service instance.
   */
  explicit external_elementsSkeletonIpcFieldManagerobjectSet(external_elementsProvidedIpcServiceInstance& skeleton_binding_instance) noexcept;

  /*!
   * \brief IPC method identifier for the method 'objectSet'. This attribute is used for
   * dispatching in the provided IPC service instances.
   */
  static constexpr amsr::ipc_binding::internal::ipc_protocol::MethodId kMethodId{6U};

  /*!
   * \brief Deserialization of service method 'objectSet'.
   * \details Stores the request into the map and calls the frontend.
   *
   * \param request Incoming method request to be deserialized and processed.
   */
  void HandleMethodRequest(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request);

  /*!
   * \brief Send out a method response, after the method has been processed by the skeleton frontend.
   *
   * \param response This structure holds information from the request (IPC header info) for the response.
   * \param remote_session_id Remote session id
   */
  void SendMethodResponse(const external_elementsIpcResponsePathInfoFieldManagerobjectSet& response, const amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId remote_session_id);

  /*!
   * \brief Serialize and send an ApplicationError method response in case the skeleton implementation returned an error.
   *
   * \param request_header Header from the request including client ID and session ID.
   * \param remote_session_id Remote session id
   * \param error_code Error code returned by the skeleton implementation.
   */
  void SerializeAndSendApplicationErrorMethodResponse(
      amsr::ipc_binding::internal::ipc_protocol::RequestMessageHeader const& request_header,
      amsr::ipc_binding::internal::ipc_protocol::RemoteSessionId const remote_session_id,
      ara::core::ErrorCode const& error_code);

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

 private:
  /** Reference to send method responses */
  external_elementsProvidedIpcServiceInstance& skeleton_binding_instance_;

  /** Mutex for method requests from multiple threads */
  std::mutex pending_lock_;

  /** Logger for tracing and debugging. */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_SKELETON_IPC_METHOD_MANAGER_H_

