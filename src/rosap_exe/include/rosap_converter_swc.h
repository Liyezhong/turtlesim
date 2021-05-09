//
// Created by root on 2021/3/22.
//

#ifndef TURTLESIM_ROSAP_CONVERTER_SWC_H
#define TURTLESIM_ROSAP_CONVERTER_SWC_H
#include <atomic>
#include <chrono>
#include <memory>
#include <string>
#include <thread>


#include "apns/external_elements.h"
#include "apns/external_elements_proxy.h"
#include "apns/driving_information.h"
#include "apns/impl_type_locationtype.h"
#include "apns/driving_information_types.h"
#include "apns/impl_type_speedtype.h"
#include "apns/driving_information_skeleton.h"
#include "ros/ros.h"
#include "ara/log/logging.h"
class rosap_converter_swc {
public:


    rosap_converter_swc();
    virtual ~rosap_converter_swc()= default;
    virtual  bool run() = 0;
    virtual  bool stop() = 0;
    std::atomic<apns::locationtype> locationdata;

    std::atomic<apns::locationtype> positiondata;


    std::atomic<apns::lanetype> lanedata;
    std::atomic<bool> elementservicefound;

protected:
       std::shared_ptr<apns::proxy::external_elementsProxy>  eleProxyPtr;
      apns::skeleton::driving_informationSkeleton DISkeleton;
      ara::log::Logger& converterLogger;
      std::atomic<bool> ProxyConstructOK;





    std::shared_ptr<ara::com::FindServiceHandle> find_service_handleptr;
};


#endif //TURTLESIM_ROSAP_CONVERTER_SWC_H
