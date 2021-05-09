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
/**        \file  rosap_exe/includes/apns/speed_control_skeleton_impl_interface.h
 *        \brief  Skeleton implementation interface of service 'speed_control'.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_IMPL_INTERFACE_H_
#define ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_IMPL_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/speed_control_common.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/future.h"
#include "socal/internal/skeleton_impl_interface.h"


namespace apns {
namespace internal {

/*!
 * \brief Skeleton implementation interface for the Service 'speed_control'
 * \remark generated
 */
class speed_controlSkeletonImplInterface : public ::amsr::socal::internal::SkeletonImplInterface {
 public:
  /*!
   * \brief Define destructor
   */
  virtual ~speed_controlSkeletonImplInterface() = default;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Pure virtual interface for sending samples of service event 'LKA_speed'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Event sample of type apns::speedtype
   */
  virtual void SendEventLKA_speed(const apns::speedtype& data) = 0;

  /*!
   * \brief Pure virtual interface for sending samples of service event 'ToGoal_speed'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Event sample of type apns::speedtype
   */
  virtual void SendEventToGoal_speed(const apns::speedtype& data) = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

} // namespace internal
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_SPEED_CONTROL_SKELETON_IMPL_INTERFACE_H_
