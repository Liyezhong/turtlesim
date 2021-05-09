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
/**        \file  AP_controller/ipc-posix/apns/driving_information_proxy_ipc_event_manager.cpp
 *        \brief  IPC proxy event handling for events and field notifications of service 'driving_information'
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
#include "apns/driving_information_proxy_ipc_event_manager.h"
#include <string>
#include <tuple>
#include <utility>
#include "apns/driving_information.h"
#include "apns/driving_information_proxy_ipc_binding.h"
#include "ipc_binding/internal/ipc_protocol/marshalling.h"

namespace apns {

/* ---- Event 'vehicle_speed' ------------------------------------------- */

driving_informationProxyIpcEventManagervehicle_speed::driving_informationProxyIpcEventManagervehicle_speed(
    driving_informationRequiredIpcServiceInstance& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "driving_informationProxyIpcEventManagervehicle_speed") {}

bool driving_informationProxyIpcEventManagervehicle_speed::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event.
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (service_event->GetSubscriptionState() == ::ara::com::SubscriptionState::kNotSubscribed) {
    service_event_ = service_event;
    service_event_->NotifySubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscriptionPending);
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    {
      // Shortening
      namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

      // Create Subscribe message header
      ipc_protocol::SubscribeEventMessageHeader subscribe_header{};
      subscribe_header.service_id_ = driving_informationRequiredIpcDeployment::kDeployment.service_id_;
      subscribe_header.instance_id_ = proxy_binding_.GetInstanceId();
      subscribe_header.major_version_ = driving_informationRequiredIpcDeployment::kDeployment.service_interface_version_.major_version_;
      subscribe_header.event_id_ = kEventId;
      subscribe_header.client_id_ = proxy_binding_.GetClientId();

      // Send SubscribeEventMessage
      is_subscription_successful = proxy_binding_.RouteSubscribeMessage(std::move(subscribe_header));
    }
  } else {
    logger_.LogWarn(
        [](ara::log::LogStream& s) {
          s << "driving_information: vehicle_speed is already subscribed. Subscription ignored."; },
          __func__, __LINE__);
  }
  return is_subscription_successful;
}

void driving_informationProxyIpcEventManagervehicle_speed::Unsubscribe() {
  if (service_event_ != nullptr) {
    if (service_event_->GetSubscriptionState() != ::ara::com::SubscriptionState::kNotSubscribed) {
      // Shortening
      namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

      // Create Unsubscribe message header
      ipc_protocol::UnsubscribeEventMessageHeader unsubscribe_header{};
      unsubscribe_header.service_id_ = driving_informationRequiredIpcDeployment::kDeployment.service_id_;
      unsubscribe_header.instance_id_ = proxy_binding_.GetInstanceId();
      unsubscribe_header.major_version_ = driving_informationRequiredIpcDeployment::kDeployment.service_interface_version_.major_version_;
      unsubscribe_header.event_id_ = kEventId;
      unsubscribe_header.client_id_ = proxy_binding_.GetClientId();

      // Send UnsubscribeEventMessage
      proxy_binding_.RouteUnsubscribeMessage(std::move(unsubscribe_header));
    }
    service_event_->NotifySubscriptionStateUpdate(::ara::com::SubscriptionState::kNotSubscribed);
  }
}

/*!
 * \brief Deserializer for argument 'data' (AsrPath: /turtlesim/ServiceDesign/datatype/speedtype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class driving_informationvehicle_speeddataDeserializer {
 public:
  /*!
   * \brief Constructor for driving_informationvehicle_speeddataDeserializer
   * \param deserializer Used root deserializer
   */
  explicit driving_informationvehicle_speeddataDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "driving_informationvehicle_speeddataDeserializer") {}

