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
/**        \file  AP_actuator/includes/apns/speed_control_proxy.h
 *        \brief  Proxy for service 'speed_control'.
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

#ifndef AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_H_
#define AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_H_

/*!
 * \trace SPEC-4980240
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/speed_control_common.h"
#include "apns/speed_control_proxy_internal.h"
#include "apns/speed_control_types.h"
#include "ara/com/runtime.h"
#include "socal/internal/fields/proxy_field.h"
#include "socal/internal/find_service_observers_manager.h"
#include "socal/internal/handle_type.h"
#include "socal/internal/methods/proxy_method.h"
#include "socal/internal/proxy.h"
#include "socal/internal/proxy_event.h"

/*!
 * \trace SPEC-4980240
 */
namespace apns {

/*!
 * \trace SPEC-4980242
 */
namespace proxy {

/*!
 * \trace SPEC-4980244
 */
namespace methods {

}  // namespace methods

/*!
 * \trace SPEC-4980243
 */
namespace events {

/*!
 * \brief Type alias for service event 'LKA_speed', that is part of the proxy.
 *
 * \trace SPEC-4980345 (Service proxy Event class)
 */
using LKA_speed =
    ::amsr::socal::internal::ProxyEvent<apns::speed_control, apns::internal::speed_controlProxyImplInterface, apns::internal::speed_controlHandleType, apns::speedtype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::speedtype
                                                                      >,
                                   &apns::internal::speed_controlProxyImplInterface::GetEventManagerLKA_speed>;

/*!
 * \brief Type alias for service event 'ToGoal_speed', that is part of the proxy.
 *
 * \trace SPEC-4980345 (Service proxy Event class)
 */
using ToGoal_speed =
    ::amsr::socal::internal::ProxyEvent<apns::speed_control, apns::internal::speed_controlProxyImplInterface, apns::internal::speed_controlHandleType, apns::speedtype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::speedtype
                                                                      >,
                                   &apns::internal::speed_controlProxyImplInterface::GetEventManagerToGoal_speed>;

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {

}  // namespace fields

/*!
 * \brief Proxy class for the service 'speed_control'.
 * \vpublic
 *
 * \trace SPEC-4980344 (Service proxy class)
 */
class speed_controlProxy : public ::amsr::socal::internal::Proxy<apns::speed_control, apns::internal::speed_controlProxyImplInterface, apns::internal::speed_controlHandleType> {
 public:

  /*!
   * \brief Type alias for the ProxyImplInterface.
   */
  using ProxyImplInterface = apns::internal::speed_controlProxyImplInterface;

  /*!
   * \brief Constructor of speed_controlProxy. Constructor takes a handle returned by
   * speed_controlProxy::FindService() method or provided as parameter to the callback handler of
   * speed_controlProxy::StartFindService().
   *
   * \details Because of internal resource management strategy, all created proxies shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \param handle The identification of the service the proxy should represent. Handles are generated by synchronous
   * speed_controlProxy::FindService or asynchronous speed_controlProxy::StartFindService.
   * The handle object passed as a parameter shall be a handle returned by a FindService call for this specific service.
   * Passing handles from different services is currently possible, but is detected. An exception is raised as documented below.
   *
   * \throws ara::com::ComException (ComErrc::unknown_instance_identifier) If the InstanceIdentifier could not be resolved.
   * \throws std::bad_alloc if the proxy backend could not be spawned.
   * \throws std::bad_cast if the given handle object does not match the handle of the service and thus a dynamic_cast to the concrete
   * service type fails.
   *
   * \vpublic
   * \trace SPEC-4980371 (Creation of service proxy)
   */
  explicit speed_controlProxy(HandleType const& handle);

  /*!
   * \brief Unregister the proxy from the communication middleware.
   *
   * \details This call will be blocked until all current events/methods' callbacks are finished/canceled.
   *
   * \vpublic
   */
  virtual ~speed_controlProxy();

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Proxy<apns::speed_control, ProxyImplInterface, apns::internal::speed_controlHandleType>;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;

 public:

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Event 'LKA_speed' which can be used by application developer.
   * \details
   * Data of type apns::speedtype 
   * \vpublic
   */
  events::LKA_speed LKA_speed;

  /*!
   * \brief Event 'ToGoal_speed' which can be used by application developer.
   * \details
   * Data of type apns::speedtype 
   * \vpublic
   */
  events::ToGoal_speed ToGoal_speed;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

}  // namespace proxy
}  // namespace apns

#endif  // AP_ACTUATOR_INCLUDES_APNS_SPEED_CONTROL_PROXY_H_

