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
/**        \file  rosap_exe/includes/apns/driving_information_skeleton_resource_manager.h
 *        \brief  Header for resource manager of service 'driving_information' skeleton.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_RESOURCE_MANAGER_H_
#define ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'driving_information' skeleton
 */
class driving_informationSkeletonResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  driving_informationSkeletonResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  driving_informationSkeletonResourceManager(const driving_informationSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  driving_informationSkeletonResourceManager(driving_informationSkeletonResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  driving_informationSkeletonResourceManager& operator=(const driving_informationSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  driving_informationSkeletonResourceManager& operator=(driving_informationSkeletonResourceManager&&) = delete;

  /*!
   * \brief Get the transmit buffer allocator for service event 'vehicle_speed'
   * \return Buffer for serialization / transmission of 'vehicle_speed' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetEventvehicle_speedTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service event 'vehicle_position'
   * \return Buffer for serialization / transmission of 'vehicle_position' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetEventvehicle_positionTxBufferAllocator();


 private:

  /*!
   * \brief Transmit buffer allocator for service event 'vehicle_speed'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator event_vehicle_speed_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service event 'vehicle_position'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator event_vehicle_position_tx_buffer_allocator_;

 };

}  // namespace resources
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_RESOURCE_MANAGER_H_
