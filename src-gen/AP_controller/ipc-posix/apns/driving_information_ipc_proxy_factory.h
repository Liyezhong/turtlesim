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
/**        \file  AP_controller/ipc-posix/apns/driving_information_ipc_proxy_factory.h
 *        \brief  SOME/IP proxy factory for service 'driving_information'
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

#ifndef AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_PROXY_FACTORY_H_
#define AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_PROXY_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_proxy_ipc_binding.h"
#include "ipc_binding/internal/aracom_ipc_binding_proxy_factory.h"
#include "ipc_binding/internal/aracom_ipc_binding_template_configuration.h"

namespace apns {

/*!
 * \brief Type alias for the client manager.
 */
using ClientManager = amsr::ipc_binding::internal::DefaultTemplateConfiguration::ClientManagerType;

/*!
 * \brief IPC proxy factory for the service interface 'driving_information'.
 */
using driving_informationIpcProxyFactory =
    amsr::ipc_binding::internal::IpcProxyFactory<driving_informationRequiredIpcServiceInstance, ClientManager>;


}  // namespace apns

#endif  // AP_CONTROLLER_IPC_POSIX_APNS_DRIVING_INFORMATION_IPC_PROXY_FACTORY_H_

