#pragma once

#include <functional>
#include "utils/Def.h"

namespace yutong{
namespace adss{

class SubscriberBase;
class PublisherBase;
template<typename _Ty>
class LoanedPtr;
class Qos;
class Context;
using ContextHolder = std::shared_ptr<Context>;
using Builder = std::shared_ptr<void>;

namespace detail{

template<typename DataT>
YT_API std::shared_ptr<SubscriberBase> CreateSubscriber(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    std::function<void(const LoanedPtr<DataT> &)> &&callback,
    const std::string &ns = ""){};

template<typename DataT>
YT_API std::shared_ptr<PublisherBase> CreatePublisher(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    const std::string &ns = ""){};

}
}}