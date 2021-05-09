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
/**        \file  rosap_exe/includes/apns/driving_information_resource_manager.h
 *        \brief  Header for resource manager of service 'driving_information'.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_RESOURCE_MANAGER_H_
#define ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_skeleton_resource_manager.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'driving_information'
 */
class driving_informationResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  driving_informationResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  driving_informationResourceManager(const driving_informationResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  driving_informationResourceManager(driving_informationResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  driving_informationResourceManager& operator=(const driving_informationResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  driving_informationResourceManager& operator=(driving_informationResourceManager&&) = delete;
  /*!
   * \brief Get resource manager for service 'driving_information' skeleton
   * \return Resource manager for service 'driving_information' skeleton
   */
  driving_informationSkeletonResourceManager& GetSkeletonResourceManager();

 private:
  /*!
   * \brief Resource manager for service 'driving_information' skeleton
   */
  driving_informationSkeletonResourceManager skeleton_resource_manager_;
};

}  // namespace resources
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_RESOURCE_MANAGER_H_
