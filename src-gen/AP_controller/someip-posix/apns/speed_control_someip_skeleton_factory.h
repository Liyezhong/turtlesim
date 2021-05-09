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
/**        \file  AP_controller/someip-posix/apns/speed_control_someip_skeleton_factory.h
 *        \brief  SOME/IP skeleton factory for service 'speed_control'
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

#ifndef AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_SKELETON_FACTORY_H_
#define AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_SKELETON_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_skeleton.h"
#include "apns/speed_control_skeleton_resource_manager.h"
#include "apns/speed_control_skeleton_someip_binding.h"
#include "someip_binding/internal/aracom_someip_skeleton_factory.h"

namespace apns {
namespace someip_binding {
namespace internal {

/*!
 * \brief SOME/IP skeleton factory for the service interface 'speed_control'
 * \remark generated
 */
using speed_controlSomeIpSkeletonFactory = amsr::someip_binding::internal::AraComSomeIpSkeletonFactory<resources::speed_controlSkeletonResourceManager, skeleton::speed_controlSkeleton, speed_controlSkeletonSomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_CONTROLLER_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_SKELETON_FACTORY_H_

