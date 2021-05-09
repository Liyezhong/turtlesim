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
/**        \file  AP_actuator/src/apns/driving_information_skeleton_resource_manager.cpp
 *        \brief  Resource manager of service 'driving_information' skeleton.
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
#include "apns/driving_information_skeleton_resource_manager.h"

namespace apns {
namespace resources {

driving_informationSkeletonResourceManager::driving_informationSkeletonResourceManager()
  : 
     event_vehicle_speed_tx_buffer_allocator_(),
     event_vehicle_position_tx_buffer_allocator_()
    {}

amsr::com_common::internal::memory::MemoryBufferAllocator& driving_informationSkeletonResourceManager::GetEventvehicle_speedTxBufferAllocator() {
  return event_vehicle_speed_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& driving_informationSkeletonResourceManager::GetEventvehicle_positionTxBufferAllocator() {
  return event_vehicle_position_tx_buffer_allocator_;

}
}  // namespace resources
}  // namespace apns

