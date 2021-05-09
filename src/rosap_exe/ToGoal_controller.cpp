//
// Created by root on 2021/3/23.
//

#include "include/ToGoal_controller.h"
#include "ara/core/string_view.h"
#include "include/application.h"
#include <chrono>
#include <thread>
using vac::container::operator ""_sv;
ara::core::InstanceSpecifier speedport{"rosap_exe/cswc/PPort_speed_control"_sv};

ToGoal_controller::ToGoal_controller(std::shared_ptr<rosap_converter> iraptr) : raptr{iraptr},
                                                                                LKASkeleton(speedport),
                                                                                ToGologger(
                                                                                        ara::log::CreateLogger(
                                                                                                "ToGo",
                                                                                                "ToGoSwc")) {
    ToGologger.LogInfo() << __FUNCTION__ << "construct ToGo SWC";
}

bool ToGoal_controller::run() {

    this->ToGologger.LogInfo() << __FUNCTION__ << "ToGoal start";
    this->LKASkeleton.OfferService();
    threads.emplace_back([this]() {
        apns::speedtype ToGOspeed;
        while (!(aaptr->exit_requested_)) {
            double error = 0.5;

            const auto &position = this->raptr->positiondata.load();
            const auto &dest = this->raptr->locationdata.load();
            const auto &x_pose = dest.x;
            const auto &y_pose = dest.y;
            const auto &x_actual = position.x;
            const auto &y_actual = position.y;
/*Todo*/auto theta_actual = position.theta;
            double x_distance = x_pose - x_actual;
            double y_distance = y_pose - y_actual;
            double theta_distance = atan2((y_distance), (x_distance)) - theta_actual;
            double linear_error = sqrt(pow(x_distance, 2.0) + pow(y_distance, 2.0));

            if (linear_error >= error) {
                //msg1.linear.x = ((-x_actual + x_pose)/std::abs((x_actual - x_pose)) )* 0.5;
                //msg1.linear.y = ((-y_actual + y_pose)/std::abs((y_actual - y_pose)) )* 0.5;

                ToGOspeed.l_vel = linear_error * 0.15;
                ToGOspeed.a_vel = theta_distance * 0.6;
                this->ToGologger.LogInfo() << __FUNCTION__ << "send ToGoalEvent l_vel=" << ToGOspeed.l_vel << "a_vel="
                                           << ToGOspeed.a_vel;
                this->LKASkeleton.ToGoal_speed.Send(ToGOspeed);
//                msg1.linear.x = Vx;
//                msg1.angular.z = w;

                this->ToGologger.LogInfo() << __FUNCTION__<<"vehicle position x="<<x_actual<<" y= "<<y_actual;
                this->ToGologger.LogInfo() << __FUNCTION__<<"dest position x="<<x_pose<<" y= "<<y_pose;
                this->ToGologger.LogInfo() << __FUNCTION__<<"lerror="<<linear_error;
                this->ToGologger.LogInfo() << __FUNCTION__<<"Aerror="<<theta_distance;

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

            }

        std::this_thread::sleep_for(std::chrono::milliseconds (20));
        };
        return false;
    });
    return 0;
}


