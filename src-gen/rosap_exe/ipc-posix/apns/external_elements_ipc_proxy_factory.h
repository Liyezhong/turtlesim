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
/**        \file  rosap_exe/ipc-posix/apns/external_elements_ipc_proxy_factory.h
 *        \brief  SOME/IP proxy factory for service 'external_elements'
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

#ifndef ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_PROXY_FACTORY_H_
#define ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_PROXY_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_proxy_ipc_binding.h"
#include "ipc_binding/internal/aracom_ipc_binding_proxy_factory.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"

namespace apns {

/*!
 * \brief Type alias for the client manager.
 */
using ClientManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ClientManagerType;

/*!
 * \brief IPC proxy factory for the service interface 'external_elements'.
 */
using external_elementsIpcProxyFactory =
    amsr::ipc_binding::internal::IpcProxyFactory<external_elementsRequiredIpcServiceInstance, ClientManager>;


}  // namespace apns

#endif  // ROSAP_EXE_IPC_POSIX_APNS_EXTERNAL_ELEMENTS_IPC_PROXY_FACTORY_H_

