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
/**        \file  AP_actuator/src/apns/driving_information_skeleton.cpp
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_skeleton.h"
#include "ara/com/internal_com_exception.h"
#include "ara/com/runtime.h"
#include "socal/internal/instance_specifier_lookup_table.h"

/*!
 * \trace SPEC-4980240
 * \trace SPEC-4980241
 */
namespace apns {
namespace skeleton {
constexpr ::amsr::socal::internal::configuration::SkeletonConfiguration driving_informationSkeleton::kConfiguration;

driving_informationSkeleton::driving_informationSkeleton(ara::com::InstanceIdentifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , vehicle_speed(this)
      , vehicle_position(this)
       {}

driving_informationSkeleton::driving_informationSkeleton(ara::core::InstanceSpecifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , vehicle_speed(this)
      , vehicle_position(this)
       {}

driving_informationSkeleton::driving_informationSkeleton(ara::com::InstanceIdentifierContainer instance_identifiers,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance_identifiers, mode, kConfiguration}
      , vehicle_speed(this)
      , vehicle_position(this)
       {}

driving_informationSkeleton::~driving_informationSkeleton() {
  // Stop all scheduled tasks related to this skeleton.
  GetThreadPool().RemoveTasks(this);
}

void driving_informationSkeleton::DoFieldInitializationChecks() {
  /* Check if all fields are initialized correctly
    * - if a field has Setter, SetHandler must be registered.
    * - if a field has Notification, Update must have been called.
    * - if a field has Getter and no GetHandler is registered, Update() must have been called.
    */
}

void driving_informationSkeleton::SendInitialFieldNotifications() {
  // Send initial field events for all fields with "hasNotifier = true"
}

}  // namespace skeleton
}  // namespace apns

