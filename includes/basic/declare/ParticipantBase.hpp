#pragma once

#include "DataChannelBase.hpp"

namespace yutong{
namespace adss{

class YT_API ParticipantBase : virtual public DataChannelBase
{
public:
    //using DataChannelBase::DataChannelBase;
    virtual ~ParticipantBase() = default;
};

using ParticipantBasePtr = std::shared_ptr<ParticipantBase>;

}}

