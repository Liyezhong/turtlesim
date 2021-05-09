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
/**        \file  AP_controller/includes/apns/external_elements_skeleton_resource_manager.h
 *        \brief  Header for resource manager of service 'external_elements' skeleton.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_RESOURCE_MANAGER_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace apns {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'external_elements' skeleton
 */
class external_elementsSkeletonResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  external_elementsSkeletonResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  external_elementsSkeletonResourceManager(const external_elementsSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  external_elementsSkeletonResourceManager(external_elementsSkeletonResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  external_elementsSkeletonResourceManager& operator=(const external_elementsSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  external_elementsSkeletonResourceManager& operator=(external_elementsSkeletonResourceManager&&) = delete;

  /*!
   * \brief Get the transmit buffer allocator for service field 'laneGet'
   * \return Buffer for serialization / transmission of 'laneGet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldlaneGetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'laneSet'
   * \return Buffer for serialization / transmission of 'laneSet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldlaneSetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'laneNotifier'
   * \return Buffer for serialization / transmission of 'laneNotifier' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldlaneNotifierTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'objectGet'
   * \return Buffer for serialization / transmission of 'objectGet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldobjectGetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'objectSet'
   * \return Buffer for serialization / transmission of 'objectSet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldobjectSetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'objectNotifier'
   * \return Buffer for serialization / transmission of 'objectNotifier' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldobjectNotifierTxBufferAllocator();


 private:

  /*!
   * \brief Transmit buffer allocator for service field 'laneGet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_laneget_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'laneSet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_laneset_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'laneNotifier'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_lanenotifier_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'objectGet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_objectget_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'objectSet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_objectset_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'objectNotifier'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_objectnotifier_tx_buffer_allocator_;

 };

}  // namespace resources
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_RESOURCE_MANAGER_H_
