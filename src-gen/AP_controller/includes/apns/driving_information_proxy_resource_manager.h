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
/**        \file  AP_controller/includes/apns/driving_information_proxy_resource_manager.h
 *        \brief  Header for resource manager of service 'driving_information' proxy.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_RESOURCE_MANAGER_H_
#define AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'driving_information' proxy
 */
class driving_informationProxyResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  driving_informationProxyResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  driving_informationProxyResourceManager(const driving_informationProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  driving_informationProxyResourceManager(driving_informationProxyResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  driving_informationProxyResourceManager& operator=(const driving_informationProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  driving_informationProxyResourceManager& operator=(driving_informationProxyResourceManager&&) = delete;

 private:
 };

}  // namespace resources
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_RESOURCE_MANAGER_H_
