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
/**        \file  AP_controller/someip-posix/apns/driving_information_proxy_someip_event_manager.cpp
 *        \brief  SOME/IP proxy event handling for events and field notifications of service 'driving_information'
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_proxy_someip_event_manager.h"
#include <string>
#include <tuple>
#include <utility>
#include "apns/driving_information.h"
#include "apns/driving_information_proxy_someip_binding.h"

namespace apns {
namespace someip_binding {
namespace internal {

/* ---- Event 'vehicle_speed' ------------------------------------------- */

driving_informationProxySomeIpEventManagervehicle_speed::driving_informationProxySomeIpEventManagervehicle_speed(
    driving_informationProxySomeIpBinding& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "driving_informationProxySomeIpEventManagervehicle_speed") {}

bool driving_informationProxySomeIpEventManagervehicle_speed::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event. (This is passed by ara::com, so it is ok to assert its correctness)
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (!subscribed_) {
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    service_event_ = service_event;
    // set subscribed_ to true before calling SubscribeEvent, as HandleEventSubscriptionStateUpdate might then be called
    // at any moment even before SubscribeEvent is returned.
    subscribed_ = true;
    proxy_binding_.SubscribeEvent(event_id_, this);
    is_subscription_successful = true;
  } else {
    logger_.LogWarn([](ara::log::LogStream& s) { s << "driving_information: vehicle_speed is already subscribed. Subscription ignored."; },
                    __func__, __LINE__);
  }
  return is_subscription_successful;
}

void driving_informationProxySomeIpEventManagervehicle_speed::Unsubscribe() {
  if (subscribed_) {
    std::lock_guard<std::mutex> guard(sample_cache_lock_);
    proxy_binding_.UnsubscribeEvent(event_id_);

    // Clean the cache to save memory and to make sure that cache size is correct by next subscription.
    invisible_sample_cache_.clear();

    subscribed_ = false;
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
  
    // Deserialization result of element 'data'
    bool deserialization_ok{true};
  
  double data_l_vel{};
    ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data_data{parent};
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
  
    // Deserialization result of element 'data'
    bool deserialization_ok{true};
  
  double data_a_vel{};
    ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data_data{parent};
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

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

apns::speedtype data{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
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



void driving_informationProxySomeIpEventManagervehicle_speed::HandleEventNotification(RootDeserializerAlias&& deserializer) {
  // shortening
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialize event sample
  driving_informationvehicle_speeddataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<apns::speedtype, bool> ret_data{arg_data_deserializer.Deserialize()};

  // Deserialization successful?
  if(ret_data.second) {
    logger_.LogDebug([](ara::log::LogStream& s) {
                      s << "Received and deserialized sample for event 'vehicle_speed'."; },
                      __func__, __LINE__);

    // Store data in invisible sample cache
    this->push(ret_data.first);

    if (subscribed_) {
      // If subscribed_, then service_event_ must have been set.
      assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

      // Notify EventReceiveHandler
      service_event_->Notify();
    }
    /* else silently discard the event. */
  } else {
    logger_.LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for event 'vehicle_speed'."; },
                      __func__, __LINE__);
  }
}

void driving_informationProxySomeIpEventManagervehicle_speed::HandleBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {
  const amsr::someip_protocol::internal::SessionId session_id{header.session_id_};
  logger_.LogDebug([&session_id](ara::log::LogStream& s) { s << "(vehicle_speed): session ID: " << session_id; },
                    __func__, __LINE__);

  if (subscribed_) {
    logger_.LogError([&header](ara::log::LogStream& s) {
                      s << "Event message is larger than the configured receive buffer - ("
                        << ara::log::LogHex16{header.service_id_} << "): "
                        << "method ID: " << header.method_id_ << ", session ID: " << header.session_id_
                        << ", original message body length: " << header.length_;
},
__func__, __LINE__);
  }
}

void driving_informationProxySomeIpEventManagervehicle_speed::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (subscribed_) {
    // If subscribed_, then service_event_ must have been set.
    assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

    // Notify the subscription handler.
    service_event_->NotifySubscriptionStateUpdate(state);
  } else {
    // service_event_ might have already been unset after Unsubscribe call.
    if (state != ::ara::com::SubscriptionState::kNotSubscribed) {
      logger_.LogError([](ara::log::LogStream& s) {
      s << "Routing of event subscription state update failed. No subscription found for event 'vehicle_speed'"; },
      __func__, __LINE__);
    }
  }
}

/* ---- Event 'vehicle_position' ------------------------------------------- */

driving_informationProxySomeIpEventManagervehicle_position::driving_informationProxySomeIpEventManagervehicle_position(
    driving_informationProxySomeIpBinding& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "driving_informationProxySomeIpEventManagervehicle_position") {}

bool driving_informationProxySomeIpEventManagervehicle_position::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event. (This is passed by ara::com, so it is ok to assert its correctness)
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (!subscribed_) {
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    service_event_ = service_event;
    // set subscribed_ to true before calling SubscribeEvent, as HandleEventSubscriptionStateUpdate might then be called
    // at any moment even before SubscribeEvent is returned.
    subscribed_ = true;
    proxy_binding_.SubscribeEvent(event_id_, this);
    is_subscription_successful = true;
  } else {
    logger_.LogWarn([](ara::log::LogStream& s) { s << "driving_information: vehicle_position is already subscribed. Subscription ignored."; },
                    __func__, __LINE__);
  }
  return is_subscription_successful;
}

