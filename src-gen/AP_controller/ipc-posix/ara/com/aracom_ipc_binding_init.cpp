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
/**        \file  AP_controller/ipc-posix/ara/com/aracom_ipc_binding_init.cpp
 *        \brief  ara::com IPC skeleton and proxy factory initialization
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_ipc_proxy_factory.h"
#include "apns/external_elements_ipc_skeleton_factory.h"
#include "ara/core/optional.h"
#include "ipc_binding/internal/aracom_ipc_binding.h"
#include "ipc_binding/internal/ipc_protocol/ipc_protocol_types.h"
#include "ipc_binding/internal/service_discovery/required_service_instance_manager.h"

namespace amsr {
namespace ipc_binding {
namespace internal {

/*!
 * \brief Literals namespace needed for StringView _sv literal.
 */
using namespace vac::container::literals;  // NOLINT(build/namespaces)

namespace apns {
/*!
 * \brief Static instantiation of a skeleton factory for the service 'external_elements'
 */
::ara::core::Optional<::apns::external_elementsIpcSkeletonFactory>
    external_elements_ipc_skeleton_factory_;
}  // namespace apns


namespace apns {
/*!
 * \brief Static instantiation of a proxy factory for the service 'driving_information'
 */
::ara::core::Optional<::apns::driving_informationIpcProxyFactory>
    driving_information_ipc_proxy_factory_;
}  // namespace apns


void AraComIpcBinding::InitializeHook(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  InitializeInstanceSpecifierMappings(instance_specifier_table);
  InitializeProvidedServiceDeployments();
  InitializeRequiredServiceDeployments();
}

void AraComIpcBinding::InitializeInstanceSpecifierMappings(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  // ---- Register all known R-Port InstanceSpecifiers ----

  // Map R-Port /turtlesim/Application_design/AP_controller_app/controller/driving_information to instance /turtlesim/Ipc/Required/RequiredIpcdriving_information 
  instance_specifier_table.MapInstanceSpecifierToInstanceId(
      this, ::ara::core::InstanceSpecifier{"AP_controller/controller/driving_information"_sv},
      ::ara::com::InstanceIdentifier{"Ipc:1"_sv},
      "/turtlesim/ServiceDesign/driving_information/driving_information"_sv);

  // ---- Register all known P-Port InstanceSpecifiers ----

  // Map P-Port /turtlesim/Application_design/AP_controller_app/controller/external_elements to instance /turtlesim/Ipc/Provided/ProvidedIpcexternal_elements
  instance_specifier_table.MapInstanceSpecifierToInstanceId(
      this, ::ara::core::InstanceSpecifier{"AP_controller/controller/external_elements"_sv},
      ::ara::com::InstanceIdentifier{"Ipc:2"_sv},
      "/turtlesim/ServiceDesign/external_elements/external_elements"_sv);
}

void AraComIpcBinding::InitializeProvidedServiceDeployments() {
  {
    // Instantiate provided service instances for service deployment '/turtlesim/Ipc/Ipcexternal_elements'.
    {
      // Provided service instance '/turtlesim/Ipc/Provided/ProvidedIpcexternal_elements'
      ipc_protocol::ProvidedServiceInstanceServiceDiscoveryParams params{};
      params.ipc_offer_service_ttl_ = 200U;
      params.ipc_unicast_address_.ipc_unicast_domain_ = 1U;
      params.ipc_unicast_address_.ipc_unicast_port_ = 40005U;

      server_manager_.EmplaceProvidedServiceInstance(1U, 2U, 1U, 0U, params, ::apns::external_elements::ServiceIdentifier);
    }
    // Instantiate and register a skeleton factory for the service:
    // 'apns::external_elements
    apns::external_elements_ipc_skeleton_factory_.emplace(this->server_manager_);
    server_manager_.AddSkeletonFactory(apns::external_elements_ipc_skeleton_factory_.value());
  }
}

void AraComIpcBinding::InitializeRequiredServiceDeployments() {
  {
    // Instantiate required service instances for service deployment '/turtlesim/Ipc/Ipcdriving_information'.
    {
      // Required service instance '/turtlesim/Ipc/Required/RequiredIpcdriving_information'
      client_manager_.EmplaceRequiredServiceInstance(0U, 1U, 1U, ipc_protocol::kMinorVersionAny, ::apns::driving_information::ServiceIdentifier);
    }
  }

  {
    // Instantiate and register a proxy factory for the service:
    // 'apns::driving_information'
    apns::driving_information_ipc_proxy_factory_.emplace(client_manager_);
    client_manager_.AddProxyFactory(apns::driving_information_ipc_proxy_factory_.value());
  }

   // Send start find service message for the state machines.
   client_manager_.StartFindingService();
}

}  // namespace internal
}  // namespace ipc_binding
}  // namespace amsr

