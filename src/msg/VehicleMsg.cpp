#include "msg/VehicleMsg.h"
#include "protobuf/vehicle_cmd.pb.h"
#include "protobuf/vehicle_info.pb.h"

namespace yutong::adss::msg
{
    struct VehicleMsg_ {
        IBUS::VehicleCmd    msgCmd_;
        IBUS::VehicleInfo   msgInfo_;
    };

    using MsgType = VehicleMsg_;

    VehicleMsg::VehicleMsg()
    {
        data_= std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    VehicleMsg::VehicleMsg(const data_ptr_mgr &&d) 
    {
        data_ = d;
    }

}