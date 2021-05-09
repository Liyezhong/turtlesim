//
// Created by root on 2021/3/22.
//

#include "include/rosap_converter_swc.h"
#include "ara/core/instance_specifier.h"
#include "vac/container/string_literals.h"

using vac::container::literals::operator ""_sv;
static ara::core::InstanceSpecifier DIsekeSpec{"rosap_exe/cswc/PPort_drivinginfomation"_sv};

rosap_converter_swc::rosap_converter_swc() :
        DISkeleton{DIsekeSpec
        }, converterLogger{ara::log::CreateLogger("racv", "rosap_converter SWC")} {
    converterLogger.LogInfo() << __FUNCTION__ << "construct SWC,offering position service";
    DISkeleton.OfferService();
    converterLogger.LogInfo() << __FUNCTION__ << "construct SWC,finding service";
    ara::core::InstanceSpecifier ExtmSpec{"rosap_exe/cswc/RPort_external_elements"_sv};
    find_service_handleptr = std::make_shared<ara::com::FindServiceHandle>(
            apns::proxy::external_elementsProxy::StartFindService(
                    [this](ara::com::ServiceHandleContainer<apns::proxy::external_elementsProxy::HandleType> extmServices) {
                        if (extmServices.size() == 0) {
                            converterLogger.LogInfo() << __FUNCTION__ << "no external_element service found";
                            elementservicefound=0;
                        } else if (extmServices.size() == 1) {
                            this->eleProxyPtr = std::make_shared<apns::proxy::external_elementsProxy>(
                                    extmServices.front());
                            converterLogger.LogInfo() << __FUNCTION__
                                                      << "one external_element service found,proxy Constructed";
                            elementservicefound=1;

                        } else{
                            converterLogger.LogInfo() << __FUNCTION__
                                                      << "multiple external_element service found,proxy Constructed";
                            elementservicefound=1;
                        }
                    }, ExtmSpec));
    positiondata.store({11.1,11.1,0});
    locationdata.store({11.1,11.1,0});
    converterLogger.LogInfo()<<__FUNCTION__<<__LINE__<<"vehicle pos("<<positiondata.load().x<<","<<positiondata.load().y<<","<<positiondata.load().theta<<") ,dest ("<<
    locationdata.load().x<<","<<locationdata.load().y<<")";
}
