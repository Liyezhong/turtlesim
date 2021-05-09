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
/**        \file  AP_actuator/includes/apns/speed_control_proxy_internal.h
 *        \brief  Proxy implementation interface of service 'speed_control'.
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

#ifndef AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_INTERNAL_H_
#define AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_INTERNAL_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/speed_control_types.h"
#include "ara/core/future.h"
#include "socal/internal/proxy_impl_event.h"

namespace apns {
namespace internal {


/*!
 * \brief Proxy HandleType for the Service 'speed_control'.
 * \trace SPEC-4980259
 */
class speed_controlHandleType final : public ::amsr::socal::internal::HandleType {
  public:
  /*!
   * \brief Inherit constructor.
   */
  using HandleType::HandleType;
};


/*!
 * \brief Proxy implementation interface for the Service 'speed_control'
 * \remark generated
 */
class speed_controlProxyImplInterface : public ::amsr::socal::internal::ProxyImplInterface {
 public:
  /*!
   * \brief Define default constructor.
   */
  speed_controlProxyImplInterface() = default;
  /*!
   * \brief Define default destructor.
   */
  virtual ~speed_controlProxyImplInterface() = default;
  /*!
   * \brief Delete copy constructor.
   */
  speed_controlProxyImplInterface(speed_controlProxyImplInterface const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  speed_controlProxyImplInterface(speed_controlProxyImplInterface &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  speed_controlProxyImplInterface &operator=(speed_controlProxyImplInterface const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  speed_controlProxyImplInterface &operator=(speed_controlProxyImplInterface &&) & = delete;

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Get the event manager object for the service event 'LKA_speed'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::speedtype >* GetEventManagerLKA_speed() = 0;
  /*!
   * \brief Get the event manager object for the service event 'ToGoal_speed'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::speedtype >* GetEventManagerToGoal_speed() = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

} //namespace internal
}  // namespace apns

#endif  // AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_INTERNAL_H_
