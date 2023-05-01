#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

class YT_API FaultProcMsg : virtual public MsgBase
{
public:
    using Type = FaultProcMsg;
    FaultProcMsg();
    FaultProcMsg(const data_ptr_mgr&& d);
    ~FaultProcMsg() = default;

public:
    bool get_has_fault() const;
    Type& set_has_fault(const bool& value);
};
}}}