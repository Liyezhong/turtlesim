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
/**        \file  rosap_exe/ipc-posix/apns/driving_information_ipc_skeleton_factory.h
 *        \brief  SOME/IP skeleton factory for service 'driving_information'
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_SKELETON_FACTORY_H_
#define ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_SKELETON_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_skeleton_ipc_binding.h"
#include "ipc_binding/internal/aracom_ipc_binding_skeleton_factory.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"

namespace apns {

/*!
 * \brief Type alias for the server manager.
 */
using ServerManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ServerManagerType;

/*!
 * \brief IPC skeleton factory for the service interface 'driving_information'.
 */
using driving_informationIpcSkeletonFactory =
    amsr::ipc_binding::internal::IpcSkeletonFactory<driving_informationProvidedIpcServiceInstance, ServerManager>;

}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_SKELETON_FACTORY_H_

