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
/**        \file  AP_actuator/someip-posix/apns/speed_control_someip_proxy_factory.h
 *        \brief  SOME/IP proxy factory for service 'speed_control'
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

#ifndef AP_ACTUATOR_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_PROXY_FACTORY_H_
#define AP_ACTUATOR_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_PROXY_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_proxy.h"
#include "apns/speed_control_proxy_resource_manager.h"
#include "apns/speed_control_proxy_someip_binding.h"
#include "someip_binding/internal/aracom_someip_proxy_factory.h"

namespace apns {
namespace someip_binding {
namespace internal {


/*!
 * \brief SOME/IP proxy factory for the service interface 'speed_control'
 * \remark generated
 */
using speed_controlSomeIpProxyFactory = amsr::someip_binding::internal::AraComSomeIpProxyFactory<resources::speed_controlProxyResourceManager, proxy::speed_controlProxy, speed_controlProxySomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_ACTUATOR_SOMEIP_POSIX_APNS_SPEED_CONTROL_SOMEIP_PROXY_FACTORY_H_

