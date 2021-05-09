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
/**        \file  AP_controller/includes/ara/com/ipc_resource_manager.h
 *        \brief  Header for resource manager of binding 'Ipc'.
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

#ifndef AP_CONTROLLER_INCLUDES_ARA_COM_IPC_RESOURCE_MANAGER_H_
#define AP_CONTROLLER_INCLUDES_ARA_COM_IPC_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace amsr {
namespace socal {
namespace internal {

/*!
 * \brief ara::com resource manager for binding 'Ipc'
 */
class IpcResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  IpcResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  IpcResourceManager(const IpcResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  IpcResourceManager(IpcResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  IpcResourceManager& operator=(const IpcResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  IpcResourceManager& operator=(IpcResourceManager&&) = delete;

  /*!
   * \brief Get the receive buffer allocator for binding 'Ipc'
   * \return Allocator for buffers meant to accomodate received 'Ipc' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetRxBufferAllocator();

  /*!
   * \brief Get the error buffer allocator for binding 'Ipc'
   * \return Allocator for buffers meant to accomodate 'Ipc' error messages
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetErrorMessageMemoryBufferAllocator();


 private:
  /*!
   * \brief Receive buffer allocator for binding 'Ipc'
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator rx_buffer_allocator_;
  /*!
   * \brief Error buffer allocator for binding 'Ipc'
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator err_buffer_allocator_;
 };

}  // namespace internal
}  // namespace socal
}  // namespace amsr

#endif  // AP_CONTROLLER_INCLUDES_ARA_COM_IPC_RESOURCE_MANAGER_H_
