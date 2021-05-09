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
/**        \file  AP_controller/includes/apns/impl_type_lanetype.h
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_IMPL_TYPE_LANETYPE_H_
#define AP_CONTROLLER_INCLUDES_APNS_IMPL_TYPE_LANETYPE_H_

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
 * \brief Type lanetype.
 * \remark generated
 * \trace SPEC-5951372
 *
 * IMPLEMENTATION-DATA-TYPE /turtlesim/ServiceDesign/datatype/lanetype
 */
struct lanetype {
  using _k_type = double;
  using _b_type = _k_type;

  _k_type k;
  _b_type b;
};

/*!
 * \brief Compare for equality with another lanetype instance.
 */
inline bool operator==(apns::lanetype const& l,
                       apns::lanetype const& r) noexcept {
  return (&l == &r) || (true
                        && (l.k == r.k)
                        && (l.b == r.b)
  );
}

/*!
 * \brief Compare for inequality with another lanetype instance.
 */
inline bool operator!=(apns::lanetype const& l,
                       apns::lanetype const& r) noexcept {
  return !(l == r);
}

}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_IMPL_TYPE_LANETYPE_H_
