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
/**        \file  rosap_exe/includes/apns/external_elements_proxy_internal.h
 *        \brief  Proxy implementation interface of service 'external_elements'.
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

#ifndef ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_INTERNAL_H_
#define ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_INTERNAL_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_types.h"
#include "ara/core/future.h"
#include "socal/internal/proxy_impl_event.h"

namespace apns {
namespace internal {


/*!
 * \brief Proxy HandleType for the Service 'external_elements'.
 * \trace SPEC-4980259
 */
class external_elementsHandleType final : public ::amsr::socal::internal::HandleType {
  public:
  /*!
   * \brief Inherit constructor.
   */
  using HandleType::HandleType;
};


/*!
 * \brief Proxy implementation interface for the Service 'external_elements'
 * \remark generated
 */
class external_elementsProxyImplInterface : public ::amsr::socal::internal::ProxyImplInterface {
 public:
  /*!
   * \brief Define default constructor.
   */
  external_elementsProxyImplInterface() = default;
  /*!
   * \brief Define default destructor.
   */
  virtual ~external_elementsProxyImplInterface() = default;
  /*!
   * \brief Delete copy constructor.
   */
  external_elementsProxyImplInterface(external_elementsProxyImplInterface const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  external_elementsProxyImplInterface(external_elementsProxyImplInterface &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  external_elementsProxyImplInterface &operator=(external_elementsProxyImplInterface const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  external_elementsProxyImplInterface &operator=(external_elementsProxyImplInterface &&) & = delete;

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /* ---- Field 'lane' ---- */
  /*!
   * \brief Get the field notifier object for the service field 'lane'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::lanetype>*
  GetFieldNotifierlane() = 0;

  /*!
   * \brief Getter for the field 'lane'
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::lane::Output> FieldlaneMethodGet() = 0;

  /*!
   * \brief Setter for the field 'lane'
   * \param value Field value of type apns::lanetype ()
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::lane::Output> FieldlaneMethodSet(const apns::lanetype& value) = 0;

  /* ---- Field 'object' ---- */
  /*!
   * \brief Get the field notifier object for the service field 'object'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<apns::locationtype>*
  GetFieldNotifierobject() = 0;

  /*!
   * \brief Getter for the field 'object'
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::object::Output> FieldobjectMethodGet() = 0;

  /*!
   * \brief Setter for the field 'object'
   * \param value Field value of type apns::locationtype ()
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::object::Output> FieldobjectMethodSet(const apns::locationtype& value) = 0;
};

} //namespace internal
}  // namespace apns

#endif  // ROSAP_EXE_INCLUDES_APNS_EXTERNAL_ELEMENTS_PROXY_INTERNAL_H_
