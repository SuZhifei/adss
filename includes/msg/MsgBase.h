#pragma once

#include "utils/Def.h"

template <typename _Ty>
static inline _Ty *to_current(const std::shared_ptr<void> &s)
{
    return reinterpret_cast<_Ty *>(s.get());
}

namespace yutong{
namespace adss{
namespace msg{
    
class YT_API MsgBase
{
public:
    using data_ptr_mgr = std::shared_ptr<void>;
    MsgBase(){};
    MsgBase(const data_ptr_mgr&& d):data_(d) {};
    ~MsgBase() = default;
    data_ptr_mgr& RefPrivateData(){return data_;};

protected:
    data_ptr_mgr data_;
};

}}}