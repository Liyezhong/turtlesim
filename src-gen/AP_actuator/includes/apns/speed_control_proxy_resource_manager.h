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
/**        \file  AP_actuator/includes/apns/speed_control_proxy_resource_manager.h
 *        \brief  Header for resource manager of service 'speed_control' proxy.
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

#ifndef AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_RESOURCE_MANAGER_H_
#define AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'speed_control' proxy
 */
class speed_controlProxyResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  speed_controlProxyResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  speed_controlProxyResourceManager(const speed_controlProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  speed_controlProxyResourceManager(speed_controlProxyResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  speed_controlProxyResourceManager& operator=(const speed_controlProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  speed_controlProxyResourceManager& operator=(speed_controlProxyResourceManager&&) = delete;

 private:
 };

}  // namespace resources
}  // namespace apns

#endif  // AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_RESOURCE_MANAGER_H_
