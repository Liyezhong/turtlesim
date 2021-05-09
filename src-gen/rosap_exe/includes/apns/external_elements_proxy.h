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
/**        \file  rosap_exe/includes/apns/external_elements_proxy.h
 *        \brief  Proxy for service 'external_elements'.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_H_
#define ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_H_

/*!
 * \trace SPEC-4980240
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "apns/external_elements_common.h"
#include "apns/external_elements_proxy_internal.h"
#include "apns/external_elements_types.h"
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

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {
/* ---- Type aliases for field 'lane' ---- */

/*!
 * \brief Type alias for the notifier of service field 'lane'.
 */
using FieldNotifierlane =
    ::amsr::socal::internal::ProxyEvent<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::lanetype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::lanetype
                                   >,
                                   &apns::internal::external_elementsProxyImplInterface::GetFieldNotifierlane>;
/*!
 * \brief Type alias for the notifier configuration of field 'lane'.
 */
using FieldNotifierConfiglane = ::amsr::socal::internal::fields::ProxyFieldParams::HasNotifier<true, FieldNotifierlane>;
/*!
 * \brief Type alias for the getter method of service field 'lane'.
 */
using FieldMethodGetlane = ::amsr::socal::internal::methods::MethodParameters<void>::ProxyMethod<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::internal::fields::lane, &apns::internal::external_elementsProxyImplInterface::FieldlaneMethodGet>;

/*!
 * \brief Type alias for the getter configuration of field 'lane'.
 */
using FieldGetterConfiglane = ::amsr::socal::internal::fields::ProxyFieldParams::HasGetter<true, FieldMethodGetlane>;

/*!
 * \brief Type alias for the setter method of service field 'lane'.
 */
using FieldMethodSetlane = ::amsr::socal::internal::methods::MethodParameters<const apns::lanetype&>::ProxyMethod<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::internal::fields::lane, &apns::internal::external_elementsProxyImplInterface::FieldlaneMethodSet>;
/*!
 * \brief Type alias for the setter configuration of field 'lane'.
 */
using FieldSetterConfiglane = ::amsr::socal::internal::fields::ProxyFieldParams::HasSetter<true, FieldMethodSetlane>;

/*!
 * \brief Field name.
 */
struct laneName {
  /*!
   * \brief Field name string.
   */
  static constexpr vac::container::CStringView Name = "lane"_sv;
};

/*!
 * \brief Type alias for the parameterization of field 'lane'.
 */
using FieldConfiglane = ::amsr::socal::internal::fields::ProxyFieldConfig<apns::internal::external_elementsProxyImplInterface, FieldNotifierConfiglane, FieldGetterConfiglane, FieldSetterConfiglane, laneName>;

/*!
 * \brief Type alias for the field 'lane'.
 *
 * \trace SPEC-5951150 (Service proxy field class)
 */
using lane =
    ::amsr::socal::internal::fields::ProxyField<apns::external_elements, apns::internal::external_elementsHandleType, apns::lanetype, FieldConfiglane>;
/* ---- Type aliases for field 'object' ---- */

/*!
 * \brief Type alias for the notifier of service field 'object'.
 */
using FieldNotifierobject =
    ::amsr::socal::internal::ProxyEvent<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::locationtype,
                                   ::amsr::socal::internal::ProxyImplEvent<apns::locationtype
                                   >,
                                   &apns::internal::external_elementsProxyImplInterface::GetFieldNotifierobject>;
/*!
 * \brief Type alias for the notifier configuration of field 'object'.
 */
using FieldNotifierConfigobject = ::amsr::socal::internal::fields::ProxyFieldParams::HasNotifier<true, FieldNotifierobject>;
/*!
 * \brief Type alias for the getter method of service field 'object'.
 */
using FieldMethodGetobject = ::amsr::socal::internal::methods::MethodParameters<void>::ProxyMethod<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::internal::fields::object, &apns::internal::external_elementsProxyImplInterface::FieldobjectMethodGet>;

/*!
 * \brief Type alias for the getter configuration of field 'object'.
 */
using FieldGetterConfigobject = ::amsr::socal::internal::fields::ProxyFieldParams::HasGetter<true, FieldMethodGetobject>;

/*!
 * \brief Type alias for the setter method of service field 'object'.
 */
using FieldMethodSetobject = ::amsr::socal::internal::methods::MethodParameters<const apns::locationtype&>::ProxyMethod<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType, apns::internal::fields::object, &apns::internal::external_elementsProxyImplInterface::FieldobjectMethodSet>;
/*!
 * \brief Type alias for the setter configuration of field 'object'.
 */
using FieldSetterConfigobject = ::amsr::socal::internal::fields::ProxyFieldParams::HasSetter<true, FieldMethodSetobject>;

/*!
 * \brief Field name.
 */
struct objectName {
  /*!
   * \brief Field name string.
   */
  static constexpr vac::container::CStringView Name = "object"_sv;
};

/*!
 * \brief Type alias for the parameterization of field 'object'.
 */
using FieldConfigobject = ::amsr::socal::internal::fields::ProxyFieldConfig<apns::internal::external_elementsProxyImplInterface, FieldNotifierConfigobject, FieldGetterConfigobject, FieldSetterConfigobject, objectName>;

/*!
 * \brief Type alias for the field 'object'.
 *
 * \trace SPEC-5951150 (Service proxy field class)
 */
using object =
    ::amsr::socal::internal::fields::ProxyField<apns::external_elements, apns::internal::external_elementsHandleType, apns::locationtype, FieldConfigobject>;

}  // namespace fields

/*!
 * \brief Proxy class for the service 'external_elements'.
 * \vpublic
 *
 * \trace SPEC-4980344 (Service proxy class)
 */
class external_elementsProxy : public ::amsr::socal::internal::Proxy<apns::external_elements, apns::internal::external_elementsProxyImplInterface, apns::internal::external_elementsHandleType> {
 public:

  /*!
   * \brief Type alias for the ProxyImplInterface.
   */
  using ProxyImplInterface = apns::internal::external_elementsProxyImplInterface;

  /*!
   * \brief Constructor of external_elementsProxy. Constructor takes a handle returned by
   * external_elementsProxy::FindService() method or provided as parameter to the callback handler of
   * external_elementsProxy::StartFindService().
   *
   * \details Because of internal resource management strategy, all created proxies shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \param handle The identification of the service the proxy should represent. Handles are generated by synchronous
   * external_elementsProxy::FindService or asynchronous external_elementsProxy::StartFindService.
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
  explicit external_elementsProxy(HandleType const& handle);

  /*!
   * \brief Unregister the proxy from the communication middleware.
   *
   * \details This call will be blocked until all current events/methods' callbacks are finished/canceled.
   *
   * \vpublic
   */
  virtual ~external_elementsProxy();

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Proxy<apns::external_elements, ProxyImplInterface, apns::internal::external_elementsHandleType>;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;

 public:

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Field 'lane' which can be used by application developer.
   * \details
   * Data of type apns::lanetype 
   * \vpublic
   */
  fields::lane lane;

  /*!
   * \brief Field 'object' which can be used by application developer.
   * \details
   * Data of type apns::locationtype 
   * \vpublic
   */
  fields::object object;
};

}  // namespace proxy
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_H_

