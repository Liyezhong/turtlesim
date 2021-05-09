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
/**        \file  AP_actuator/includes/apns/driving_information_skeleton.h
 *        \brief  Skeleton for service 'driving_information'.
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_api
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_H_
#define AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_H_

/*!
 * \trace SPEC-4980239
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include <memory>
#include <vector>
#include "apns/driving_information_common.h"
#include "apns/driving_information_skeleton_impl_interface.h"
#include "apns/driving_information_types.h"
#include "ara/core/future.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/optional.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "socal/internal/fields/skeleton_field.h"
#include "socal/internal/skeleton.h"
#include "socal/internal/skeleton_event.h"
#include "socal/internal/skeleton_interface.h"
#include "socal/internal/skeleton_request_handling.h"

/*!
 * \trace SPEC-4980240
 */
namespace apns {
/*!
 * \trace SPEC-4980241
 */
namespace skeleton {
/*!
 * \brief Forward declaration for inserting as a type into the template class SkeletonEvent
 */
class driving_informationSkeleton;

/*!
 * \trace SPEC-4980244
 */
namespace methods {

}  // namespace methods

/*!
 * \trace SPEC-4980243
 */
namespace events {

/*!
 * \brief Type alias for service event 'vehicle_speed', that is part of the skeleton.
 *
 * \trace SPEC-4980342 (Service skeleton event class)
 */
using vehicle_speed =
    ::amsr::socal::internal::SkeletonEvent<apns::skeleton::driving_informationSkeleton, apns::speedtype,
                                      apns::internal::driving_informationSkeletonImplInterface,
                                      &apns::internal::driving_informationSkeletonImplInterface::SendEventvehicle_speed>;

/*!
 * \brief Type alias for service event 'vehicle_position', that is part of the skeleton.
 *
 * \trace SPEC-4980342 (Service skeleton event class)
 */
using vehicle_position =
    ::amsr::socal::internal::SkeletonEvent<apns::skeleton::driving_informationSkeleton, apns::locationtype,
                                      apns::internal::driving_informationSkeletonImplInterface,
                                      &apns::internal::driving_informationSkeletonImplInterface::SendEventvehicle_position>;

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {

}  // namespace fields

/*!
 * \brief Skeleton interface class for the service 'driving_information'.
 * \vpublic
 * \trace SPEC-4980341 (Service skeleton class)
 */
class driving_informationSkeleton
    : public ::amsr::socal::internal::Skeleton<apns::driving_information,
                                          apns::internal::driving_informationSkeletonImplInterface> {
 public:
  /*!
   * \brief Delete default constructor.
   */
  driving_informationSkeleton() = delete;
  /*!
   * \brief Delete copy constructor.
   */
  driving_informationSkeleton(driving_informationSkeleton const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  driving_informationSkeleton(driving_informationSkeleton &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  driving_informationSkeleton &operator=(driving_informationSkeleton const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  driving_informationSkeleton &operator=(driving_informationSkeleton &&) & = delete;

  /*!
   * \brief Constructor of driving_informationSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   * \vpublic
   *
   * \trace SPEC-4980351 (Creation of service skeleton)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance The identifier of a specific instance of a service, needed to distinguish different instances of
   *        exactly the same service in the system.
   * \param mode The mode of the service implpementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
  explicit driving_informationSkeleton(
      ara::com::InstanceIdentifier instance,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

  /*!
   * \brief Constructor of driving_informationSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \trace SPEC-8053552 (Creation of service skeleton using Instance Spec)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance The InstanceSpecifier of a specific service instance, needed to distinguish different instances of
   *        exactly the same service in the system.
   * \param mode The mode of the service implementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same underlying instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
  explicit driving_informationSkeleton(
      ara::core::InstanceSpecifier instance,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

  /*!
   * \brief Constructor of driving_informationSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \trace SPEC-8053554 (Creation of service skeleton using Instance ID Container)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance_identifiers The container of instances of a service, each instance element needed to distinguish different instances of exactly the same service in the system.
   * \param mode The mode of the service implementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
  explicit driving_informationSkeleton(
      ara::com::InstanceIdentifierContainer instance_identifiers,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);


  /*!
   * \brief Destructor
   * \details This call will be blocked until all current method requests are finished/canceled.
   * \vpublic
   * \trace SPEC-4980351
   */
  virtual ~driving_informationSkeleton();

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief The skeleton event 'vehicle_speed' which can be used by application developer.
   * \details 
   * Data of type apns::speedtype
   * \vpublic
   */
  events::vehicle_speed vehicle_speed;

  /*!
   * \brief The skeleton event 'vehicle_position' which can be used by application developer.
   * \details 
   * Data of type apns::locationtype
   * \vpublic
   */
  events::vehicle_position vehicle_position;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Skeleton<apns::driving_information, apns::internal::driving_informationSkeletonImplInterface>;

  /*!
   * \brief Checks if all fields are correctly initialized and throws the corresponding exception in case of failure.
   *
   * \trace SPEC-4980364 (Ensuring the existence of valid Field values)
   * \trace SPEC-4980365 (Ensuring existence of SetHandler)
   *
   * \throws ara::com::SetHandlerNotAvailableException if any of the fields of the skeleton has Setter but no SetHandler
   *         is registered.
   * \throws ara::com::BackendNotAvailableException If SOME/IP is configured as the communication binding and the
   *         application is not connected to the Daemon.
   * \throws ara::com::FieldNotInitializedException if any of the fields of the skeleton is not initialized and either
   *         1) it has a notifier or 2) it has a getter and no GetHandler is registered.
   */
  void DoFieldInitializationChecks() override;

  /*!
   * \brief Sends all initial events for the fields that have notifiers.
   */
  void SendInitialFieldNotifications() override;

  /*!
   * \brief Skeleton resource configuration parametrized via ARXML.
   */
  static constexpr ::amsr::socal::internal::configuration::SkeletonConfiguration kConfiguration{::amsr::socal::internal::configuration::SkeletonConfiguration::MethodRequestBufferLimit{0U}, ::amsr::socal::internal::configuration::MemoryMode::kFlexible};
};  // class driving_informationSkeleton

}  // namespace skeleton
}  // namespace apns

#endif  // AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_H_