/*!
 * \brief Deserialize argument 'data'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::speedtype, bool> Deserialize() {
  return Deserializedata<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<double, bool> Deserializedata_l_vel(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'data'
    bool deserialization_ok{true};
  
  double data_l_vel{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data_data{parent};
  deserialization_ok &= deserializer__data_data.PopFront(data_l_vel) > 0U;
    return std::make_pair(data_l_vel, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<double, bool> Deserializedata_a_vel(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'data'
    bool deserialization_ok{true};
  
  double data_a_vel{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data_data{parent};
  deserialization_ok &= deserializer__data_data.PopFront(data_a_vel) > 0U;
    return std::make_pair(data_a_vel, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'data' (/turtlesim/ServiceDesign/datatype/speedtype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::speedtype, bool> Deserializedata(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

apns::speedtype data{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__data.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::speedtype::_l_vel_type, bool> ret_l_vel{Deserializedata_l_vel(&deserializer__data)};
  deserialization_ok &= ret_l_vel.second;
  data.l_vel = ret_l_vel.first;
  const std::pair<apns::speedtype::_a_vel_type, bool> ret_a_vel{Deserializedata_a_vel(&deserializer__data)};
  deserialization_ok &= ret_a_vel.second;
  data.a_vel = ret_a_vel.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'data'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(data, deserialization_ok);
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



void driving_informationProxyIpcEventManagervehicle_speed::HandleEventNotification(amsr::ipc_binding::internal::ipc_protocol::NotificationMessage& notification_msg) {
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  const ipc_protocol::NotificationMessageHeader& msg_header{notification_msg.GetMessageHeader()};
  logger_.LogDebug(
      [&msg_header](ara::log::LogStream& s) {
      s << "(0x" << ara::log::HexFormat(msg_header.service_id_) << ", 0x"
      << ara::log::HexFormat(msg_header.instance_id_) << ", 0x" << ara::log::HexFormat(msg_header.major_version_)
      << ", 0x" << ara::log::HexFormat(msg_header.event_id_) << ")";
      },
      __func__, __LINE__);
  // Start deserializing the sample only in case the subscription has been ACK -> kSubscribed.
  if (service_event_ && (service_event_->GetSubscriptionState() == ::ara::com::SubscriptionState::kSubscribed)) {
    amsr::ipc_binding::internal::ipc_protocol::IpcPacketShared packet{notification_msg.GetPacket()};

    // Create deserializer
    common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};
    ipc_marshaller::NotificationMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};
    const ipc_protocol::NotificationMessageHeader& deserialized_notification_header{header_deserializer.GetDeserializedHeader()};

    // Check for validity of event.
    if (deserialized_notification_header.event_id_ == kEventId) {
      // Deserialize event sample
    driving_informationvehicle_speeddataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<apns::speedtype, bool> ret_data{arg_data_deserializer.Deserialize()}; 

      // Deserialization successful?
      if (ret_data.second) {
        logger_.LogDebug(
            [](ara::log::LogStream& s) {
              s << "Received and deserialized sample for event 'vehicle_speed'."; },
              __func__, __LINE__);

        // Store data in invisible sample cache
        this->push(ret_data.first);

        // Notify about incoming event sample.
        service_event_->Notify();
      } else {
        logger_.LogError(
            [](ara::log::LogStream& s) {
              s << "Deserialization error occurred for event 'vehicle_speed'."; },
              __func__, __LINE__);
      }
    } else {
      logger_.LogError(
          [](ara::log::LogStream& s) {
            s << "Event id mismatch for event 'vehicle_speed'."; },
            __func__, __LINE__);
    }
  }
}

void driving_informationProxyIpcEventManagervehicle_speed::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (service_event_ != nullptr) {
    switch (service_event_->GetSubscriptionState()) {
      case ::ara::com::SubscriptionState::kNotSubscribed: {
        // If not subscribed, we don't care about any state change.
        break;
      }
      case ::ara::com::SubscriptionState::kSubscriptionPending: {

        // We are expecting a change, forward it.
        service_event_->NotifySubscriptionStateUpdate(state);
        break;
      }
      case ::ara::com::SubscriptionState::kSubscribed: {
        // If the skeleton is down, we might go to pending.
        if (state == ::ara::com::SubscriptionState::kSubscriptionPending) {
          service_event_->NotifySubscriptionStateUpdate(state);
        }
        break;
      }
      default: { break; }
    }
  }
}

/* ---- Event 'vehicle_position' ------------------------------------------- */

driving_informationProxyIpcEventManagervehicle_position::driving_informationProxyIpcEventManagervehicle_position(
    driving_informationRequiredIpcServiceInstance& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kIpcLoggerContextId, amsr::com_common::internal::logging::kIpcLoggerContextDescription,
              "driving_informationProxyIpcEventManagervehicle_position") {}

bool driving_informationProxyIpcEventManagervehicle_position::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event.
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (service_event->GetSubscriptionState() == ::ara::com::SubscriptionState::kNotSubscribed) {
    service_event_ = service_event;
    service_event_->NotifySubscriptionStateUpdate(::ara::com::SubscriptionState::kSubscriptionPending);
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    {
      // Shortening
      namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

      // Create Subscribe message header
      ipc_protocol::SubscribeEventMessageHeader subscribe_header{};
      subscribe_header.service_id_ = driving_informationRequiredIpcDeployment::kDeployment.service_id_;
      subscribe_header.instance_id_ = proxy_binding_.GetInstanceId();
      subscribe_header.major_version_ = driving_informationRequiredIpcDeployment::kDeployment.service_interface_version_.major_version_;
      subscribe_header.event_id_ = kEventId;
      subscribe_header.client_id_ = proxy_binding_.GetClientId();

      // Send SubscribeEventMessage
      is_subscription_successful = proxy_binding_.RouteSubscribeMessage(std::move(subscribe_header));
    }
  } else {
    logger_.LogWarn(
        [](ara::log::LogStream& s) {
          s << "driving_information: vehicle_position is already subscribed. Subscription ignored."; },
          __func__, __LINE__);
  }
  return is_subscription_successful;
}

