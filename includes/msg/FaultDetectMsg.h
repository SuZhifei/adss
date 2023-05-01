#pragma once

#include "msg/MsgBase.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace msg{

//test:自定义数据类型
typedef struct FaultDetectMsg_t {
    uint8_t u8Modulestatus;
    uint8_t positionstatus;
};

class YT_API FaultDetectMsg : virtual public MsgBase
{
public:
    using Type = FaultDetectMsg;
    FaultDetectMsg();
    FaultDetectMsg(const data_ptr_mgr&& d);
    ~FaultDetectMsg() = default;

public:
    uint32_t get_moudle_id() const;
    Type& set_moudle_id(const uint32_t& value);

    uint32_t get_fault_level() const;
    Type& set_fault_level(const uint32_t& value);
};
}}}
