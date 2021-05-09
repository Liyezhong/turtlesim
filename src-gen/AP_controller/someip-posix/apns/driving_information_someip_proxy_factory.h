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
/**        \file  AP_controller/someip-posix/apns/driving_information_someip_proxy_factory.h
 *        \brief  SOME/IP proxy factory for service 'driving_information'
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

#ifndef AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_PROXY_FACTORY_H_
#define AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_PROXY_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_proxy.h"
#include "apns/driving_information_proxy_resource_manager.h"
#include "apns/driving_information_proxy_someip_binding.h"
#include "someip_binding/internal/aracom_someip_proxy_factory.h"

namespace apns {
namespace someip_binding {
namespace internal {


/*!
 * \brief SOME/IP proxy factory for the service interface 'driving_information'
 * \remark generated
 */
using driving_informationSomeIpProxyFactory = amsr::someip_binding::internal::AraComSomeIpProxyFactory<resources::driving_informationProxyResourceManager, proxy::driving_informationProxy, driving_informationProxySomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace apns

#endif  // AP_CONTROLLER_SOMEIP_POSIX_APNS_DRIVING_INFORMATION_SOMEIP_PROXY_FACTORY_H_

