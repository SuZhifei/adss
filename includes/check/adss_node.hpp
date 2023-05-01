#pragma once

#include "basic/api/DataChannel.hpp"
#include "protobuf/fault_proc.pb.h"
#include "protobuf/fault_report.pb.h"
#include "protobuf/fault_proc.pb.h"
#include "protobuf/LocationInterface.pb.h"
#include "protobuf/vehicle_info.pb.h"
#include "protobuf/vehicle_cmd.pb.h"
#include "protobuf/fault_detect.pb.h"

namespace yutong{
namespace adss{

class AdssNode : public DataChannelBase
{
public:
    AdssNode();

    /**
     * @brief 发布故障诊断信息
     * @param  fault_proc [in]  故障诊断信息
     */
    void PubFaultProc(const IBUS::FaultProcMsg &fault_proc);

    /**
     * @brief 发布故障上报信息
     * @param  fault_report [in]  故障上报信息
     */
    void PubFaultReport(const IBUS::FaultProcMsg &fault_report);

protected:
    virtual ~AdssNode();
    
    /**
     * @brief   订阅RTK定位消息的回调函数
     * @param   msg  接收到的RTK定位消息
     */
    void SubLocationCallback(const yutong::adss::LoanedPtr<IBUS::LocationService> &msg);

    /**
     * @brief 订阅车身底盘消息的回调函数
     * @param  msg [in]    接收到的车身底盘消息
     */
    void SubVehInfoCallback(const yutong::adss::LoanedPtr<IBUS::VehicleInfo> &msg);
    
    /**
     * @brief 订阅车辆控制信息回调函数
     * @param  msg     控制命令信息
     */
    void SubVehCmdCallback(const yutong::adss::LoanedPtr<IBUS::VehicleCmd> &msg);

    /**
     * @brief 订阅故障诊断消息的回调函数
     * @param  msg    接收到的规控消息
     */
    void SubFaultDetectCallback(const yutong::adss::LoanedPtr<IBUS::FaultDetectMsg> &msg);
private:
    bool Init();

    std::shared_ptr<Publisher<IBUS::FaultProcMsg>>      pubFaultProc_;   // 故障处理信息发布者
    std::shared_ptr<Publisher<IBUS::FaultReportMsg>>    pubFaultReport_; // 故障上报信息发布者
};
}}