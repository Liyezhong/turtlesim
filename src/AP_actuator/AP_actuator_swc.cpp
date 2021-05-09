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
 *        \brief  Main entry point of the lkaClient, used for testing the calulator service.
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "include/AP_actuator_swc.h"
#include "ara/core/instance_specifier.h"
#include "vac/container/string_literals.h"
#include "include/turtle.h"
#include "include/turtle_frame.h"

using vac::container::literals::operator ""_sv;
extern turtlesim::TurtleFrame *Framept;

static ara::com::InstanceIdentifier const ToGoServiceInstance{
        "SomeIp:2"_sv};
static ara::com::InstanceIdentifier const LKAInstance{
        "SomeIp:1"_sv};
/* ToGoSpeedcontrol_server_found;
 LKASpeedcontrol_server_found;*/
static std::shared_ptr<std::shared_ptr<apns::proxy::speed_controlProxy>> thistypeProxyPtrPtr;
static std::shared_ptr<std::atomic<bool>> thisflagptr;
namespace apns {

    /*std::atomic<bool> AP_actuator_swc::ToGoSpeedcontrol_server_found{false};
    std::atomic<bool> AP_actuator_swc::ToGoal_subscribed{false};
    std::atomic<bool> AP_actuator_swc::lka_event_received{false};*/
    std::shared_ptr<apns::proxy::speed_controlProxy>
            AP_actuator_swc::ToGospeed_control_proxy = 0;
    std::shared_ptr<apns::skeleton::driving_informationSkeleton>
            AP_actuator_swc::drinfo_skeleton = 0;
    std::shared_ptr<apns::proxy::speed_controlProxy> AP_actuator_swc::LKA_control_proxy = 0;
    std::atomic<bool> AP_actuator_swc::ToGoSpeedcontrol_server_found{0};
    std::atomic<bool> AP_actuator_swc::LKASpeedcontrol_server_found = {0};
    std::atomic<bool> AP_actuator_swc::ToGoal_subscribed{0};


    ara::log::Logger &AP_actuator_swc::GetLogger() {
        static ara::log::Logger &logger{ara::log::CreateLogger("atuator", "Context for SOMEIP atua client")};
        return logger;
    }

    void AP_actuator_swc::FindService() {
        // Search for lkaService. When a lkaService instance is found, the function FindServiceHandler gets
        // called
        GetLogger().LogInfo() << "constructor skeleton ";

        ara::core::InstanceSpecifier const dinfo_port{
                "AP_actuator/actuator/driving_information"_sv};
        AP_actuator_swc::drinfo_skeleton = std::make_shared<apns::skeleton::driving_informationSkeleton>(dinfo_port);
        GetLogger().LogInfo() << "offer drivingInfo service ";
        AP_actuator_swc::drinfo_skeleton->OfferService();
        GetLogger().LogInfo() << "Searching for lkaService";
        ara::core::InstanceSpecifier const speedcontrol_client_port{
                "AP_actuator/actuator/speed_control"_sv};

        ara::com::FindServiceHandle find_service_handle =
                apns::proxy::speed_controlProxy::StartFindService(FindServiceHandler,
                                                                  speedcontrol_client_port);

        // Wait until lkaSerice is found
        /* while (!AP_actuator_swc::ToGoSpeedcontrol_server_found.load(std::memory_order_seq_cst)) {
             std::this_thread::sleep_for(std::chrono::milliseconds(100));
         }*/
        // Stop searching for further services
        /* apns::proxy::LKAProxy::StopFindService(find_service_handle);*/
    }

/*    ara::core::Future<vector::lkaservice::proxy::methods::divide::Output> AP_actuator_swc::CallDivide(
            std::uint32_t operand1, std::uint32_t operand2) {
        ara::core::Future<vector::lkaservice::proxy::methods::divide::Output> divide_future =
                AP_actuator_swc::ToGospeed_control_proxy->divide(operand1, operand2);
        return divide_future;
    }*/

/*    ara::core::Future<vector::lkaservice::proxy::methods::add::Output> AP_actuator_swc::CallAdd(
            std::uint32_t operand1, std::uint32_t operand2) {
        auto add_future = AP_actuator_swc::ToGospeed_control_proxy->add(operand1, operand2);
        return add_future;
    }*/

