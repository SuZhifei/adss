#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

class YT_API LocationInterfaceMsg : virtual public MsgBase
{
public:
    using Type = LocationInterfaceMsg;
    LocationInterfaceMsg();
    LocationInterfaceMsg(const data_ptr_mgr&& d);
    ~LocationInterfaceMsg() = default;

public:

};
}}}
