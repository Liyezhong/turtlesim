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
/**        \file  rosap_exe/ipc-posix/apns/speed_control_skeleton_ipc_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'speed_control'
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
#include "apns/speed_control_skeleton_ipc_binding.h"
#include <utility>

namespace apns {

amsr::ipc_binding::internal::ForwardOutput speed_controlProvidedIpcServiceInstance::OnRequestReceived(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};

  /* Get method ID from header for dispatching to a concrete MethodManager. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{request.GetMessageHeader().method_id_};

  switch (method_id) {
    default: {
      /*
       * Method implementation is missing.
       * Send an error response if it's no fire & forget method.
       */
      forwarded = false;
      break;
    }
  }

  return forwarded;
}

amsr::ipc_binding::internal::ForwardOutput speed_controlProvidedIpcServiceInstance::OnRequestNoReturnReceived(amsr::ipc_binding::internal::ipc_protocol::RequestNoReturnMessage&& request) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};

  /* Get method ID from header for dispatching to a concrete method manager. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{request.GetMessageHeader().method_id_};

  switch (method_id) {
    default: {
      /*
       * Method implementation is missing.
       * No error response is sent for fire & forget methods.
       */
      forwarded = false;
      break;
    }
  }

  return forwarded;
}

amsr::ipc_binding::internal::ForwardSubscribeEventOutput speed_controlProvidedIpcServiceInstance::OnSubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventMessageHeader const& subscribe_request) {
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> init_field{};
  amsr::ipc_binding::internal::ForwardOutput ack{true};

  /* Get event ID from header for dispatching to a concrete event manager. */
  const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{subscribe_request.event_id_};

  switch (event_id) {
    case speed_controlSkeletonIpcEventManagerLKA_speed::kEventId: {
      event_LKA_speed_.HandleEventSubscription();
      break;
    }
    case speed_controlSkeletonIpcEventManagerToGoal_speed::kEventId: {
      event_ToGoal_speed_.HandleEventSubscription();
      break;
    }
    default: {
      /* Event implementation is missing. */
      ack = false;
      break;
    }
  }

  return {ack, init_field};
}

amsr::ipc_binding::internal::ForwardOutput speed_controlProvidedIpcServiceInstance::OnUnsubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::UnsubscribeEventMessageHeader const& unsubscribe_request) {
  (void) unsubscribe_request;
  return false;
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* Event 'LKA_speed' */
void speed_controlProvidedIpcServiceInstance::SendEventLKA_speed(const apns::speedtype& data) {
  event_LKA_speed_.Send(data);
}

/* Event 'ToGoal_speed' */
void speed_controlProvidedIpcServiceInstance::SendEventToGoal_speed(const apns::speedtype& data) {
  event_ToGoal_speed_.Send(data);
}

/* ---- Fields ----------------------------------------------------------------------------------------------------- */

}  // namespace apns

