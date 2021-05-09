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
/**        \file  AP_controller/includes/apns/external_elements_skeleton_impl_interface.h
 *        \brief  Skeleton implementation interface of service 'external_elements'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_IMPL_INTERFACE_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_IMPL_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/external_elements_common.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/future.h"
#include "socal/internal/skeleton_impl_interface.h"


namespace apns {
namespace internal {

/*!
 * \brief Skeleton implementation interface for the Service 'external_elements'
 * \remark generated
 */
class external_elementsSkeletonImplInterface : public ::amsr::socal::internal::SkeletonImplInterface {
 public:
  /*!
   * \brief Define destructor
   */
  virtual ~external_elementsSkeletonImplInterface() = default;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Pure virtual interface for updating service field 'lane'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Field data oof type apns::lanetype
   */
  virtual void UpdateFieldlane(apns::lanetype const& data) = 0;

  /*!
   * \brief Pure virtual interface for updating service field 'object'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Field data oof type apns::locationtype
   */
  virtual void UpdateFieldobject(apns::locationtype const& data) = 0;
};

} // namespace internal
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_SKELETON_IMPL_INTERFACE_H_
