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
/**        \file  rosap_exe/includes/apns/impl_type_locationtype.h
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

#ifndef ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_LOCATIONTYPE_H_
#define ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_LOCATIONTYPE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace apns {

/*!
 * \brief Type locationtype.
 * \remark generated
 * \trace SPEC-5951372
 *
 * IMPLEMENTATION-DATA-TYPE /turtlesim/ServiceDesign/datatype/locationtype
 */
struct locationtype {
  using _x_type = double;
  using _y_type = _x_type;
  using _theta_type = _x_type;

  _x_type x;
  _y_type y;
  _theta_type theta;
};

/*!
 * \brief Compare for equality with another locationtype instance.
 */
inline bool operator==(apns::locationtype const& l,
                       apns::locationtype const& r) noexcept {
  return (&l == &r) || (true
                        && (l.x == r.x)
                        && (l.y == r.y)
                        && (l.theta == r.theta)
  );
}

/*!
 * \brief Compare for inequality with another locationtype instance.
 */
inline bool operator!=(apns::locationtype const& l,
                       apns::locationtype const& r) noexcept {
  return !(l == r);
}

}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_IMPL_TYPE_LOCATIONTYPE_H_
