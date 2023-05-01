#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

class YT_API FaultReportMsg : virtual public MsgBase
{
public:
    using Type = FaultReportMsg;
    FaultReportMsg();
    FaultReportMsg(const data_ptr_mgr&& d);
    ~FaultReportMsg() = default;

public:
    bool get_has_fault() const;
    Type& set_has_fault(const bool& value);

    uint32_t get_fault_level() const;
    Type& set_fault_level(const uint32_t& value);
};
}}}
