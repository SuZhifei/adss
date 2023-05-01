#include "msg/FaultProcMsg.h"
#include "protobuf/fault_proc.pb.h"

namespace yutong::adss::msg
{
    using MsgType = IBUS::FaultProcMsg;

    FaultProcMsg::FaultProcMsg()
    {
        data_ = std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    FaultProcMsg::FaultProcMsg(const data_ptr_mgr&& d) 
    {
        data_ = d;
    }

    bool FaultProcMsg::get_has_fault() const
    {
        auto thiz = to_current<MsgType>(data_);
        return thiz->has_fault();
    }

    FaultProcMsg::Type& FaultProcMsg::set_has_fault(const bool& value)
    {
        auto thiz = to_current<MsgType>(data_);
        thiz->set_has_fault(value);
        return *this;
    }
}
