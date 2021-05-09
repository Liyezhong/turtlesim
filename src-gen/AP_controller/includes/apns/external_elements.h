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
/**        \file  AP_controller/includes/apns/external_elements.h
 *        \brief  Header for service 'external_elements'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_resource_manager.h"
#include "ara/com/service_identifier.h"
#include "vac/container/c_string_view.h"
#include "vac/container/string_literals.h"

namespace apns {

/*!
 * \brief Literals namespace is needed for "_sv literal.
 */
using namespace vac::container::literals;  // NOLINT(build/namespaces)

/*!
 * \brief Representation of service 'external_elements'
 * \details Used for service-specific aspects:
 *  - Resource management
 *  - Service Identifier
 *
 * \trace SPEC-4980256
 */
class external_elements final {
 public:
  /*!
   * \brief Type-alias for easy access to CStringView.
   */
  using CStringView = vac::container::CStringView;

  /*!
   * \brief Type-alias for used resource manager for service 'external_elements'.
   */
  using ResourceManager = resources::external_elementsResourceManager;

  /*!
   * \brief Service Identifier.
   *
   * \trace SPEC-4980252, SPEC-4980256
   */
  static constexpr ara::com::ServiceIdentifierType ServiceIdentifier{CStringView{"external_elements"_sv}};

  /*!
   * \brief Service shortname path.
   */
  static constexpr CStringView kServiceShortNamePath{"/turtlesim/ServiceDesign/external_elements/external_elements"_sv};
};

}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_H_
