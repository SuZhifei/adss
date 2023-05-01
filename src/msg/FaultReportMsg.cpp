#include "msg/FaultReportMsg.h"
#include "protobuf/fault_report.pb.h"

namespace yutong::adss::msg
{
    using MsgType = IBUS::FaultReportMsg;

    FaultReportMsg::FaultReportMsg()
    {
        data_= std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    FaultReportMsg::FaultReportMsg(const data_ptr_mgr &&d) 
    {
        data_ = d;
    }

    bool FaultReportMsg::get_has_fault() const
    {
        auto thiz = to_current<MsgType>(data_);
        return thiz->has_fault();
    }

    FaultReportMsg::Type& FaultReportMsg::set_has_fault(const bool& value)
    {
        auto thiz = to_current<MsgType>(data_);
        thiz->set_has_fault(value);
        return *this;
    }

    uint32_t FaultReportMsg::get_fault_level() const
    {
        auto thiz = to_current<MsgType>(data_);
        return thiz->add_fault_list()->fault_level();
    }

    FaultReportMsg::Type& FaultReportMsg::set_fault_level(const uint32_t& value)
    {
        auto thiz = to_current<MsgType>(data_);
        thiz->add_fault_list()->set_fault_level(value);
        return *this;
    }

}