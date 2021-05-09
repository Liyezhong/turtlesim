//
// Created by root on 2021/3/23.
//

#include "include/LKA_controller.h"
#include "ara/core/string_view.h"
#include "include/application.h"
#include <chrono>
#include <thread>

using vac::container::operator ""_sv;
ara::core::InstanceSpecifier LKAspeedpport{"AP_controller/controller/speed_control"_sv};
ara::core::InstanceSpecifier ToGoalspeedrport{"AP_controller/controller/driving_information"_sv};
ara::core::InstanceSpecifier Positionrport{"AP_controller/controller/driving_information"_sv};
ara::com::InstanceIdentifier PositionInstance{"Ipc:1"_sv};
ara::com::InstanceIdentifier ToGoalspeedInstance{"SomeIp:3"_sv};

LKA_controller::LKA_controller(std::shared_ptr<Application> appptr) : aaptr(appptr),
                                                                      LKASkeleton(LKAspeedpport),
                                                                      PositionInfofound(0), SpeedInfofound(0),
                                                                      LKAlogger(
                                                                              ara::log::CreateLogger(
                                                                                      "LKAC",
                                                                                      "LKASwc")) {
    LKAlogger.LogInfo() << __FUNCTION__ << "construct LKAC SWC";

    FindingPtr = std::make_shared<ara::com::FindServiceHandle>(apns::proxy::driving_informationProxy::StartFindService(
            [this](ara::com::ServiceHandleContainer<apns::proxy::driving_informationProxy::HandleType> foundservices) {
                LKAlogger.LogInfo() << __FUNCTION__ << "  start find drivingservice ";

                if (foundservices.size() == 0) {
                    LKAlogger.LogWarn() << "no DrivingInfoService found";
                    PositionInfofound.store(0);
                    SpeedInfofound.store(0);
                } else if (foundservices.size() == 1) {
                    LKAlogger.LogWarn() << __FUNCTION__ << __LINE__ << " only one DrivingInfoService found";

                    if (foundservices.front().GetInstanceId() == ToGoalspeedInstance) {
                        LKAlogger.LogWarn() << __FUNCTION__ << __LINE__ << "only one ToGoalspeedInstanceService found"
                                            << foundservices.front().GetInstanceId().ToString();

                        ToGoalSpeedProxyPtr = std::make_shared<apns::proxy::driving_informationProxy>(
                                foundservices.front());
                        SpeedInfofound = 1;
                        ToGoalSpeedProxyPtr.get()->vehicle_speed.Subscribe(
                                ara::com::EventCacheUpdatePolicy::kLastN, 1);
                        LKAlogger.LogWarn() << "speed vehicle event state"
                                            << static_cast<int>(ToGoalSpeedProxyPtr->vehicle_position.GetSubscriptionState())
                                            << "kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";
                        int x = static_cast<int>(ToGoalSpeedProxyPtr->vehicle_position.GetSubscriptionState());
                        x = x;
                    } else {
                        LKAlogger.LogWarn() << __FUNCTION__ << __LINE__ << "only one PositionService found"
                                            << foundservices.front().GetInstanceId().ToString();

                        PositionProxyPtr = std::make_shared<apns::proxy::driving_informationProxy>(
                                foundservices.front());
                        PositionInfofound = 1;
                        PositionProxyPtr.get()->vehicle_position.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN, 1);
                        LKAlogger.LogWarn() << "positon vehicle event state"
                                            << static_cast<int>(PositionProxyPtr->vehicle_position.GetSubscriptionState())
                                            << "kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";

                    }

                } else if (foundservices.size() == 2) {
                    LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << "both PositionService found";

                    for (auto handl:foundservices) {
                        if (handl.GetInstanceId() == ToGoalspeedInstance) {
                            LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << " construct ToGoalSpeedProxyPtr";
                            ToGoalSpeedProxyPtr = std::make_shared<apns::proxy::driving_informationProxy>(handl);
                            SpeedInfofound = 1;
                            ToGoalSpeedProxyPtr.get()->vehicle_speed.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                                                                               1);
                            LKAlogger.LogWarn() << "speed vehicle event state"
                                                << static_cast<int>(ToGoalSpeedProxyPtr->vehicle_position.GetSubscriptionState())
                                                << "kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";

                        } else {
                            LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << " construct PositionProxyPtr";
                            PositionProxyPtr = std::make_shared<apns::proxy::driving_informationProxy>(handl);
                            PositionInfofound = 1;
                            PositionProxyPtr.get()->vehicle_position.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                                                                               1);
                            LKAlogger.LogWarn() << "positon vehicle event state"
                                                << static_cast<int>(PositionProxyPtr->vehicle_position.GetSubscriptionState())
                                                << "kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";


                        }
                    }
                } else {
                    LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << " more than one DrivingInfoService found ";

                };

                /*     if (SpeedInfofound) {
                         ToGoalSpeedProxyPtr->vehicle_speed.SetReceiveHandler(
                                 [this]() {
                                     if (ToGoalSpeedProxyPtr->vehicle_speed.Update()) {
                                         LKAlogger.LogInfo() << "l "
                                                             << ToGoalSpeedProxyPtr->vehicle_speed.GetCachedSamples().front()->l_vel;
                                     }
                                 }
                         );
                     }
                     if (PositionInfofound) {
                         PositionProxyPtr->vehicle_position.SetReceiveHandler([this]() {
                                                                                  if (PositionProxyPtr->vehicle_position.Update()) {
                                                                                      LKAlogger.LogInfo() << "x "
                                                                                                          << PositionProxyPtr->vehicle_position.GetCachedSamples().front()->x;
                                                                                  }
                                                                              }
                         );
                     }*/

            }, Positionrport));

}

