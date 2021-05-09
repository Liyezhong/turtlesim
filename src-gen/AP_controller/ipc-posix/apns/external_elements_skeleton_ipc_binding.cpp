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
/**        \file  AP_controller/ipc-posix/apns/external_elements_skeleton_ipc_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'external_elements'
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
#include "apns/external_elements_skeleton_ipc_binding.h"
#include <utility>

namespace apns {

amsr::ipc_binding::internal::ForwardOutput external_elementsProvidedIpcServiceInstance::OnRequestReceived(amsr::ipc_binding::internal::ipc_protocol::RemoteRequestMessage&& request) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};

  /* Get method ID from header for dispatching to a concrete MethodManager. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{request.GetMessageHeader().method_id_};

  switch (method_id) {
    case external_elementsSkeletonIpcFieldManagerlaneGet::kMethodId: {
      field_lane_get_.HandleMethodRequest(std::move(request));
      break;
    }
    case external_elementsSkeletonIpcFieldManagerlaneSet::kMethodId: {
      field_lane_set_.HandleMethodRequest(std::move(request));
      break;
    }
    case external_elementsSkeletonIpcFieldManagerobjectGet::kMethodId: {
      field_object_get_.HandleMethodRequest(std::move(request));
      break;
    }
    case external_elementsSkeletonIpcFieldManagerobjectSet::kMethodId: {
      field_object_set_.HandleMethodRequest(std::move(request));
      break;
    }
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

amsr::ipc_binding::internal::ForwardOutput external_elementsProvidedIpcServiceInstance::OnRequestNoReturnReceived(amsr::ipc_binding::internal::ipc_protocol::RequestNoReturnMessage&& request) {
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

amsr::ipc_binding::internal::ForwardSubscribeEventOutput external_elementsProvidedIpcServiceInstance::OnSubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventMessageHeader const& subscribe_request) {
  ara::core::Optional<amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr> init_field{};
  amsr::ipc_binding::internal::ForwardOutput ack{true};

  /* Get event ID from header for dispatching to a concrete event manager. */
  const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{subscribe_request.event_id_};

  switch (event_id) {
    case external_elementsSkeletonIpcFieldNotifierlane::kEventId: {
      init_field = field_notifier_lane_.HandleEventSubscription();
      break;
    }
    case external_elementsSkeletonIpcFieldNotifierobject::kEventId: {
      init_field = field_notifier_object_.HandleEventSubscription();
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

amsr::ipc_binding::internal::ForwardOutput external_elementsProvidedIpcServiceInstance::OnUnsubscribeEventReceived(amsr::ipc_binding::internal::ipc_protocol::UnsubscribeEventMessageHeader const& unsubscribe_request) {
  (void) unsubscribe_request;
  return false;
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* ---- Fields ----------------------------------------------------------------------------------------------------- */
/* Field 'lane' */
void external_elementsProvidedIpcServiceInstance::UpdateFieldlane(const apns::lanetype& data) {
  field_notifier_lane_.Send(data);
}
/* Field 'object' */
void external_elementsProvidedIpcServiceInstance::UpdateFieldobject(const apns::locationtype& data) {
  field_notifier_object_.Send(data);
}

}  // namespace apns