void driving_informationProxySomeIpEventManagervehicle_position::Unsubscribe() {
  if (subscribed_) {
    std::lock_guard<std::mutex> guard(sample_cache_lock_);
    proxy_binding_.UnsubscribeEvent(event_id_);

    // Clean the cache to save memory and to make sure that cache size is correct by next subscription.
    invisible_sample_cache_.clear();

    subscribed_ = false;
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
  
    // Deserialization result of element 'x'
    bool deserialization_ok{true};
  
  apns::locationtype::_x_type data_x{};
    ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data_x{parent};
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
  
    // Deserialization result of element 'y'
    bool deserialization_ok{true};
  
  apns::locationtype::_y_type data_y{};
    ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data_y{parent};
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
  
    // Deserialization result of element 'theta'
    bool deserialization_ok{true};
  
  apns::locationtype::_theta_type data_theta{};
    ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data_theta{parent};
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

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

apns::locationtype data{};
  ::amsr::someip_protocol::internal::serialization::ComplexDataTypeDeserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
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



void driving_informationProxySomeIpEventManagervehicle_position::HandleEventNotification(RootDeserializerAlias&& deserializer) {
  // shortening
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialize event sample
  driving_informationvehicle_positiondataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<apns::locationtype, bool> ret_data{arg_data_deserializer.Deserialize()};

  // Deserialization successful?
  if(ret_data.second) {
    logger_.LogDebug([](ara::log::LogStream& s) {
                      s << "Received and deserialized sample for event 'vehicle_position'."; },
                      __func__, __LINE__);

    // Store data in invisible sample cache
    this->push(ret_data.first);

    if (subscribed_) {
      // If subscribed_, then service_event_ must have been set.
      assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

      // Notify EventReceiveHandler
      service_event_->Notify();
    }
    /* else silently discard the event. */
  } else {
    logger_.LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for event 'vehicle_position'."; },
                      __func__, __LINE__);
  }
}

void driving_informationProxySomeIpEventManagervehicle_position::HandleBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {
  const amsr::someip_protocol::internal::SessionId session_id{header.session_id_};
  logger_.LogDebug([&session_id](ara::log::LogStream& s) { s << "(vehicle_position): session ID: " << session_id; },
                    __func__, __LINE__);

  if (subscribed_) {
    logger_.LogError([&header](ara::log::LogStream& s) {
                      s << "Event message is larger than the configured receive buffer - ("
                        << ara::log::LogHex16{header.service_id_} << "): "
                        << "method ID: " << header.method_id_ << ", session ID: " << header.session_id_
                        << ", original message body length: " << header.length_;
},
__func__, __LINE__);
  }
}

void driving_informationProxySomeIpEventManagervehicle_position::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (subscribed_) {
    // If subscribed_, then service_event_ must have been set.
    assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

    // Notify the subscription handler.
    service_event_->NotifySubscriptionStateUpdate(state);
  } else {
    // service_event_ might have already been unset after Unsubscribe call.
    if (state != ::ara::com::SubscriptionState::kNotSubscribed) {
      logger_.LogError([](ara::log::LogStream& s) {
      s << "Routing of event subscription state update failed. No subscription found for event 'vehicle_position'"; },
      __func__, __LINE__);
    }
  }
}


}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