bool LKA_controller::run() {

    this->LKAlogger.LogInfo() << __FUNCTION__ << "LKA start";
    this->LKASkeleton.OfferService();

    while (!(aaptr->exit_requested_)) {
/*
        double error = 0.5;
*/
//        if (SpeedInfofound == 1 && PositionInfofound == 1 && PositionProxyPtr.get() && ToGoalSpeedProxyPtr.get()) {
//            LKAlogger.LogWarn() << "speed vehicle event state "
//                                << static_cast<int>(ToGoalSpeedProxyPtr->vehicle_position.GetSubscriptionState())
//                                << " kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";
//            LKAlogger.LogWarn() << "positon vehicle event state "
//                                << static_cast<int>(PositionProxyPtr->vehicle_position.GetSubscriptionState())
//                                << " kSubscribed = 0U, kNotSubscribed = 1U, kSubscriptionPending = 2U";
//        }

        if ( PositionProxyPtr.get() && ToGoalSpeedProxyPtr.get()
            /*PositionProxyPtr->vehicle_position.GetSubscriptionState() != ara::com::SubscriptionState::kNotSubscribed &&
            ToGoalSpeedProxyPtr->vehicle_position.GetSubscriptionState() !=
            ara::com::SubscriptionState::kNotSubscribed*/) {
            if (this->PositionProxyPtr->vehicle_position.Update())
                this->vehicle_position = *(this->PositionProxyPtr->vehicle_position.GetCachedSamples().front());
            if (this->ToGoalSpeedProxyPtr->vehicle_speed.Update())
                vehicle_speed = *(this->ToGoalSpeedProxyPtr->vehicle_speed.GetCachedSamples().front());
            /*const auto &x_pose = dest.x;
            const auto &y_pose = dest.y;

            const auto &x_actual = vehicle_position.x;
            const auto &y_actual = vehicle_position.y;
    *//*auto theta_actual = vehicle_position.theta;
            double x_distance = x_pose - x_actual;
            double y_distance = y_pose - y_actual;
            double theta_distance = atan2((y_distance), (x_distance)) - theta_actual;
            double linear_error = sqrt(pow(x_distance, 2.0) + pow(y_distance, 2.0));*/
            this->LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << "  position  x= " << vehicle_position.x << "  y= "
                                      << vehicle_position.y<<" 0= "<<vehicle_position.theta;
            if (vehicle_position.x <= 16.1 && vehicle_position.x >= 6.1 && vehicle_position.y >= 10.1 && vehicle_position.y <= 12.1) {
//            apns::speedtype LKAspeed;
                double vy = std::sin(vehicle_position.theta) * vehicle_speed.l_vel;
                double bounddist = (vehicle_position.y - 10.1) * (12.1 - vehicle_position.y);
                vy = vy * bounddist;
                double av = std::asin(vy / vehicle_speed.l_vel) - vehicle_position.theta;
                LKASkeleton.ToGoal_speed.Send({vehicle_speed.l_vel, av});
                this->LKAlogger.LogWarn() << __FUNCTION__ << __LINE__ << "  send LKASignal  l " << vehicle_speed.l_vel << "  a "
                                          << av;
            } else {
                LKASkeleton.ToGoal_speed.Send({vehicle_speed.l_vel, vehicle_speed.a_vel});

                this->LKAlogger.LogInfo() << __FUNCTION__ << __LINE__ << "send no LKASignal";

            }
            /*if (linear_error >= error) {
                //msg1.linear.x = ((-x_actual + x_pose)/std::abs((x_actual - x_pose)) )* 0.5;
                //msg1.linear.y = ((-y_actual + y_pose)/std::abs((y_actual - y_pose)) )* 0.5;

                ToGOspeed.l_vel = linear_error * 0.15;
                ToGOspeed.a_vel = theta_distance * 0.6;
                this->LKAlogger.LogInfo() << __FUNCTION__ << "send ToGoalEvent l_vel=" << ToGOspeed.l_vel << "a_vel="
                                          << ToGOspeed.a_vel;
                this->LKASkeleton.ToGoal_speed.Send(ToGOspeed);
    //                msg1.linear.x = Vx;
    //                msg1.angular.z = w;

                this->LKAlogger.LogInfo() << __FUNCTION__ << "vehicle vehicle_position x=" << x_actual << " y= " << y_actual;
                this->LKAlogger.LogInfo() << __FUNCTION__ << "dest vehicle_position x=" << x_pose << " y= " << y_pose;
                this->LKAlogger.LogInfo() << __FUNCTION__ << "lerror=" << linear_error;
                this->LKAlogger.LogInfo() << __FUNCTION__ << "Aerror=" << theta_distance;

    //                ROS_INFO("error ang = %f", theta_distance);

    //                ROS_INFO("Vx = %f", msg1.linear.x);
                //ROS_INFO("Vy = %f", msg1.linear.y);
    //                ROS_INFO("x_distance = %f", x_distance);
    //                ROS_INFO("y_distance = %f", y_distance);
    //                ROS_INFO("linear_error = %f", linear_error);
                //double k = ((-x_actual + x_pose)/std::abs((x_actual - x_pose)) );
                //ROS_INFO("%f", k );

            } else {
                ToGOspeed.l_vel = 0;
                ToGOspeed.a_vel = 0;
                this->LKASkeleton.ToGoal_speed.Send(ToGOspeed);
    //                msg1.linear.x = 0.;
    //                msg1.angular.z = 0.;
    //                ROS_INFO("linear_error = %f", linear_error);
                //ROS_INFO("else is ok");

            }*/}
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }

    return 0;
}

bool LKA_controller::stop() {
    this->LKASkeleton.StopOfferService();
    apns::proxy::driving_informationProxy::StopFindService(*(FindingPtr.get()));
    ToGoalSpeedProxyPtr->vehicle_speed.Unsubscribe();
    PositionProxyPtr->vehicle_position.Unsubscribe();
    return false;
}



