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
/**        \file  AP_controller/includes/apns/driving_information_proxy.h
 *        \brief  Proxy for service 'driving_information'.
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

#ifndef AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_H_
#define AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_H_

/*!
 * \trace SPEC-4980240
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/driving_information_common.h"
#include "apns/driving_information_proxy_internal.h"
#include "apns/driving_information_types.h"
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
 * \brief Type alias for service event 'vehicle_speed', that is part of the proxy.
 *
 * \trace SPEC-4980345 (Service proxy Event class)
 */
using vehicle_speed =
    ::amsr::socal::internal::ProxyEvent<apns::driving_information, apns::internal::driving_informationProxyImplInterface, apns::internal::driving_informationHandleType, apns::speedtype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::speedtype
                                                                      >,
                                   &apns::internal::driving_informationProxyImplInterface::GetEventManagervehicle_speed>;

/*!
 * \brief Type alias for service event 'vehicle_position', that is part of the proxy.
 *
 * \trace SPEC-4980345 (Service proxy Event class)
 */
using vehicle_position =
    ::amsr::socal::internal::ProxyEvent<apns::driving_information, apns::internal::driving_informationProxyImplInterface, apns::internal::driving_informationHandleType, apns::locationtype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::locationtype
                                                                      >,
                                   &apns::internal::driving_informationProxyImplInterface::GetEventManagervehicle_position>;

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {

}  // namespace fields

/*!
 * \brief Proxy class for the service 'driving_information'.
 * \vpublic
 *
 * \trace SPEC-4980344 (Service proxy class)
 */
class driving_informationProxy : public ::amsr::socal::internal::Proxy<apns::driving_information, apns::internal::driving_informationProxyImplInterface, apns::internal::driving_informationHandleType> {
 public:

  /*!
   * \brief Type alias for the ProxyImplInterface.
   */
  using ProxyImplInterface = apns::internal::driving_informationProxyImplInterface;

  /*!
   * \brief Constructor of driving_informationProxy. Constructor takes a handle returned by
   * driving_informationProxy::FindService() method or provided as parameter to the callback handler of
   * driving_informationProxy::StartFindService().
   *
   * \details Because of internal resource management strategy, all created proxies shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \param handle The identification of the service the proxy should represent. Handles are generated by synchronous
   * driving_informationProxy::FindService or asynchronous driving_informationProxy::StartFindService.
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
  explicit driving_informationProxy(HandleType const& handle);

  /*!
   * \brief Unregister the proxy from the communication middleware.
   *
   * \details This call will be blocked until all current events/methods' callbacks are finished/canceled.
   *
   * \vpublic
   */
  virtual ~driving_informationProxy();

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Proxy<apns::driving_information, ProxyImplInterface, apns::internal::driving_informationHandleType>;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;

 public:

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Event 'vehicle_speed' which can be used by application developer.
   * \details
   * Data of type apns::speedtype 
   * \vpublic
   */
  events::vehicle_speed vehicle_speed;

  /*!
   * \brief Event 'vehicle_position' which can be used by application developer.
   * \details
   * Data of type apns::locationtype 
   * \vpublic
   */
  events::vehicle_position vehicle_position;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
};

}  // namespace proxy
}  // namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_DRIVING_INFORMATION_PROXY_H_

