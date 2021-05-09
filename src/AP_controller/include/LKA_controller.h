//
// Created by root on 2021/3/23.
//

#ifndef TURTLESIM_LKA_CONTROLLER_H
#define TURTLESIM_LKA_CONTROLLER_H

//#include "rosap_converter.h"
#include "apns/impl_type_speedtype.h"
#include "apns/speed_control.h"
#include "apns/speed_control_skeleton.h"
#include "apns/driving_information.h"
#include "apns/driving_information_proxy.h"


class Application;
class LKA_controller {
public:
    LKA_controller(
    std::shared_ptr<Application> appptr
    );

    ~LKA_controller() = default;

    bool run();

    bool stop();
    std::shared_ptr<Application> aaptr;

private:
//    std::shared_ptr<rosap_converter> raptr;
    apns::skeleton::speed_controlSkeleton LKASkeleton;
    std::shared_ptr<apns::proxy::driving_informationProxy> PositionProxyPtr=0;
    std::shared_ptr<apns::proxy::driving_informationProxy> ToGoalSpeedProxyPtr=0;
    std::shared_ptr<ara::com::FindServiceHandle>  FindingPtr=0;
    apns::locationtype vehicle_position;
    apns::speedtype vehicle_speed;
    std::atomic<bool> PositionInfofound;
    std::atomic<bool> SpeedInfofound;
    ara::log::Logger& LKAlogger;
    std::vector<std::thread>   threads;
};


#endif //TURTLESIM_LKA_CONTROLLER_H
