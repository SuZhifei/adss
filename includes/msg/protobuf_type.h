// NOLINT: This file starts with a BOM since it contain non-ASCII characters
#include "utils/Def.h"
#include <string>
#include <array>
#include <string_view>
#include <limits>
#include <memory>
#include <vector>
#include <cstdint>

//定义结构体

namespace yutong{
namespace adss{
namespace msg{

typedef struct FaultDetectMsg_t {
    uint8_t u8Modulestatus;
    uint8_t positionstatus;
};

class YT_API FaultDetectMsg
{
public:
    using Type = FaultDetectMsg;
    using data_ptr_mgr = std::shared_ptr<void>;
    FaultDetectMsg();
    ~FaultDetectMsg() = default;

    FaultDetectMsg(data_ptr_mgr&& d);
    data_ptr_mgr& RefPrivateData();

public:
    uint32_t get_moudle_id() const;
    Type& set_moudle_id(const uint32_t& value);

    uint32_t get_fault_level() const;
    Type& set_fault_level(const uint32_t& value);

private:
    data_ptr_mgr d;
};
}}}
