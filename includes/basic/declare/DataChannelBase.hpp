#pragma once

#include "utils/Def.h"

namespace yutong{
namespace adss{

class YT_API DataChannelBase
{
public:
	virtual ~DataChannelBase() = default;

protected:
	DataChannelBase() = default;
};

using DataChannelBasePtr = std::shared_ptr<DataChannelBase>;

}}