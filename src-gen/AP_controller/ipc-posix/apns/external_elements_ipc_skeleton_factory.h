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
/**        \file  AP_controller/ipc-posix/apns/external_elements_ipc_skeleton_factory.h
 *        \brief  SOME/IP skeleton factory for service 'external_elements'
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_ipc
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_SKELETON_FACTORY_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_SKELETON_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_skeleton_ipc_binding.h"
#include "ipc_binding/internal/aracom_ipc_binding_skeleton_factory.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"

namespace apns {

/*!
 * \brief Type alias for the server manager.
 */
using ServerManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ServerManagerType;

/*!
 * \brief IPC skeleton factory for the service interface 'external_elements'.
 */
using external_elementsIpcSkeletonFactory =
    amsr::ipc_binding::internal::IpcSkeletonFactory<external_elementsProvidedIpcServiceInstance, ServerManager>;

}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_SKELETON_FACTORY_H_

