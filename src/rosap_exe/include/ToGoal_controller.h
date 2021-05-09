//
// Created by root on 2021/3/23.
//

#ifndef TURTLESIM_LKA_CONTROLLER_H
#define TURTLESIM_LKA_CONTROLLER_H

#include "rosap_converter.h"
#include "apns/impl_type_speedtype.h"
#include "apns/speed_control.h"
#include "apns/speed_control_skeleton.h"
class Application;
class ToGoal_controller {
public:
    ToGoal_controller(std::shared_ptr<rosap_converter> iraptr
    /*,std::shared_ptr<Application> appptr*/
    );

    ~ToGoal_controller() = default;

    bool run();

    bool stop();
    std::shared_ptr<Application> aaptr;

private:
    std::shared_ptr<rosap_converter> raptr;
    apns::skeleton::speed_controlSkeleton LKASkeleton;
    ara::log::Logger& ToGologger;
    std::vector<std::thread>   threads;
};


#endif //TURTLESIM_LKA_CONTROLLER_H
