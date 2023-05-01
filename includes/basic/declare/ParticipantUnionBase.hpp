#pragma once

#include "DataChannelBase.hpp"
#include <memory>

namespace yutong{
namespace adss{

class Context;

class ParticipantUnionPrivate;
class YT_API ParticipantUnionBase : virtual public DataChannelBase
{
public:
    ParticipantUnionBase(const std::string &ns = "");
    virtual ~ParticipantUnionBase();
    virtual void Run();
    virtual void RunBackground();
    virtual void Disband();
    std::string Namespace() const;
    virtual bool IsRunning() const;
    virtual bool IsValid() const;
protected:
    virtual std::shared_ptr<Context> CreateToken(const std::string &name);

private:
    std::shared_ptr<ParticipantUnionPrivate> d;
};

using ParticipantUnionBasePtr = std::shared_ptr<ParticipantUnionBase>;

}}