    /*  ara::core::Future<vector::lkaservice::proxy::methods::subtract::Output> AP_actuator_swc::CallSubtract(
              std::uint32_t operand1, std::uint32_t operand2) {
          auto subtract_future = AP_actuator_swc::ToGospeed_control_proxy->subtract(operand1, operand2);
          return subtract_future;
      }
  */
/*
    void AP_actuator_swc::DivisionByZeroHandler(void) { GetLogger().LogError() << "Division by zero!"; }
*/

/*    void AP_actuator_swc::LKAEventHandler(boost::shared_ptr<turtlesim::Turtle> destturtle) {
        // Check if new events are placed into the local cache

        if (ToGospeed_control_proxy->lka_event.Update()) {
            double x = (**(ToGospeed_control_proxy->lka_event.GetCachedSamples().begin())).lvl;
            double y = 0;
            double agv = (**(ToGospeed_control_proxy->lka_event.GetCachedSamples().begin())).avl;
            GetLogger().LogInfo() << "Last event is: linear vel"
                                  << x << "angular vel"
                                  << agv;
//            AP_actuator_swc::divide_event_received = true;

            destturtle->setVel(x, y, agv);
        }
    }*/

    /*  std::uint32_t AP_actuator_swc::GetDivideResult() {
          return **(ToGospeed_control_proxy->divideResult.GetCachedSamples().begin());
      }
  */
//    void AP_actuator_swc::SubscribeToEvents(std::function<void ()> callback) {
//        // Subscribe to events and set handlers
//        AP_actuator_swc::ToGospeed_control_proxy->LKA_speed.SetReceiveHandler(
//                callback);
//        AP_actuator_swc::ToGospeed_control_proxy->LKA_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
//                                                                1);
//
//        /**// Subscribe to divideResult field (notify event)
//        AP_actuator_swc::ToGospeed_control_proxy->divideResult.SetReceiveHandler([]() { DivideResultHandler(); });
//        AP_actuator_swc::ToGospeed_control_proxy->divideResult.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN, 1);*/
//    }

    void AP_actuator_swc::UnsubscribeToEvents() {
        // Unsubscribe from divisionByZero event
        AP_actuator_swc::ToGospeed_control_proxy->LKA_speed.Unsubscribe();
        AP_actuator_swc::drinfo_skeleton->StopOfferService();
        // Unsubscribe from divideResult field notify event
//        ToGospeed_control_proxy->divideResult.Unsubscribe();
        ToGospeed_control_proxy.reset();
    }

    /* void AP_actuator_swc*/

    /*apns::proxy::fields::divideResult::FieldType
    AP_actuator_swc::GetLastDevideResultFromField() {
        return ToGospeed_control_proxy->divideResult.Get().get();
    }*/

    /*  void AP_actuator_swc::SetLastDivideResult(
              vector::lkaservice::proxy::fields::divideResult::FieldType input) {
          ToGospeed_control_proxy->divideResult.Set(input);
      }*/

    void AP_actuator_swc::FindServiceHandler(
            ara::com::ServiceHandleContainer<apns::proxy::speed_controlProxy::HandleType>
            speedcontrol_services) {
        if (speedcontrol_services.size() == 0) {
            GetLogger().LogInfo() << "No speedService instance found";
            AP_actuator_swc::ToGoSpeedcontrol_server_found.store(false);
            AP_actuator_swc::LKASpeedcontrol_server_found.store(0);

            return;
        } else {
            for (auto handle:speedcontrol_services) {
                GetLogger().LogInfo() << speedcontrol_services.size() << " speedService instance found";

                AP_actuator_swc::HandleToPortThenCS(handle);
            }
            // The example doesn't handle this case
            GetLogger().LogInfo() << "Found multiple instances of SpeedControlService";

        }
        GetLogger().LogInfo()<<"LKAstates "<< static_cast<int>(LKA_control_proxy->LKA_speed.GetSubscriptionState());
        GetLogger().LogInfo()<<"ToGostates "<<static_cast<int>(ToGospeed_control_proxy->ToGoal_speed.GetSubscriptionState());

    }

    void AP_actuator_swc::Initialize(std::string cfg_path_) {
        ara::com::Runtime::getInstance().Initialize(cfg_path_);
    }

