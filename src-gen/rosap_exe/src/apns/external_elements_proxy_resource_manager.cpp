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
/**        \file  rosap_exe/src/apns/external_elements_proxy_resource_manager.cpp
 *        \brief  Resource manager of service 'external_elements' proxy.
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
#include "apns/external_elements_proxy_resource_manager.h"

namespace apns {
namespace resources {

external_elementsProxyResourceManager::external_elementsProxyResourceManager()
  : 
     field_laneget_tx_buffer_allocator_(),
     field_laneset_tx_buffer_allocator_(),
     field_lanenotifier_tx_buffer_allocator_(),
     field_objectget_tx_buffer_allocator_(),
     field_objectset_tx_buffer_allocator_(),
     field_objectnotifier_tx_buffer_allocator_()
    {}

amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldlaneGetTxBufferAllocator() {
  return field_laneget_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldlaneSetTxBufferAllocator() {
  return field_laneset_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldlaneNotifierTxBufferAllocator() {
  return field_lanenotifier_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldobjectGetTxBufferAllocator() {
  return field_objectget_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldobjectSetTxBufferAllocator() {
  return field_objectset_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& external_elementsProxyResourceManager::GetFieldobjectNotifierTxBufferAllocator() {
  return field_objectnotifier_tx_buffer_allocator_;

}
}  // namespace resources
}  // namespace apns

