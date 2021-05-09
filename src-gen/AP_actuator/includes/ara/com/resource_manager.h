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
/**        \file  AP_actuator/includes/ara/com/resource_manager.h
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

#ifndef AP_ACTUATOR_INCLUDES_ARA_COM_RESOURCE_MANAGER_H_
#define AP_ACTUATOR_INCLUDES_ARA_COM_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_resource_manager.h"
#include "apns/speed_control_resource_manager.h"
#include "ara/com/someip_resource_manager.h"

namespace amsr {
namespace socal {
namespace internal {

/*!
 * \brief ara::com resource manager root object
 */
class ResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  ResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  ResourceManager(const ResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  ResourceManager(ResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  ResourceManager& operator=(const ResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  ResourceManager& operator=(ResourceManager&&) = delete;

  /*!
   * \brief Get service specific resource manager. Template specialization available for all existing services.
   * \tparam ServiceType Concrete service type
   * \return Reference to service specific resource manager
   */
  template <typename ServiceType>
  typename ServiceType::ResourceManager& GetResourceManager();

  /*!
   * \brief Get resource manager for binding 'SomeIp'
   * \return Reference to resource manager for binding 'SomeIp'
   */
  ::amsr::socal::internal::SomeIpResourceManager& GetSomeIpResourceManager();

 private:
  /*!
   * \brief Resource manager for service 'apns::driving_information'
   */
  apns::resources::driving_informationResourceManager apns_driving_information_resource_manager_;

  /*!
   * \brief Resource manager for service 'apns::speed_control'
   */
  apns::resources::speed_controlResourceManager apns_speed_control_resource_manager_;

  /*!
   * \brief Resource manager for binding 'SomeIp'
   */
  SomeIpResourceManager someip_resource_manager_;

};

}  // namespace internal
}  // namespace socal
}  // namespace amsr

#endif  // AP_ACTUATOR_INCLUDES_ARA_COM_RESOURCE_MANAGER_H_

