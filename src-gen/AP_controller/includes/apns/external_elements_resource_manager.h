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
/**        \file  AP_controller/includes/apns/external_elements_resource_manager.h
 *        \brief  Header for resource manager of service 'external_elements'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_RESOURCE_MANAGER_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_skeleton_resource_manager.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'external_elements'
 */
class external_elementsResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  external_elementsResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  external_elementsResourceManager(const external_elementsResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  external_elementsResourceManager(external_elementsResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  external_elementsResourceManager& operator=(const external_elementsResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  external_elementsResourceManager& operator=(external_elementsResourceManager&&) = delete;
  /*!
   * \brief Get resource manager for service 'external_elements' skeleton
   * \return Resource manager for service 'external_elements' skeleton
   */
  external_elementsSkeletonResourceManager& GetSkeletonResourceManager();

 private:
  /*!
   * \brief Resource manager for service 'external_elements' skeleton
   */
  external_elementsSkeletonResourceManager skeleton_resource_manager_;
};

}  // namespace resources
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_RESOURCE_MANAGER_H_