void driving_informationProxyIpcEventManagervehicle_position::Unsubscribe() {
  if (service_event_ != nullptr) {
    if (service_event_->GetSubscriptionState() != ::ara::com::SubscriptionState::kNotSubscribed) {
      // Shortening
      namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;

      // Create Unsubscribe message header
      ipc_protocol::UnsubscribeEventMessageHeader unsubscribe_header{};
      unsubscribe_header.service_id_ = driving_informationRequiredIpcDeployment::kDeployment.service_id_;
      unsubscribe_header.instance_id_ = proxy_binding_.GetInstanceId();
      unsubscribe_header.major_version_ = driving_informationRequiredIpcDeployment::kDeployment.service_interface_version_.major_version_;
      unsubscribe_header.event_id_ = kEventId;
      unsubscribe_header.client_id_ = proxy_binding_.GetClientId();

      // Send UnsubscribeEventMessage
      proxy_binding_.RouteUnsubscribeMessage(std::move(unsubscribe_header));
    }
    service_event_->NotifySubscriptionStateUpdate(::ara::com::SubscriptionState::kNotSubscribed);
  }
}

/*!
 * \brief Deserializer for argument 'data' (AsrPath: /turtlesim/ServiceDesign/datatype/locationtype)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class driving_informationvehicle_positiondataDeserializer {
 public:
  /*!
   * \brief Constructor for driving_informationvehicle_positiondataDeserializer
   * \param deserializer Used root deserializer
   */
  explicit driving_informationvehicle_positiondataDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "driving_informationvehicle_positiondataDeserializer") {}

/*!
 * \brief Deserialize argument 'data'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<apns::locationtype, bool> Deserialize() {
  return Deserializedata<RootDeserializer>(deserializer_);
}

private:
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'x' (/turtlesim/ServiceDesign/datatype/locationtype/x)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_x_type, bool> Deserializedata_x(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'x'
    bool deserialization_ok{true};
  
  apns::locationtype::_x_type data_x{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data_x{parent};
  deserialization_ok &= deserializer__data_x.PopFront(data_x) > 0U;
    return std::make_pair(data_x, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'y' (/turtlesim/ServiceDesign/datatype/locationtype/y)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_y_type, bool> Deserializedata_y(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'y'
    bool deserialization_ok{true};
  
  apns::locationtype::_y_type data_y{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data_y{parent};
  deserialization_ok &= deserializer__data_y.PopFront(data_y) > 0U;
    return std::make_pair(data_y, deserialization_ok);
  }
  
  /*!
   * \brief CppImplDataTypeValue deserialization for element 'theta' (/turtlesim/ServiceDesign/datatype/locationtype/theta)
   * \tparam ParentDeserializer Type of parent deserializer
   * \param parent Used parent deserializer
   */
  template <typename ParentDeserializer>
  std::pair<apns::locationtype::_theta_type, bool> Deserializedata_theta(ParentDeserializer* parent) {
    namespace common_marshalling = ::amsr::com_common::internal::serialization;
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
    namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;
  
    // Deserialization result of element 'theta'
    bool deserialization_ok{true};
  
  apns::locationtype::_theta_type data_theta{};
    ::amsr::com_common::internal::serialization::Deserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data_theta{parent};
  deserialization_ok &= deserializer__data_theta.PopFront(data_theta) > 0U;
    return std::make_pair(data_theta, deserialization_ok);
  }
  
