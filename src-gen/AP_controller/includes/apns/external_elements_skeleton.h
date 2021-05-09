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
/**        \file  AP_controller/includes/apns/external_elements_skeleton.h
 *        \brief  Skeleton for service 'external_elements'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_H_

/*!
 * \trace SPEC-4980239
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include <memory>
#include <vector>
#include "apns/external_elements_common.h"
#include "apns/external_elements_skeleton_impl_interface.h"
#include "apns/external_elements_types.h"
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
class external_elementsSkeleton;

/*!
 * \trace SPEC-4980244
 */
namespace methods {

}  // namespace methods

/*!
 * \trace SPEC-4980243
 */
namespace events {

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {
/*!
 * \brief Type alias for the notification of field 'lane'.
 */
using FieldNotifierlane = ::amsr::socal::internal::SkeletonEvent<
  apns::skeleton::external_elementsSkeleton,
  apns::lanetype,
  apns::internal::external_elementsSkeletonImplInterface,
  &apns::internal::external_elementsSkeletonImplInterface::UpdateFieldlane>;

/*!
 * \brief Type alias for the notifier configuration of field 'lane'.
 */
using FieldNotifierConfiglane = ::amsr::socal::internal::fields::SkeletonFieldParams::HasNotifier<true, FieldNotifierlane>;

/*!
 * \brief Type alias for the getter configuration of field 'lane'.
 */
using FieldGetterConfiglane = ::amsr::socal::internal::fields::SkeletonFieldParams::HasGetter<true>;

/*!
 * \brief Type alias for the setter configuration of field 'lane'.
 */
using FieldSetterConfiglane = ::amsr::socal::internal::fields::SkeletonFieldParams::HasSetter<true>;

/*!
 * \brief Field name.
 */
struct laneName {
  /*!
   * \brief Field name string.
   */
  static constexpr vac::container::CStringView Name = "lane"_sv;
};

/*!
 * \brief Type alias for the parameterization of field 'lane'.
 */
using FieldConfiglane = ::amsr::socal::internal::fields::SkeletonFieldConfig<apns::skeleton::external_elementsSkeleton, FieldNotifierConfiglane, FieldGetterConfiglane, FieldSetterConfiglane, laneName>;

/*!
 * \brief Type alias for service field 'lane', that is part of the skeleton.
 *
 * \trace SPEC-4980343 (Service skeleton Field class)
 */
using lane = ::amsr::socal::internal::fields::SkeletonField<apns::lanetype, FieldConfiglane>;

/*!
 * \brief Type alias for the notification of field 'object'.
 */
using FieldNotifierobject = ::amsr::socal::internal::SkeletonEvent<
  apns::skeleton::external_elementsSkeleton,
  apns::locationtype,
  apns::internal::external_elementsSkeletonImplInterface,
  &apns::internal::external_elementsSkeletonImplInterface::UpdateFieldobject>;

/*!
 * \brief Type alias for the notifier configuration of field 'object'.
 */
using FieldNotifierConfigobject = ::amsr::socal::internal::fields::SkeletonFieldParams::HasNotifier<true, FieldNotifierobject>;

/*!
 * \brief Type alias for the getter configuration of field 'object'.
 */
using FieldGetterConfigobject = ::amsr::socal::internal::fields::SkeletonFieldParams::HasGetter<true>;

/*!
 * \brief Type alias for the setter configuration of field 'object'.
 */
using FieldSetterConfigobject = ::amsr::socal::internal::fields::SkeletonFieldParams::HasSetter<true>;

/*!
 * \brief Field name.
 */
struct objectName {
  /*!
   * \brief Field name string.
   */
  static constexpr vac::container::CStringView Name = "object"_sv;
};

/*!
 * \brief Type alias for the parameterization of field 'object'.
 */
using FieldConfigobject = ::amsr::socal::internal::fields::SkeletonFieldConfig<apns::skeleton::external_elementsSkeleton, FieldNotifierConfigobject, FieldGetterConfigobject, FieldSetterConfigobject, objectName>;

/*!
 * \brief Type alias for service field 'object', that is part of the skeleton.
 *
 * \trace SPEC-4980343 (Service skeleton Field class)
 */
using object = ::amsr::socal::internal::fields::SkeletonField<apns::locationtype, FieldConfigobject>;


}  // namespace fields

/*!
 * \brief Skeleton interface class for the service 'external_elements'.
 * \vpublic
 * \trace SPEC-4980341 (Service skeleton class)
 */
class external_elementsSkeleton
    : public ::amsr::socal::internal::Skeleton<apns::external_elements,
                                          apns::internal::external_elementsSkeletonImplInterface> {
 public:
  /*!
   * \brief Delete default constructor.
   */
  external_elementsSkeleton() = delete;
  /*!
   * \brief Delete copy constructor.
   */
  external_elementsSkeleton(external_elementsSkeleton const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  external_elementsSkeleton(external_elementsSkeleton &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  external_elementsSkeleton &operator=(external_elementsSkeleton const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  external_elementsSkeleton &operator=(external_elementsSkeleton &&) & = delete;

  /*!
   * \brief Constructor of external_elementsSkeleton.
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
  explicit external_elementsSkeleton(
      ara::com::InstanceIdentifier instance,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

  /*!
   * \brief Constructor of external_elementsSkeleton.
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
  explicit external_elementsSkeleton(
      ara::core::InstanceSpecifier instance,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

  /*!
   * \brief Constructor of external_elementsSkeleton.
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
  explicit external_elementsSkeleton(
      ara::com::InstanceIdentifierContainer instance_identifiers,
      ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);


  /*!
   * \brief Destructor
   * \details This call will be blocked until all current method requests are finished/canceled.
   * \vpublic
   * \trace SPEC-4980351
   */
  virtual ~external_elementsSkeleton();

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief The skeleton field 'lane' which can be used by application developer.
   * \details 
   * Data of type apns::lanetype
   * \vpublic
   */
  fields::lane lane;

  /*!
   * \brief The skeleton field 'object' which can be used by application developer.
   * \details 
   * Data of type apns::locationtype
   * \vpublic
   */
  fields::object object;

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Skeleton<apns::external_elements, apns::internal::external_elementsSkeletonImplInterface>;

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
};  // class external_elementsSkeleton

}  // namespace skeleton
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_H_

