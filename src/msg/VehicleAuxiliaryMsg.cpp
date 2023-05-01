#include "msg/VehicleAuxiliaryMsg.h"
#include "protobuf/vehicle_auxiliary_info.pb.h"
#include "protobuf/vehicle_auxiliary_cmd.pb.h"

namespace yutong::adss::msg
{
    struct VehicleAuxiliaryMsg_ {
        IBUS::VehicleAuxiliaryCmd   msgCmd_;
        IBUS::VehicleAuxiliaryInfo  msgInfo_;
    };

    using MsgType = VehicleAuxiliaryMsg_;

    VehicleAuxiliaryMsg::VehicleAuxiliaryMsg()
    {
        data_= std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    VehicleAuxiliaryMsg::VehicleAuxiliaryMsg(const data_ptr_mgr &&d) 
    {
        data_ = d;
    }

}