    void AP_actuator_swc::Sendvehicle_speed(double l_veli, double a_veli) {
        apns::speedtype data{l_veli, a_veli};
        AP_actuator_swc::drinfo_skeleton->vehicle_speed.Send(data);
    }

    void AP_actuator_swc::HandleToPortThenCS(apns::proxy::speed_controlProxy::HandleType &handle) {
        if (handle.GetInstanceId() == ToGoServiceInstance) {
            GetLogger().LogInfo() << "this handle is ToGO" << handle.GetInstanceId().ToString();
            AP_actuator_swc::ToGospeed_control_proxy =
                    std::make_shared<apns::proxy::speed_controlProxy>(handle);
            GetLogger().LogInfo() << "toGO ptr" << ToGospeed_control_proxy.get();
            ToGoSpeedcontrol_server_found = 1;
            if (ToGoSpeedcontrol_server_found && ToGospeed_control_proxy.get()) {
                ToGospeed_control_proxy->ToGoal_speed.SetReceiveHandler([]() {
                    if (ToGospeed_control_proxy->ToGoal_speed.Update()) {
                        double x = (**(ToGospeed_control_proxy->ToGoal_speed.GetCachedSamples().begin())).l_vel;
                        double y = 0;
                        double a = (**(ToGospeed_control_proxy->ToGoal_speed.GetCachedSamples().begin())).a_vel;
                        GetLogger().LogInfo() << "Last ToGO event is: linear vel"
                                              << x << " angular vel "
                                              << a;
                        Framept->getexistnturtle()->setVel(x, y, a);
                    }

                });
                ToGospeed_control_proxy->ToGoal_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN, 1);
            }
        } else if (handle.GetInstanceId() == LKAInstance) {
            GetLogger().LogInfo() << "this handle is LKA" << handle.GetInstanceId().ToString();
            AP_actuator_swc::LKA_control_proxy =
                    std::make_shared<apns::proxy::speed_controlProxy>(handle);
            GetLogger().LogInfo() << "LKA ptr" << LKA_control_proxy.get();
            LKASpeedcontrol_server_found = 1;
            if (LKASpeedcontrol_server_found && LKA_control_proxy.get()) {
                LKA_control_proxy->LKA_speed.SetReceiveHandler([]() {
                    if (LKA_control_proxy->LKA_speed.Update()) {
                        double x = (**(LKA_control_proxy->LKA_speed.GetCachedSamples().begin())).l_vel;
                        double y = 0;
                        double a = (**(LKA_control_proxy->LKA_speed.GetCachedSamples().begin())).a_vel;
                        GetLogger().LogInfo() << "Last LKA event is: linear vel"
                                              << x << " angular vel "
                                              << a;
                        Framept->getexistnturtle()->setVel(x, y, a);
                    }
                });
                LKA_control_proxy->LKA_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN, 1);
            }
        }


    }

/*
    void AP_actuator_swc::HandleToPortThenCS(apns::proxy::speed_controlProxy::HandleType &handle) {

        if (handle.GetInstanceId() == ToGoServiceInstance) {

            GetLogger().LogInfo() << "Found one ToGospeedService instance " << ToGoServiceInstance.ToString();
            // Get proxy instance
            */
