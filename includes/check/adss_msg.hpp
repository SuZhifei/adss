#pragma once

#include <list>
#include "utils/Def.h"
#include "protobuf/fault_proc.pb.h"
#include "protobuf/fault_report.pb.h"
#include "protobuf/fault_proc.pb.h"
#include "protobuf/LocationInterface.pb.h"
#include "protobuf/vehicle_info.pb.h"
#include "protobuf/vehicle_cmd.pb.h"
#include "protobuf/fault_detect.pb.h"
#include "msg/LocationInterfaceMsg.h"
#include "msg/VehicleMsg.h"
#include "msg/VehicleAuxiliaryMsg.h"
#include "msg/FaultDetectMsg.h"
#include "msg/FaultProcMsg.h"
#include "msg/FaultReportMsg.h"

using namespace yutong::adss::msg;

namespace yutong {
namespace adss {

class AdssMsg
{
public:
    /*
    注意这种单例写法需要C++11。
    因为是从C++11标准才开始规定 static变量是线程安全的。
    也就是说无需我们自己写加锁保护的代码，编译器能够帮我们做到。
    该代码优点是：效率高、性能好；但缺点是：编译器如果是c++11之前的版本可能导致多次构造函数的调用，所以只能在较新的编译器上使用。
    如果介意，可以改用传统的单例模式，具体参考includes/utils/Singleton.h。
    */
    static AdssMsg& GetInstance() {
        static AdssMsg inst;
        return inst;
    }
    AdssMsg(const AdssMsg&) = delete;
    AdssMsg& operator=(const AdssMsg&) = delete;
    
    /**
     * @brief 消息处理模块初始化
     * @param  msg [in]    初始化安全服务节点
     */
    void Init();
    /**
     * @brief 故障上报云端
     * @param  msg [in]    上送云端的故障信息
     */
    // void PubFaultReport(const common::msg::FaultReport &fault_report);
    /**
     * @brief 故障处理消息
     * @param  msg [in]    接收到故障处理消息
     */
    // void PubFaultProc(const common::msg::FaultProc &fault_proc);

    // RTK定位
    std::list<LocationInterfaceMsg> GetLocalization();
    /**
     * @brief 增加定位信息
     * @param  msg [in]    接收到定位消息
     */
    void AddLocalization(const IBUS::LocationService &loca);

    // 车身
    std::list<VehicleMsg> GetVehInfo();
    /**
     * @brief 增加车身反馈消息
     * @param  msg [in]    接收到车身消息
     */
    void AddVehInfo(const IBUS::VehicleInfo &veh_info);

    // 控制
    /**
     * @brief 获取控制消息
     * @param  msg [in]    null
     */
    yutong::adss::msg::VehicleMsg GetVehCmd();
        /**
     * @brief 设置控制消息
     * @param  msg [in]    控制消息
     */
    void SetVehCmd(const IBUS::VehicleCmd &veh_cmd);

    // 故障诊断
    /**
     * @brief 接收故障采集消息
     * @param  msg [in]    接收到故障采集消息
     */
    void AddFaultDetect(const IBUS::FaultDetectMsg &fault_detect);
        /**
     * @brief 获取故障采集消息
     * @param  msg [in]    获取故障采集消息
     */
    bool GetFaultDetect(FaultDetectMsg &fault_detect);

    // 故障处理
    FaultProcMsg GetFaultProc();
        /**
     * @brief 设置故障处理消息
     * @param  msg [in]    故障处理消息
     */
    void SetFaultProc(const IBUS::FaultProcMsg &fault_proc);

private:
    AdssMsg();
    virtual ~AdssMsg();

    VehicleMsg                      vehCmd_;// 运动控制信息
    FaultProcMsg                    faultProc_;
    std::list<VehicleMsg>           vehInfoList_;// 车身信息
    std::list<FaultDetectMsg>       faultDetectList_;
    std::list<LocationInterfaceMsg> localizationList_;// RTK定位信息

    std::mutex  locaMtx_;
    std::mutex  vehCmdMtx_;
    std::mutex  vehInfoMtx_;
    std::mutex  faultDetectMtx_;
    std::mutex  faultProcMtx_;

    const size_t    maxCapacity{1000};// 故障诊断信息最大缓存数量

};


}}