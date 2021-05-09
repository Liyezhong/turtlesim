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
/**        \file  AP_controller/src/apns/speed_control_skeleton_resource_manager.cpp
 *        \brief  Resource manager of service 'speed_control' skeleton.
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
#include "apns/speed_control_skeleton_resource_manager.h"

namespace apns {
namespace resources {

speed_controlSkeletonResourceManager::speed_controlSkeletonResourceManager()
  : 
     event_lka_speed_tx_buffer_allocator_(),
     event_togoal_speed_tx_buffer_allocator_()
    {}

amsr::com_common::internal::memory::MemoryBufferAllocator& speed_controlSkeletonResourceManager::GetEventLKA_speedTxBufferAllocator() {
  return event_lka_speed_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& speed_controlSkeletonResourceManager::GetEventToGoal_speedTxBufferAllocator() {
  return event_togoal_speed_tx_buffer_allocator_;

}
}  // namespace resources
}  // namespace apns

