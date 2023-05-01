#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

class YT_API VehicleAuxiliaryMsg : virtual public MsgBase
{
public:
    using Type = VehicleAuxiliaryMsg;
    VehicleAuxiliaryMsg();
    VehicleAuxiliaryMsg(const data_ptr_mgr&& d);
    ~VehicleAuxiliaryMsg() = default;

public:

};
}}}
