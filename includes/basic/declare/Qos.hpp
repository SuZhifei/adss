#pragma once

#include <memory>
#include "utils/Def.h"

namespace yutong{
namespace adss{

class YT_API Qos
{
public:
    Qos(int s) : size(s) {}

public:
    int size;
};

}}