// NOLINT: This file starts with a BOM since it contain non-ASCII characters
//本文件是对通讯协议接口的调用，通讯协议包括ZMQ\DDS(ROS2)等,其中数据协议分别采用Protobuffer和msg

#include "basic/declare/DataChannelDeclare.hpp"
#include "basic/declare/TypeSupport.hpp"
#include "basic/declare/Context.hpp"
#include "basic/declare/Qos.hpp"
#include "basic/declare/LoanedPtr.hpp"
#include "basic/declare/PublisherBase.hpp"
#include "basic/declare/SubscriberBase.hpp"
#include "msg/FaultDetectMsg.h"
#include "utils/Def.h"

namespace yutong{
namespace adss{
namespace detail{

template <typename _Ty>
static inline _Ty *to_current(const std::shared_ptr<void> &s)
{
    return reinterpret_cast<_Ty *>(s.get());
}

class ProtoSubscription : public SubscriberBase
{
public:
    using type = yutong::adss::msg::FaultDetectMsg;
    std::shared_ptr<type> sub;
};

class ProtoPublisher : public PublisherBase
{
public:
    using type = yutong::adss::msg::FaultDetectMsg;
    std::shared_ptr<type> pub;
};

template <>
std::shared_ptr<SubscriberBase> CreateSubscriber<yutong::adss::msg::FaultDetectMsg_t>(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    std::function<void(const LoanedPtr<yutong::adss::msg::FaultDetectMsg_t> &)> &&callback,
    const std::string &ns /*= ""*/)
{
    std::vector<std::string> events;
    // events.push_back(channel);
    // Controller::RegisterEvents(events);
    // std::function<void(typename CurrentType::StringChangedArgs)> func = [cb = std::move(callback)](const soa::com::Controller::StringChangedArgs & s) {
    //     dc::icard_msgs::msg::gnssInfo_t gl;
    //     RosType t;
    //     t.ParseFromString(s.value);

    //     LoanedPtr<soa::com::Controller::StringChangedArgs> SoaFunc(std::make_unique<soa::com::Controller::StringChangedArgs>(s));
    //     cb(SoaFunc);
    // };
    // Controller::StringChangedEvent() += std::bind(func, std::placeholders::_1);

    return nullptr;
}

template <>
std::shared_ptr<SubscriberBase> CreateSubscriber<yutong::adss::msg::FaultDetectMsg>(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    std::function<void(const LoanedPtr<yutong::adss::msg::FaultDetectMsg> &)> &&callback,
    const std::string &ns /*= ""*/)
{
    std::vector<std::string> events;
    // events.push_back(channel);
    // Controller::RegisterEvents(events);
    // std::function<void(typename CurrentType::StringChangedArgs)> func = [cb = std::move(callback)](const soa::com::Controller::StringChangedArgs & s) {
    //     dc::icard_msgs::msg::gnssInfo_t gl;
    //     RosType t;
    //     t.ParseFromString(s.value);

    //     LoanedPtr<soa::com::Controller::StringChangedArgs> SoaFunc(std::make_unique<soa::com::Controller::StringChangedArgs>(s));
    //     cb(SoaFunc);
    // };
    // Controller::StringChangedEvent() += std::bind(func, std::placeholders::_1);

    return nullptr;
}

template <>
std::shared_ptr<PublisherBase> CreatePublisher<yutong::adss::msg::FaultDetectMsg_t>(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    const std::string &ns /*= ""*/)
{
    //auto node = to_current<RosPublisher>(ctx->ctx);
    auto pub = std::make_shared<ProtoPublisher>();
    //pub->pub = node->create_publisher<RosType>(channel, qos.size);
    return pub;
}
template <>
std::shared_ptr<PublisherBase> CreatePublisher<yutong::adss::msg::FaultDetectMsg>(
    const ContextHolder &ctx, const std::string &channel, const Qos &qos,
    const std::string &ns /*= ""*/)
{
    //auto node = to_current<RosPublisher>(ctx->ctx);
    auto pub = std::make_shared<ProtoPublisher>();
    //pub->pub = node->create_publisher<RosType>(channel, qos.size);
    return pub;
}

template <>
void PublishData<yutong::adss::msg::FaultDetectMsg>(
    const std::shared_ptr<PublisherBase> &ctx,
    yutong::adss::LoanedPtr<yutong::adss::msg::FaultDetectMsg> &&data)
{
    auto pub = to_current<ProtoPublisher>(ctx);

    //此处把protobuf数据转换成需要的格式
    ;
    //Controller::SetString(channel, );
    return;
}
template <>
void PublishData<yutong::adss::msg::FaultDetectMsg_t>(
    const std::shared_ptr<PublisherBase> &ctx,
    yutong::adss::LoanedPtr<yutong::adss::msg::FaultDetectMsg_t> &&data)
{
    auto pub = to_current<ProtoPublisher>(ctx);
    //此处把protobuf数据转换成需要的格式
    //pub->pub->publish(*to_current<RosType>(data->RefPrivateData()));
    
    //将数据发送出去：
    //Controller::SetString(channel, ns);
    return;
}
template <>
LoanedPtr<yutong::adss::msg::FaultDetectMsg> LoanData<yutong::adss::msg::FaultDetectMsg>(
    [[maybe_unused]] const std::shared_ptr<PublisherBase> &ctx)
{
    return LoanedPtr<yutong::adss::msg::FaultDetectMsg>(std::make_unique<yutong::adss::msg::FaultDetectMsg>());
}

}}}
