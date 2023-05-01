#include "msg/FaultDetectMsg.h"
#include "protobuf/fault_detect.pb.h"

namespace yutong::adss::msg
{
    using MsgType = IBUS::FaultDetectMsg;

    FaultDetectMsg::FaultDetectMsg()
    {
        data_= std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    FaultDetectMsg::FaultDetectMsg(const data_ptr_mgr &&d) 
    {
        data_ = d;
    }

    uint32_t FaultDetectMsg::get_moudle_id() const
    {
        auto thiz = to_current<MsgType>(data_);
        return thiz->moudle_id();
    }

    FaultDetectMsg::Type& FaultDetectMsg::set_moudle_id(const uint32_t& value)
    {
        auto thiz = to_current<MsgType>(data_);
        thiz->set_moudle_id(value);
        return *this;
    }

    uint32_t FaultDetectMsg::get_fault_level() const
    {
        auto thiz = to_current<MsgType>(data_);
        return thiz->add_detect_info()->fault_level();
    }

    FaultDetectMsg::Type& FaultDetectMsg::set_fault_level(const uint32_t& value)
    {
        auto thiz = to_current<MsgType>(data_);
        thiz->add_detect_info()->set_fault_level(value);
        return *this;
    }

}