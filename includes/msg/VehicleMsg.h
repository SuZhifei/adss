#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

class YT_API VehicleMsg : virtual public MsgBase
{
public:
    using Type = VehicleMsg;
    VehicleMsg();
    VehicleMsg(const data_ptr_mgr&& d);
    ~VehicleMsg() = default;

public:

};
}}}
