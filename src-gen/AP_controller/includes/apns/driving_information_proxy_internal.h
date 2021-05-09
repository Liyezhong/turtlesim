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
/**        \file  AP_controller/includes/apns/driving_information_proxy_internal.h
 *        \brief  Proxy implementation interface of service 'driving_information'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_INTERNAL_H_
#define AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_INTERNAL_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/driving_information_types.h"
#include "ara/core/future.h"
#include "socal/internal/proxy_impl_event.h"

namespace apns {
namespace internal {


/*!
 * \brief Proxy HandleType for the Service 'driving_information'.
 * \trace SPEC-4980259
 */
class driving_informationHandleType final : public ::amsr::socal::internal::HandleType {
  public:
  /*!
   * \brief Inherit constructor.
   */
  using HandleType::HandleType;
};


/*!
 * \brief Proxy implementation interface for the Service 'driving_information'
 * \remark generated
 */
class driving_informationProxyImplInterface : public ::amsr::socal::internal::ProxyImplInterface {
 public:
  /*!
   * \brief Define default constructor.
   */
  driving_informationProxyImplInterface() = default;
  /*!
   * \brief Define default destructor.
   */
  virtual ~driving_informationProxyImplInterface() = default;
  /*!
   * \brief Delete copy constructor.
   */
  driving_informationProxyImplInterface(driving_informationProxyImplInterface const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  driving_informationProxyImplInterface(driving_informationProxyImplInterface &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  driving_informationProxyImplInterface &operator=(driving_informationProxyImplInterface const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  driving_informationProxyImplInterface &operator=(driving_informationProxyImplInterface &&) & = delete;

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Get the event manager object for the service event 'vehicle_speed'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::speedtype >* GetEventManagervehicle_speed() = 0;
  /*!
   * \brief Get the event manager object for the service event 'vehicle_position'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::locationtype >* GetEventManagervehicle_position() = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

} //namespace internal
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_INTERNAL_H_
