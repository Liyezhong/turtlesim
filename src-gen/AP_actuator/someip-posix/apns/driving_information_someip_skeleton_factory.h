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
/**        \file  AP_actuator/someip-posix/apns/driving_information_someip_skeleton_factory.h
 *        \brief  SOME/IP skeleton factory for service 'driving_information'
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

#ifndef AP_ACTUATOR_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_SKELETON_FACTORY_H_
#define AP_ACTUATOR_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_SKELETON_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_skeleton.h"
#include "apns/driving_information_skeleton_resource_manager.h"
#include "apns/driving_information_skeleton_someip_binding.h"
#include "someip_binding/internal/aracom_someip_skeleton_factory.h"

namespace apns {
namespace someip_binding {
namespace internal {

/*!
 * \brief SOME/IP skeleton factory for the service interface 'driving_information'
 * \remark generated
 */
using driving_informationSomeIpSkeletonFactory = amsr::someip_binding::internal::AraComSomeIpSkeletonFactory<resources::driving_informationSkeletonResourceManager, skeleton::driving_informationSkeleton, driving_informationSkeletonSomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_ACTUATOR_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_SKELETON_FACTORY_H_

