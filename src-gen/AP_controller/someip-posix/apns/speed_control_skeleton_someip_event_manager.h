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
/**        \file  AP_controller/someip-posix/apns/speed_control_skeleton_someip_event_manager.h
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

#ifndef AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_EVENT_MANAGER_H_
#define AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include "apns/speed_control_common.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "socal/internal/session_handler.h"
#include "someip-protocol/internal/marshalling.h"
#include "someip_binding/internal/e2e_marshalling.h"

namespace apns {
namespace someip_binding {
namespace internal {

// Forward-declaration for back-reference
class speed_controlSkeletonSomeIpBinding;

/* ---- Event 'LKA_speed' ------------------------------------------- */
/*!
 * \brief SOME/IP Skeleton event manager for event 'LKA_speed'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class speed_controlSkeletonSomeIpEventManagerLKA_speed final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related SOME/IP skeleton binding to be used
   * \param tx_buffer_allocator Reference to memory buffer allocator for packet transmission
   */
  speed_controlSkeletonSomeIpEventManagerLKA_speed(
      speed_controlSkeletonSomeIpBinding& skeleton_binding,
      amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator);

  /*!
   * \brief Send a event sample of skeleton event 'LKA_speed'.
   *
   * \param data Event sample of type speedtype
   *
   * \throws ::ara::com::InternalComException If serialization has failed (errc: serialization_error).
   * \trace SPEC-4981292, SPEC-4980077
   */
  void Send(const apns::speedtype& data);

 private:

  /*!
   * \brief Returns a reference to the session handler.
   *
   * \pre -
   * \threadsafe TRUE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \return reference to the session handler.
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& GetSessionHandler() noexcept { return session_; }

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Skeleton binding for event transmission
   */
  speed_controlSkeletonSomeIpBinding& skeleton_binding_;

  /*!
   * \brief Reference to buffer allocator for packet transmission
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId> session_;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

/* ---- Event 'ToGoal_speed' ------------------------------------------- */
/*!
 * \brief SOME/IP Skeleton event manager for event 'ToGoal_speed'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class speed_controlSkeletonSomeIpEventManagerToGoal_speed final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related SOME/IP skeleton binding to be used
   * \param tx_buffer_allocator Reference to memory buffer allocator for packet transmission
   */
  speed_controlSkeletonSomeIpEventManagerToGoal_speed(
      speed_controlSkeletonSomeIpBinding& skeleton_binding,
      amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator);

  /*!
   * \brief Send a event sample of skeleton event 'ToGoal_speed'.
   *
   * \param data Event sample of type speedtype
   *
   * \throws ::ara::com::InternalComException If serialization has failed (errc: serialization_error).
   * \trace SPEC-4981292, SPEC-4980077
   */
  void Send(const apns::speedtype& data);

 private:

  /*!
   * \brief Returns a reference to the session handler.
   *
   * \pre -
   * \threadsafe TRUE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \return reference to the session handler.
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& GetSessionHandler() noexcept { return session_; }

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Skeleton binding for event transmission
   */
  speed_controlSkeletonSomeIpBinding& skeleton_binding_;

  /*!
   * \brief Reference to buffer allocator for packet transmission
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId> session_;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SKELETON_SOMEIP_EVENT_MANAGER_H_

