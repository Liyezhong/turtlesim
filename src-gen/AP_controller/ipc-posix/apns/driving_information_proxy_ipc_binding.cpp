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
/**        \file  AP_controller/ipc-posix/apns/driving_information_proxy_ipc_binding.cpp
 *        \brief  Frame for IPC binding service instance class of service 'driving_information'
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
#include "apns/driving_information_proxy_ipc_binding.h"
#include <utility>

namespace apns {

amsr::ipc_binding::internal::ForwardOutput driving_informationRequiredIpcServiceInstance::OnResponseReceived(amsr::ipc_binding::internal::ipc_protocol::ResponseMessage&& response) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};
  /* Get method ID from response header for dispatching. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{response.GetMessageHeader().method_id_};

  /* Based on the method id -> dispatching to a concrete MethodManager based on method id -> deserialization. */
  switch (method_id) {
    default: {
      forwarded = false;
      break;
    }
  }

  return forwarded;
}

amsr::ipc_binding::internal::ForwardOutput driving_informationRequiredIpcServiceInstance::OnNotificationReceived(amsr::ipc_binding::internal::ipc_protocol::NotificationMessagePtr notification) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};
  /* Get method ID from reponse header for dispatching. */
  const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{notification->GetMessageHeader().event_id_};

  /* Based on the event id -> dispatching to the EventManager -> deserialization. */
  switch (event_id) {
    case driving_informationProxyIpcEventManagervehicle_speed::kEventId: {
      event_vehicle_speed_.HandleEventNotification(*notification);
      break;
    }
    case driving_informationProxyIpcEventManagervehicle_position::kEventId: {
      event_vehicle_position_.HandleEventNotification(*notification);
      break;
    }
    default: {
      forwarded = false;
      break;
    }
  }

  return forwarded;
}

void driving_informationRequiredIpcServiceInstance::OnServiceInstanceDown() {

        event_vehicle_speed_.HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscriptionPending);
        event_vehicle_position_.HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscriptionPending);
}

amsr::ipc_binding::internal::ForwardOutput driving_informationRequiredIpcServiceInstance::OnSubscribeAckReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventAckMessageHeader const& ack_response_header) {
  amsr::ipc_binding::internal::ForwardOutput accepted{true};

  /* Filter by client id */
  const amsr::ipc_binding::internal::ipc_protocol::ClientId client_id{ack_response_header.client_id_};
  if (client_id == GetClientId()) {
    /* Get event ID from reponse header for dispatching. */
    const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{ack_response_header.event_id_};

    /* Based on the event id -> dispatching to the EventManager -> update the subscription state. */
    switch (event_id) {
      case driving_informationProxyIpcEventManagervehicle_speed::kEventId: {
        event_vehicle_speed_.HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscribed);
        break;
      }
      case driving_informationProxyIpcEventManagervehicle_position::kEventId: {
        event_vehicle_position_.HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscribed);
        break;
      }
      default: {
        accepted = false;
        break;
      }
    }
  } else {
    accepted = false;
  }

  return accepted;
}

amsr::ipc_binding::internal::ForwardOutput driving_informationRequiredIpcServiceInstance::OnSubscribeNAckReceived(amsr::ipc_binding::internal::ipc_protocol::SubscribeEventNAckMessageHeader const& nack_response_header) {
  amsr::ipc_binding::internal::ForwardOutput accepted{true};

  /* Filter by client id */
  const amsr::ipc_binding::internal::ipc_protocol::ClientId client_id{nack_response_header.client_id_};
  if ((client_id == GetClientId()) || (client_id == 0U)) {
    /* Client id 0 is used for broadcasting that the skeleton is not anymore available. */
    ::ara::com::SubscriptionState new_state = (client_id == 0U) ? ::ara::com::SubscriptionState::kSubscriptionPending
                                                              : ::ara::com::SubscriptionState::kNotSubscribed;
    /* Get event ID from reponse header for dispatching. */
    const amsr::ipc_binding::internal::ipc_protocol::EventId event_id{nack_response_header.event_id_};

    /* Based on the event id -> dispatching to the EventManager -> update the subscription state. */
    switch (event_id) {
      case driving_informationProxyIpcEventManagervehicle_speed::kEventId: {
        event_vehicle_speed_.HandleEventSubscriptionStateUpdate(new_state);
        break;
      }
      case driving_informationProxyIpcEventManagervehicle_position::kEventId: {
        event_vehicle_position_.HandleEventSubscriptionStateUpdate(new_state);
        break;
      }
      default: {
        (void)new_state;
        accepted = false;
        break;
      }
    }
  } else {
    accepted = false;
  }

  return accepted;
}

amsr::ipc_binding::internal::ForwardOutput driving_informationRequiredIpcServiceInstance::OnApplicationErrorReceived(amsr::ipc_binding::internal::ipc_protocol::ApplicationErrorMessage&& response) {
  amsr::ipc_binding::internal::ForwardOutput forwarded{true};
  /* Get method ID from response header for dispatching. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{response.GetMessageHeader().method_id_};

  /* Based on the method id -> dispatching to a concrete MethodManager based on method id -> deserialization. */
  switch (method_id) {
    default: {
      forwarded = false;
      break;
    }
  }

  return forwarded;
}

void driving_informationRequiredIpcServiceInstance::OnErrorResponseReceived(amsr::ipc_binding::internal::ipc_protocol::ErrorResponseMessage&& response) {
  /* Get method ID from response header for dispatching. */
  const amsr::ipc_binding::internal::ipc_protocol::MethodId method_id{response.GetMessageHeader().method_id_};

  /* Based on the method id -> dispatching to a concrete MethodManager based on method id -> deserialization. */
  switch (method_id) {
    default: {
      break;
    }
  }
}

}  // namespace apns

