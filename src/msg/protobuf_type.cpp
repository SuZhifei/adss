// NOLINT: This file starts with a BOM since it contain non-ASCII characters

#include "basic/declare/DataChannelDeclare.hpp"
#include "basic/declare/TypeSupport.hpp"
#include "basic/declare/Context.hpp"
#include "basic/declare/Qos.hpp"
#include "basic/declare/LoanedPtr.hpp"
#include "basic/declare/PublisherBase.hpp"
#include "basic/declare/SubscriberBase.hpp"
#include "protobuf/fault_detect.pb.h"
#include "msg/protobuf_type.h"
#include "protobuf/fault_detect.pb.h"
#include "utils/Def.h"

template <typename _Ty>
static inline _Ty *to_current(const std::shared_ptr<void> &s)
{
    return reinterpret_cast<_Ty *>(s.get());
}
namespace yutong::adss::msg
{
    using MsgType = IBUS::FaultDetectMsg;

    FaultDetectMsg::FaultDetectMsg()
        : d(std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>()))
    {
    }
    FaultDetectMsg::FaultDetectMsg(data_ptr_mgr &&d) : d(d) {}

    FaultDetectMsg::data_ptr_mgr &FaultDetectMsg::RefPrivateData() { return d; }

    uint32_t FaultDetectMsg::get_moudle_id() const
    {
        auto thiz = to_current<MsgType>(d);
        return thiz->moudle_id();
    }

    FaultDetectMsg::Type& FaultDetectMsg::set_moudle_id(const uint32_t& value)
    {
        auto thiz = to_current<MsgType>(d);
        thiz->set_moudle_id(value);
        return *this;
    }

    uint32_t FaultDetectMsg::get_fault_level() const
    {
        auto thiz = to_current<IBUS::FaultDetectInfo>(d);
        return thiz->fault_level();
    }

    FaultDetectMsg::Type& FaultDetectMsg::set_fault_level(const uint32_t& value)
    {
        auto thiz = to_current<IBUS::FaultDetectInfo>(d);
        thiz->set_fault_level(value);
        return *this;
    }

}

namespace yutong{
namespace adss{
namespace detail{

    using yutong::adss::msg::MsgType;

    class ProtoSubscription : public SubscriberBase
    {
    public:
        using type = MsgType;
        std::shared_ptr<type> sub;
    };

    class ProtoPublisher : public PublisherBase
    {
    public:
        using type = MsgType;
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

        //此处把protobuf数据转换成string
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
        //此处把protobuf数据转换成string
        //pub->pub->publish(*to_current<RosType>(data->RefPrivateData()));

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
