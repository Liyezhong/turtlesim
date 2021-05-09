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
/**        \file  rosap_exe/includes/apns/speed_control_skeleton_resource_manager.h
 *        \brief  Header for resource manager of service 'speed_control' skeleton.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_RESOURCE_MANAGER_H_
#define ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'speed_control' skeleton
 */
class speed_controlSkeletonResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  speed_controlSkeletonResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  speed_controlSkeletonResourceManager(const speed_controlSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  speed_controlSkeletonResourceManager(speed_controlSkeletonResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  speed_controlSkeletonResourceManager& operator=(const speed_controlSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  speed_controlSkeletonResourceManager& operator=(speed_controlSkeletonResourceManager&&) = delete;

  /*!
   * \brief Get the transmit buffer allocator for service event 'LKA_speed'
   * \return Buffer for serialization / transmission of 'LKA_speed' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetEventLKA_speedTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service event 'ToGoal_speed'
   * \return Buffer for serialization / transmission of 'ToGoal_speed' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetEventToGoal_speedTxBufferAllocator();


 private:

  /*!
   * \brief Transmit buffer allocator for service event 'LKA_speed'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator event_lka_speed_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service event 'ToGoal_speed'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator event_togoal_speed_tx_buffer_allocator_;

 };

}  // namespace resources
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_RESOURCE_MANAGER_H_
