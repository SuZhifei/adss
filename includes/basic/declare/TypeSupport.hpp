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

namespace detail{

template<typename DataT>
YT_API void PublishData(const std::shared_ptr<PublisherBase> &ctx, LoanedPtr<DataT> &&data);

template<typename DataT>
YT_API LoanedPtr<DataT> LoanData(const std::shared_ptr<PublisherBase> &ctx);

}}}