/*!
 * \brief CppImplDataTypeStruct deserialization for element 'data' (/turtlesim/ServiceDesign/datatype/locationtype)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<apns::locationtype, bool> Deserializedata(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;
  namespace ipc_marshalling = amsr::ipc_binding::internal::ipc_protocol::serialization;

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

apns::locationtype data{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<ipc_marshalling::DefaultIpcPayloadUint32LengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
  const ::amsr::someip_protocol::internal::serialization::LengthFieldInfo length_field{deserializer__data.GetLengthFieldValue()};
  if (length_field.status_ == ::amsr::someip_protocol::internal::serialization::LengthFieldStatus::kOk) {
  const std::pair<apns::locationtype::_x_type, bool> ret_x{Deserializedata_x(&deserializer__data)};
  deserialization_ok &= ret_x.second;
  data.x = ret_x.first;
  const std::pair<apns::locationtype::_y_type, bool> ret_y{Deserializedata_y(&deserializer__data)};
  deserialization_ok &= ret_y.second;
  data.y = ret_y.first;
  const std::pair<apns::locationtype::_theta_type, bool> ret_theta{Deserializedata_theta(&deserializer__data)};
  deserialization_ok &= ret_theta.second;
  data.theta = ret_theta.first;
} else {
  logger_.LogError([](ara::log::LogStream& s) {
  s << "Deserialization error: Invalid length field detected in byte stream of method argument 'data'. Cancelling deserialization.";}, __func__, __LINE__);
  deserialization_ok = false;
}
  return std::make_pair(data, deserialization_ok);
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



void driving_informationProxyIpcEventManagervehicle_position::HandleEventNotification(amsr::ipc_binding::internal::ipc_protocol::NotificationMessage& notification_msg) {
  namespace ipc_protocol = amsr::ipc_binding::internal::ipc_protocol;
  namespace ipc_marshaller = ipc_protocol::serialization;
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  const ipc_protocol::NotificationMessageHeader& msg_header{notification_msg.GetMessageHeader()};
  logger_.LogDebug(
      [&msg_header](ara::log::LogStream& s) {
      s << "(0x" << ara::log::HexFormat(msg_header.service_id_) << ", 0x"
      << ara::log::HexFormat(msg_header.instance_id_) << ", 0x" << ara::log::HexFormat(msg_header.major_version_)
      << ", 0x" << ara::log::HexFormat(msg_header.event_id_) << ")";
      },
      __func__, __LINE__);
  // Start deserializing the sample only in case the subscription has been ACK -> kSubscribed.
  if (service_event_ && (service_event_->GetSubscriptionState() == ::ara::com::SubscriptionState::kSubscribed)) {
    amsr::ipc_binding::internal::ipc_protocol::IpcPacketShared packet{notification_msg.GetPacket()};

    // Create deserializer
    common_marshalling::Deserializer<ipc_marshaller::DefaultIpcPolicy> deserializer{common_marshalling::PacketBufferView{common_marshalling::PacketBufferView{*packet}}};
    ipc_marshaller::NotificationMessageHeaderDeserializer<ipc_marshaller::DefaultIpcPolicy, decltype(deserializer)> header_deserializer{&deserializer};
    const ipc_protocol::NotificationMessageHeader& deserialized_notification_header{header_deserializer.GetDeserializedHeader()};

    // Check for validity of event.
    if (deserialized_notification_header.event_id_ == kEventId) {
      // Deserialize event sample
    driving_informationvehicle_positiondataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<apns::locationtype, bool> ret_data{arg_data_deserializer.Deserialize()}; 

      // Deserialization successful?
      if (ret_data.second) {
        logger_.LogDebug(
            [](ara::log::LogStream& s) {
              s << "Received and deserialized sample for event 'vehicle_position'."; },
              __func__, __LINE__);

        // Store data in invisible sample cache
        this->push(ret_data.first);

        // Notify about incoming event sample.
        service_event_->Notify();
      } else {
        logger_.LogError(
            [](ara::log::LogStream& s) {
              s << "Deserialization error occurred for event 'vehicle_position'."; },
              __func__, __LINE__);
      }
    } else {
      logger_.LogError(
          [](ara::log::LogStream& s) {
            s << "Event id mismatch for event 'vehicle_position'."; },
            __func__, __LINE__);
    }
  }
}

void driving_informationProxyIpcEventManagervehicle_position::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (service_event_ != nullptr) {
    switch (service_event_->GetSubscriptionState()) {
      case ::ara::com::SubscriptionState::kNotSubscribed: {
        // If not subscribed, we don't care about any state change.
        break;
      }
      case ::ara::com::SubscriptionState::kSubscriptionPending: {

        // We are expecting a change, forward it.
        service_event_->NotifySubscriptionStateUpdate(state);
        break;
      }
      case ::ara::com::SubscriptionState::kSubscribed: {
        // If the skeleton is down, we might go to pending.
        if (state == ::ara::com::SubscriptionState::kSubscriptionPending) {
          service_event_->NotifySubscriptionStateUpdate(state);
        }
        break;
      }
      default: { break; }
    }
  }
}


}  // namespace apns

