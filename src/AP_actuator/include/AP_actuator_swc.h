/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  client/main.cc
 *        \brief  Main entry point of the calculatorClient, used for testing the calulator service.
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#ifndef SRC_CLIENT_SOMEIP_SOMEIP_CALCULATOR_CLIENT_H_
#define SRC_CLIENT_SOMEIP_SOMEIP_CALCULATOR_CLIENT_H_

#include <atomic>
#include <chrono>
#include <memory>
#include <string>
#include <thread>

#include "ara/com/runtime.h"
#include "ara/com/types.h"
#include "ara/core/future.h"
#include "ara/log/logging.h"
#include "apns/speed_control.h"
#include "apns/speed_control_proxy.h"
#include "apns/driving_information.h"
#include "apns/driving_information_skeleton.h"


namespace apns {

/*!
 * \brief APClient of turtle.
 */
    class AP_actuator_swc {
    public:
        /*!
         * \brief Delete default constructor.
         */
        AP_actuator_swc() = delete;

        /*!
         * \brief Delete destructor.
         */
        virtual ~AP_actuator_swc() = delete;

        /*!
         * \brief Function is searching for one calculator service provider
         */
        static void FindService();

        /*!
         * \brief Function is calling the method divide with the given parameters
         * \param operand1 Is the dividend
         * \param operand2 Is the divisor
         */
/*  static ara::core::Future<vector::calculatorservice::proxy::methods::divide::Output> CallDivide(
      std::uint32_t operand1, std::uint32_t operand2);*/

        /*!
         * \brief Function is calling the method add with the given parameters
         * \param operand1 Is the addend1
         * \param operand2 Is the addend2
         */
/*  static ara::core::Future<vector::calculatorservice::proxy::methods::add::Output> CallAdd(std::uint32_t operand1,
          *//*                                                                                 std::uint32_t operand2);*/

        /*!
         * \brief Function is calling the method add with the given parameters
         * \param operand1 Is the minuend
         * \param operand2 Is the subtrahend
         */
/*  static ara::core::Future<vector::calculatorservice::proxy::methods::subtract::Output> CallSubtract(
      std::uint32_t operand1, std::uint32_t operand2);*/

        /*!
         * \brief Function is subscribing the division results and the devision by zero.
         */
        static void SubscribeToEvents(std::function<void()> callback);

        /*!
         * \brief Function is unsubscribing the division results and the devision by zero.
         */
        static void UnsubscribeToEvents();

        /*!
         * \brief Function is returning the last division result.
         */
        /*static vector::calculatorservice::proxy::fields::divideResult::FieldType GetLastDevideResultFromField();
      */
        /*!
         * \brief Function is setting the last division result to an given value.
         * \param input Is the value the last division result will be set to.
         */
        /* static void SetLastDivideResult(vector::calculatorservice::proxy::fields::divideResult::FieldType input);
       */
        /*!
         * \brief  Function gets called when a calculatorService instance is found
         * \param  calculator_services Contains all found calculatorService instances
         */
        static void FindServiceHandler(
                ara::com::ServiceHandleContainer<apns::proxy::speed_controlProxy::HandleType>
                speedcontrol_services);

        /*!
         * \brief  Function gets called when a divisionByZero event occurs
         */
        /*static void DivisionByZeroHandler(void);*/

        /*!
         * \brief  Function gets called when a divideResult notify event occurs
         *         (everytime the server instance writes to the divideResult field).
         */
/*
  static void DivideResultHandler(void);
*/

        /*!
         * \brief Function returns the devide result
         */
/*
  static std::uint32_t GetDivideResult(void);
*/
/*        static void LKAEventHandler(boost::shared_ptr<turtlesim::Turtle> destturtle);*/
        /*!
         * \brief Function initializes the ara::com::Runtime
         */
        static void Initialize(std::string cfg_path_);

        /*!
         * \brief Flag to indicate if an service provider was found
         */
        static std::atomic<bool> ToGoSpeedcontrol_server_found;
        static std::atomic<bool> LKASpeedcontrol_server_found;
        static std::atomic<bool> LKAreplicaSpeedcontrol_server_found;

        /*!
         * \brief Flag to indicate whether a divider event was received
         */
        static std::atomic<bool> lka_event_receive;
        static std::atomic<bool> ToGoal_subscribed;

        /*!
         * \brief Shared pointer holding the calculator_service_proxy
         */
        static std::shared_ptr<apns::proxy::speed_controlProxy> ToGospeed_control_proxy;
        static std::shared_ptr<apns::proxy::speed_controlProxy> LKA_control_proxy;

        static std::shared_ptr<apns::skeleton::driving_informationSkeleton> drinfo_skeleton;

        static void Sendvehicle_speed(double l_vel,double a_vel);
        static void HandleToPortThenCS(apns::proxy::speed_controlProxy::HandleType& handle);
        /**
         * \brief Holds the logging context
         */
        static ara::log::Logger &GetLogger();
    };

}  // namespace apns

#endif  // SRC_CLIENT_SOMEIP_SOMEIP_CALCULATOR_CLIENT_H_
