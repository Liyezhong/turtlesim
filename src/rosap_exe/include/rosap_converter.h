//
// Created by root on 2021/3/23.
//

#ifndef TURTLESIM_ROSAP_CONVERTER_H
#define TURTLESIM_ROSAP_CONVERTER_H

#include "rosap_converter_swc.h"
#include "ros/ros.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/Pose.h"

class rosap_converter : public rosap_converter_swc, ros::NodeHandle {
public:
    rosap_converter();

    ~rosap_converter() override = default;

    bool run() override;
     bool stop() override;
private:
    ros::Subscriber positionlistener;

    ros::ServiceServer elementListener;

    void topicConvertFunc(const turtlesim::PoseConstPtr &rossample);

    bool SetterConvertFunc(turtlesim::TeleportAbsolute::Request &req, turtlesim::TeleportAbsolute::Response &res);
};


#endif //TURTLESIM_ROSAP_CONVERTER_H
