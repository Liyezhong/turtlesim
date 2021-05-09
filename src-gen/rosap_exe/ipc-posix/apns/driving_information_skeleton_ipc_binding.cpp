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
/**        \file  rosap_exe/ipc-posix/apns/driving_information_skeleton_ipc_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'driving_information'
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
#include "apns/driving_information_skeleton_ipc_binding.h"
#include <utility>

namespace apns {

amsr::ipc_binding::internal::ForwardOutput driving_informationProvidedIpcServiceInstance::OnRequestReceived(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
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

amsr::ipc_binding::internal::ForwardOutput driving_informationProvidedIpcServiceInstance::OnRequestNoReturnReceived(amsr::ipc_binding::internal::ipc_protocol::RequestNoReturnMessage&& request) {
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

amsr::ipc_binding::internal::ForwardSubscribeEventOutput driving_informationProvidedIpcServiceInstance::OnSubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventMessageHeader const& subscribe_request) {
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> init_field{};
  amsr::ipc_binding::internal::ForwardOutput ack{true};

  /* Get event ID from header for dispatching to a concrete event manager. */
  const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{subscribe_request.event_id_};

  switch (event_id) {
    case driving_informationSkeletonIpcEventManagervehicle_speed::kEventId: {
      event_vehicle_speed_.HandleEventSubscription();
      break;
    }
    case driving_informationSkeletonIpcEventManagervehicle_position::kEventId: {
      event_vehicle_position_.HandleEventSubscription();
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

amsr::ipc_binding::internal::ForwardOutput driving_informationProvidedIpcServiceInstance::OnUnsubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::UnsubscribeEventMessageHeader const& unsubscribe_request) {
  (void) unsubscribe_request;
  return false;
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* Event 'vehicle_speed' */
void driving_informationProvidedIpcServiceInstance::SendEventvehicle_speed(const apns::speedtype& data) {
  event_vehicle_speed_.Send(data);
}

/* Event 'vehicle_position' */
void driving_informationProvidedIpcServiceInstance::SendEventvehicle_position(const apns::locationtype& data) {
  event_vehicle_position_.Send(data);
}

/* ---- Fields ----------------------------------------------------------------------------------------------------- */

}  // namespace apns

