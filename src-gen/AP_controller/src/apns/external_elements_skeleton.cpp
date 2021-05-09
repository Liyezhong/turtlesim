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
/**        \file  AP_controller/src/apns/external_elements_skeleton.cpp
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_skeleton.h"
#include "ara/com/internal_com_exception.h"
#include "ara/com/runtime.h"
#include "socal/internal/instance_specifier_lookup_table.h"

/*!
 * \trace SPEC-4980240
 * \trace SPEC-4980241
 */
namespace apns {
namespace skeleton {
constexpr ::amsr::socal::internal::configuration::SkeletonConfiguration external_elementsSkeleton::kConfiguration;

external_elementsSkeleton::external_elementsSkeleton(ara::com::InstanceIdentifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , lane(this)
      , object(this)
       {}

external_elementsSkeleton::external_elementsSkeleton(ara::core::InstanceSpecifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , lane(this)
      , object(this)
       {}

external_elementsSkeleton::external_elementsSkeleton(ara::com::InstanceIdentifierContainer instance_identifiers,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance_identifiers, mode, kConfiguration}
      , lane(this)
      , object(this)
       {}

external_elementsSkeleton::~external_elementsSkeleton() {
  // Stop all scheduled tasks related to this skeleton.
  GetThreadPool().RemoveTasks(this);
}

void external_elementsSkeleton::DoFieldInitializationChecks() {
  /* Check if all fields are initialized correctly
    * - if a field has Setter, SetHandler must be registered.
    * - if a field has Notification, Update must have been called.
    * - if a field has Getter and no GetHandler is registered, Update() must have been called.
    */

    if (!lane.IsSetHandlerRegistered()) {
      logger_.LogError([this](ara::log::LogStream& s) {
                        s << "Failed to offer service 'external_elements' with instance id(s) '";
                        for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                          s << " " << entry.GetInstanceIdentifier().ToString();
                        }
                        s << "' - No SetHandler has been registered for field 'lane'."; },
                        __func__, __LINE__);
      throw ara::com::InternalComException(ara::com::InternalComErrc::set_handler_not_available);
    }
    if (!lane.IsUpdated()) {
        logger_.LogError([this](ara::log::LogStream& s) {
                          s << "Failed to offer service 'external_elements' with instance id(s) '";
                          for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                            s << " " << entry.GetInstanceIdentifier().ToString();
                          }
                          s << "' - No initial value has been set for field 'lane' (lane::Update(...) has never been called)."; },
                          __func__, __LINE__);
        throw ara::com::InternalComException(ara::com::InternalComErrc::field_not_initialized);
    }

    if (!object.IsSetHandlerRegistered()) {
      logger_.LogError([this](ara::log::LogStream& s) {
                        s << "Failed to offer service 'external_elements' with instance id(s) '";
                        for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                          s << " " << entry.GetInstanceIdentifier().ToString();
                        }
                        s << "' - No SetHandler has been registered for field 'object'."; },
                        __func__, __LINE__);
      throw ara::com::InternalComException(ara::com::InternalComErrc::set_handler_not_available);
    }
    if (!object.IsUpdated()) {
        logger_.LogError([this](ara::log::LogStream& s) {
                          s << "Failed to offer service 'external_elements' with instance id(s) '";
                          for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                            s << " " << entry.GetInstanceIdentifier().ToString();
                          }
                          s << "' - No initial value has been set for field 'object' (object::Update(...) has never been called)."; },
                          __func__, __LINE__);
        throw ara::com::InternalComException(ara::com::InternalComErrc::field_not_initialized);
    }
}

void external_elementsSkeleton::SendInitialFieldNotifications() {
  // Send initial field events for all fields with "hasNotifier = true"
  lane.SendInitialValue();
  object.SendInitialValue();
}

}  // namespace skeleton
}  // namespace apns

