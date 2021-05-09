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
/**        \file  rosap_exe/src/ara/com/resource_manager.cpp
 *        \brief  Binding independent resource manager
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
#include "ara/com/resource_manager.h"
#include "apns/driving_information.h"
#include "apns/external_elements.h"
#include "apns/speed_control.h"

namespace amsr {
namespace socal {
namespace internal {

/*!
 * \brief Template specialization for resource manager of service 'apns::driving_information'
 */
template <>
apns::resources::driving_informationResourceManager&
ResourceManager::GetResourceManager<apns::driving_information>() {
  return apns_driving_information_resource_manager_;
}

/*!
 * \brief Template specialization for resource manager of service 'apns::external_elements'
 */
template <>
apns::resources::external_elementsResourceManager&
ResourceManager::GetResourceManager<apns::external_elements>() {
  return apns_external_elements_resource_manager_;
}

/*!
 * \brief Template specialization for resource manager of service 'apns::speed_control'
 */
template <>
apns::resources::speed_controlResourceManager&
ResourceManager::GetResourceManager<apns::speed_control>() {
  return apns_speed_control_resource_manager_;
}

::amsr::socal::internal::IpcResourceManager&
::amsr::socal::internal::ResourceManager::GetIpcResourceManager() {
  return ipc_resource_manager_;
}

::amsr::socal::internal::SomeIpResourceManager&
::amsr::socal::internal::ResourceManager::GetSomeIpResourceManager() {
  return someip_resource_manager_;
}

}  // namespace internal
}  // namespace socal
}  // namespace amsr

