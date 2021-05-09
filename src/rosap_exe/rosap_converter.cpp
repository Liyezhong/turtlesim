//
// Created by root on 2021/3/23.
//

#include "include/rosap_converter.h"
# include <turtlesim/Pose.h>
#include "turtlesim/TeleportAbsolute.h"
#include "ara/core/future.h"
rosap_converter::rosap_converter()
        : rosap_converter_swc(), ros::NodeHandle() {
    this->converterLogger.LogInfo()<<"constructor subconverter";


}

bool rosap_converter::run() {
    this->converterLogger.LogInfo()<<"running converter ";

    positionlistener = this->subscribe("position", 10,&rosap_converter::topicConvertFunc,this );

    this->converterLogger.LogInfo()<<"subscribe ros position topic";


    elementListener=this->advertiseService("teleport_absolute",&rosap_converter::SetterConvertFunc, this);

    this->converterLogger.LogInfo()<<"advertise ros element teleport_absolute";

    return false;
}

void rosap_converter::topicConvertFunc(const turtlesim::PoseConstPtr &rossample) {

//        apns::locationtype getlocationfromros{rossample->x, rossample->y};
    /*Todo 3wei*/
        ROS_INFO("get ROS position message,converting to AP event");
        DISkeleton.vehicle_position.Send({rossample->x, rossample->y,rossample->theta});
        this->positiondata.store({rossample->x,rossample->y,rossample->theta});
        this->converterLogger.LogInfo()<<"get ros topic message,convert to AP event";

}

bool rosap_converter::SetterConvertFunc(turtlesim::TeleportAbsolute::Request &req,
                                        turtlesim::TeleportAbsolute::Response &res) {
res=res;
        ROS_INFO("get ROS element set request,converting to AP setter");

        this->converterLogger.LogInfo()<<"get ROS element set request"<<" store data and converting to AP setter";
        this->locationdata.store({req.x,req.y,req.theta});
    this->converterLogger.LogInfo()<<"stored data and converting to AP setter";

    if(elementservicefound){
        auto setterOK= eleProxyPtr->object.Set(locationdata.load()).then(
                [this](ara::core::Future<apns::locationtype> ares){ this->converterLogger.LogInfo()<<"get AP setter response,set to x="<<ares.get().x
                                                                                                   <<"y="<<ares.get().y;
                    return 1;
                }
        );}

    return 0;
}

bool rosap_converter::stop() {
    this->eleProxyPtr->StopFindService(*(this->find_service_handleptr.get()));
    this->eleProxyPtr->object.Unsubscribe();
    this->DISkeleton.StopOfferService();
    this->elementListener.shutdown();
    this->positionlistener.shutdown();
    return false;
}


