#include "check/adss_msg.hpp"

using namespace std;

namespace yutong::adss{
    
AdssMsg::AdssMsg() {}

AdssMsg::~AdssMsg(){}

std::list<LocationInterfaceMsg> AdssMsg::GetLocalization()
{
    std::lock_guard<std::mutex> lock(locaMtx_);
    return localizationList_;
}

void AdssMsg::AddLocalization(const IBUS::LocationService &loca)
{
    std::lock_guard<std::mutex> lock(locaMtx_);
    if (5 < localizationList_.size())
    {
        localizationList_.pop_front();
    }
    LocationInterfaceMsg loca_;
    //将local的值赋值给local_
    //loca_.xxx = loca.xxx
    localizationList_.push_back(loca_);
}

std::list<VehicleMsg> AdssMsg::GetVehInfo()
{
    std::lock_guard<std::mutex> lock(vehInfoMtx_);
    return vehInfoList_;
}

void AdssMsg::AddVehInfo(const IBUS::VehicleInfo &veh_info)
{
    std::lock_guard<std::mutex> lock(vehInfoMtx_);
    if (9 < vehInfoList_.size())
    {
        vehInfoList_.pop_front();
    }
    VehicleMsg vMsg_;
    vehInfoList_.push_back(vMsg_);
}

VehicleMsg AdssMsg::GetVehCmd()
{
    std::lock_guard<std::mutex> lock(vehCmdMtx_);
    return vehCmd_;
}

void AdssMsg::SetVehCmd(const IBUS::VehicleCmd &veh_cmd)
{
    std::lock_guard<std::mutex> lock(vehCmdMtx_);
    // if(veh_cmd.controlSrcId == common::msg::EgoVehicleCmd::SRC_ID_BIG_DECISION){
    //     vehCmd_ = veh_cmd;
    // }
}

void AdssMsg::AddFaultDetect(const IBUS::FaultDetectMsg &fault_detect)
{
    std::lock_guard<std::mutex> lock(faultDetectMtx_);
    // 超过上限就将接收到的消息丢弃
    if (faultDetectList_.size() > maxCapacity)
    {
        cout << "Fault Detect queue is overflow ! message will be discarded." << endl;
        return;
    }

    FaultDetectMsg fault_detect_;
    IBUS::FaultDetectMsg remote_msg = fault_detect;
    fault_detect_.set_moudle_id(remote_msg.moudle_id());
    fault_detect_.set_fault_level(remote_msg.add_detect_info()->fault_level());
    //补充...
    
    faultDetectList_.emplace_back(fault_detect_);
}

bool AdssMsg::GetFaultDetect(FaultDetectMsg &fault_detect)
{
    std::lock_guard<std::mutex> lock(faultDetectMtx_);
    if (0 < faultDetectList_.size())
    {
        fault_detect = *(faultDetectList_.begin());
        faultDetectList_.pop_front();
        return true;
    }
    return false;
}

FaultProcMsg AdssMsg::GetFaultProc()
{
    std::lock_guard<std::mutex> lock(faultProcMtx_);
    return faultProc_;
}

void AdssMsg::SetFaultProc(const IBUS::FaultProcMsg &fault_proc)
{
    std::lock_guard<std::mutex> lock(faultProcMtx_);
    FaultProcMsg fault_proc_;
    IBUS::FaultProcMsg remote_msg = fault_proc;
    fault_proc_.set_has_fault(remote_msg.has_fault());
    //补充...

    faultProc_ = fault_proc_;
}
}

