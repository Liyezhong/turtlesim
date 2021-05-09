
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
/**        \file  AP_controller/includes/apns/external_elements_types.h
 *        \brief  Input and output structures for methods, fields and application errors of service 'external_elements'
 *
 *      \details  Definition of common input-/output structs used for simplified argument / marshalling handling. For all elements like methods, events fields structs with the related in-/output arguments are generated.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_api
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_TYPES_H_
#define AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_TYPES_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apns/external_elements_common.h"

namespace apns {

namespace internal {

namespace methods {

}  // namespace methods

namespace fields {

/*!
 * \brief Data class for service field 'lane'.
 * \remark generated
 */
class lane final {
 public:
  /*!
   * \brief Return/output parameters of service field 'lane'
   */
  using Output = apns::lanetype;
};


  /*!
 * \brief A class for field method 'lane'Get used for type definitions.
 */
class laneGet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {};

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/lanetype)
     */
    apns::lanetype out_val;
  };
};

/*!
 * \brief A class for field method 'lane'Set used for type definitions.
 */
class laneSet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/lanetype)
     */
    apns::lanetype in_val;

  };

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/lanetype)
     */
    apns::lanetype out_val;
  };
};

/*!
 * \brief Data class for service field 'object'.
 * \remark generated
 */
class object final {
 public:
  /*!
   * \brief Return/output parameters of service field 'object'
   */
  using Output = apns::locationtype;
};


  /*!
 * \brief A class for field method 'object'Get used for type definitions.
 */
class objectGet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {};

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/locationtype)
     */
    apns::locationtype out_val;
  };
};

/*!
 * \brief A class for field method 'object'Set used for type definitions.
 */
class objectSet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/locationtype)
     */
    apns::locationtype in_val;

  };

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/turtlesim/ServiceDesign/datatype/locationtype)
     */
    apns::locationtype out_val;
  };
};

}  // namespace fields
}  // namespace internal

}  //  namespace apns

#endif  // AP_CONTROLLER_INCLUDES_APNS_EXTERNAL_ELEMENTS_TYPES_H_