/*AP_actuator_swc::ToGospeed_control_proxy =
                    std::make_shared<apns::proxy::speed_controlProxy>(handle);
            GetLogger().LogInfo() << "CONSTRUCTED ToGospeedService proxy";

            AP_actuator_swc::ToGoSpeedcontrol_server_found.store(true);
            AP_actuator_swc::ToGospeed_control_proxy->LKA_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                                                                          1);
            GetLogger().LogInfo() << "subscribe ToGospeedServiceProxy";
            AP_actuator_swc::ToGospeed_control_proxy->ToGoal_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                                                                             1);
            ToGospeed_control_proxy->ToGoal_speed.SetReceiveHandler(
                    [](){
                        if (ToGospeed_control_proxy->ToGoal_speed.Update()) {
                            double x = (**(ToGospeed_control_proxy->ToGoal_speed.GetCachedSamples().begin())).l_vel;
                            double y = 0;
                            double a = (**(ToGospeed_control_proxy->ToGoal_speed.GetCachedSamples().begin())).a_vel;
                            GetLogger().LogInfo() << "Last event is: linear vel"
                                                  << x << " angular vel "
                                                  << a;
//            AP_actuator_swc::divide_event_received = true;

                            Framept->getexistnturtle()->setVel(x, y, a);*//*

            thistypeProxyPtrPtr = std::make_shared<std::shared_ptr<apns::proxy::speed_controlProxy>>(
                    AP_actuator_swc::ToGospeed_control_proxy);
//            GetLogger().LogInfo() << "Found one ToGospeedService instance1 " << ToGoServiceInstance.ToString();
            AP_actuator_swc::ToGoSpeedcontrol_server_found.store(1);

//            thisflagptr=std::make_shared<std::atomic<bool >>(AP_actuator_swc::ToGoSpeedcontrol_server_found);
//            GetLogger().LogInfo() << "Found one ToGospeedService instance2 " << ToGoServiceInstance.ToString();
        } else if (handle.GetInstanceId() == LKAInstance) {

            GetLogger().LogInfo() << "Found one LKAService instance " << handle.GetInstanceId().ToString();
            thistypeProxyPtrPtr = std::make_shared<std::shared_ptr<apns::proxy::speed_controlProxy>>(
                    AP_actuator_swc::LKA_control_proxy);
//            thisflagptr.reset(&AP_actuator_swc::ToGoSpeedcontrol_server_found);
            AP_actuator_swc::LKASpeedcontrol_server_found.store(1);

        } else {
            GetLogger().LogInfo() << "unknown ServiceHandle " << handle.GetInstanceId().ToString();

        }

        *(thistypeProxyPtrPtr) = {std::make_shared<apns::proxy::speed_controlProxy>(handle)};

*/
/*
        AP_actuator_swc::ToGoSpeedcontrol_server_found.store(1);
*//*


        GetLogger().LogInfo() << __FUNCTION__ << __LINE__ << "  subscribe Event" << handle.GetInstanceId().ToString();
        if (handle.GetInstanceId() == ToGoServiceInstance) {
            thistypeProxyPtrPtr.get()->get()->ToGoal_speed.
                    Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                              1);
            GetLogger().LogInfo() << __FUNCTION__ << __LINE__ << "  subscribe ToGoal Event"
                                  << handle.GetInstanceId().ToString();
            thistypeProxyPtrPtr.get()->get()->ToGoal_speed.SetReceiveHandler(
                    []() {
                        if ((*thistypeProxyPtrPtr)->ToGoal_speed.Update()
                                ) {
                            double x = (**((*thistypeProxyPtrPtr)->ToGoal_speed.GetCachedSamples().begin())).l_vel;

                            double y = 0;

                            double a = (**((*thistypeProxyPtrPtr)->ToGoal_speed.GetCachedSamples().begin())).a_vel;

                            GetLogger().LogInfo() << "Last TOGO event is: linear vel " << x << " angular vel " << a;
                            Framept->getexistnturtle()->setVel(x, y, a);
                        }
                    });
        } else if ((handle.GetInstanceId() == LKAInstance))
        {thistypeProxyPtrPtr.get()->get()->LKA_speed.
                Subscribe(
                ara::com::EventCacheUpdatePolicy::kLastN,
                1);
            GetLogger().LogInfo() << __FUNCTION__ << __LINE__ << "  subscribe LKA Event"
                                  << handle.GetInstanceId().ToString();
        thistypeProxyPtrPtr.get()->get()->LKA_speed.SetReceiveHandler(
                []() {
                    if ((*thistypeProxyPtrPtr)->LKA_speed.

                            Update()

                            ) {
                        double x = (**((*thistypeProxyPtrPtr)->LKA_speed.GetCachedSamples().begin())).l_vel;

                        double y = 0;

                        double a = (**((*thistypeProxyPtrPtr)->LKA_speed.GetCachedSamples().begin())).a_vel;

                        GetLogger()

                                .

                                        LogInfo()

                                << "Last LKA  event is: linear vel "
                                << x << " angular vel " << a;
                        Framept->getexistnturtle()->setVel(x, y, a);


                    }
                }

        );}


    }
*/

}  // namespace someip
