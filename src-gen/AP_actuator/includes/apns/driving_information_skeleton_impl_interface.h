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
/**        \file  AP_actuator/includes/apns/driving_information_skeleton_impl_interface.h
 *        \brief  Skeleton implementation interface of service 'driving_information'.
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

#ifndef AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_IMPL_INTERFACE_H_
#define AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_IMPL_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/driving_information_common.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/future.h"
#include "socal/internal/skeleton_impl_interface.h"


namespace apns {
namespace internal {

/*!
 * \brief Skeleton implementation interface for the Service 'driving_information'
 * \remark generated
 */
class driving_informationSkeletonImplInterface : public ::amsr::socal::internal::SkeletonImplInterface {
 public:
  /*!
   * \brief Define destructor
   */
  virtual ~driving_informationSkeletonImplInterface() = default;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Pure virtual interface for sending samples of service event 'vehicle_speed'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Event sample of type apns::speedtype
   */
  virtual void SendEventvehicle_speed(const apns::speedtype& data) = 0;

  /*!
   * \brief Pure virtual interface for sending samples of service event 'vehicle_position'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Event sample of type apns::locationtype
   */
  virtual void SendEventvehicle_position(const apns::locationtype& data) = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

} // namespace internal
}  // namespace apns

#endif  // AP_ACTUATOR_INCLUDES_APNS_DRIVING_INFORMATION_SKELETON_IMPL_INTERFACE_H_
