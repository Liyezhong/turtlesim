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
/**        \file  rosap_exe/someip-posix/ara/com/aracom_someip_binding_init.cpp
 *        \brief  ara::com SOME/IP binding initialization
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_someip
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_someip_skeleton_factory.h"
#include "ara/com/resource_manager.h"
#include "ara/core/optional.h"
#include "someip_binding/internal/aracom_someip_binding.h"

namespace amsr {
namespace someip_binding {
namespace internal {

/*!
 * \brief Literals namespace needed for StringView _sv literal.
 */
using namespace vac::container::literals;  // NOLINT(build/namespaces)

namespace apns {

/*!
 * \brief  Static instantiation of a skeleton factory for the service 'speed_control'.
 */
ara::core::Optional<::apns::someip_binding::internal::speed_controlSomeIpSkeletonFactory>
    speed_control_someip_skeleton_factory_;
}  // namespace apns



template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeInstanceSpecifierMappings(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  // ---- Register all known R-Port InstanceSpecifiers ----
  // No R-Ports configured

  // ---- Register all known P-Port InstanceSpecifiers ----

  // Map P-Port /turtlesim/Application_design/rosap_exe/rosap_converter/PPort_speed_control to instance /turtlesim/Someip/Provided/ProvidedSomeipSpeedControl
  instance_specifier_table.MapInstanceSpecifierToInstanceId(
      this, ::ara::core::InstanceSpecifier{"rosap_exe/cswc/PPort_speed_control"_sv},
      ::ara::com::InstanceIdentifier{"SomeIp:2"_sv},"/turtlesim/ServiceDesign/speed_control/speed_control"_sv);
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeServiceInterfaceProxyFactories() {
  // No required service interfaces configured
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeServiceInterfaceSkeletonFactories() {

  // Instantiate and register a skeleton factory for the service
  // 'apns::speed_control'.
  apns::speed_control_someip_skeleton_factory_.emplace(
      server_manager_, resource_manager_.GetResourceManager<::apns::speed_control>().GetSkeletonResourceManager());
  server_manager_.AddSkeletonFactory(apns::speed_control_someip_skeleton_factory_.value());
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeHook(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  InitializeInstanceSpecifierMappings(instance_specifier_table);

  // Initialize factories for service interface creation
  InitializeServiceInterfaceProxyFactories();
  InitializeServiceInterfaceSkeletonFactories();

  // Connect to the SOME/IP daemon
  someip_posix_.Connect();
}

}  // namespace internal
}  // namespace someip_binding
}  // namespace amsr

