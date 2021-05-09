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
/**        \file  rosap_exe/includes/apns/impl_type_speedtype.h
 *        \brief
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_modelleddatatypes_api
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_SPEEDTYPE_H_
#define ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_SPEEDTYPE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "apns/impl_type_a_vel.h"
#include "apns/impl_type_l_vel.h"

namespace apns {

/*!
 * \brief Type speedtype.
 * \remark generated
 * \trace SPEC-5951372
 *
 * IMPLEMENTATION-DATA-TYPE /turtlesim/ServiceDesign/datatype/speedtype
 */
struct speedtype {
  using _l_vel_type = apns::l_vel;
  using _a_vel_type = apns::a_vel;

  _l_vel_type l_vel;
  _a_vel_type a_vel;
};

/*!
 * \brief Compare for equality with another speedtype instance.
 */
inline bool operator==(apns::speedtype const& l,
                       apns::speedtype const& r) noexcept {
  return (&l == &r) || (true
                        && (l.l_vel == r.l_vel)
                        && (l.a_vel == r.a_vel)
  );
}

/*!
 * \brief Compare for inequality with another speedtype instance.
 */
inline bool operator!=(apns::speedtype const& l,
                       apns::speedtype const& r) noexcept {
  return !(l == r);
}

}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_SPEEDTYPE_H_
