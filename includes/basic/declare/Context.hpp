#pragma once

#include <memory>
#include "utils/Def.h"

namespace yutong{
namespace adss{

class YT_API Context
{
public:
    using RmwContext = std::shared_ptr<void>;
    RmwContext ctx;
};

}}
