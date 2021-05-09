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
/**        \file  rosap_exe/includes/apns/speed_control_resource_manager.h
 *        \brief  Header for resource manager of service 'speed_control'.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_RESOURCE_MANAGER_H_
#define ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_skeleton_resource_manager.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'speed_control'
 */
class speed_controlResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  speed_controlResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  speed_controlResourceManager(const speed_controlResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  speed_controlResourceManager(speed_controlResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  speed_controlResourceManager& operator=(const speed_controlResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  speed_controlResourceManager& operator=(speed_controlResourceManager&&) = delete;
  /*!
   * \brief Get resource manager for service 'speed_control' skeleton
   * \return Resource manager for service 'speed_control' skeleton
   */
  speed_controlSkeletonResourceManager& GetSkeletonResourceManager();

 private:
  /*!
   * \brief Resource manager for service 'speed_control' skeleton
   */
  speed_controlSkeletonResourceManager skeleton_resource_manager_;
};

}  // namespace resources
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_RESOURCE_MANAGER_H_
