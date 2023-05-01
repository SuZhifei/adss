#pragma once

#include "basic/declare/Context.hpp"
#include "basic/declare/DataChannelBase.hpp"
#include "basic/declare/DataChannelDeclare.hpp"
#include "basic/declare/ParticipantUnionBase.hpp"
#include "basic/declare/ParticipantBase.hpp"
#include "basic/declare/PublisherBase.hpp"
#include "basic/declare/SubscriberBase.hpp"
#include "basic/declare/LoanedPtr.hpp"
#include "basic/declare/TypeSupport.hpp"
#include "basic/declare/Qos.hpp"
#include <functional>
#include <memory>
#include <string>

namespace yutong{
namespace adss{

template<typename _Ty>
class Publisher : virtual public PublisherBase
{
public:
    using type = _Ty;
    using loan_type = LoanedPtr<type>;
    using bill = typename loan_type::bill_type;

public:
    Publisher(const std::shared_ptr<PublisherBase> &impl) : impl_(impl) {}
    Publisher(std::shared_ptr<PublisherBase> &&impl)
        : impl_(std::forward<decltype(impl_)>(impl))
    {
    }
    loan_type Loan() { return detail::LoanData<type>(impl_); }
    void Write(std::shared_ptr<type> &&ptr)
    {
        detail::PublishData(impl_, std::forward<decltype(ptr)>(ptr));
    }
    void Write(const type &data)
    {
        auto ptr = Loan();
        *ptr = data;
        Write(std::move(ptr));
    }

private:
    std::shared_ptr<PublisherBase> impl_;

};

template<typename _Ty>
class YT_API Subscriber : virtual public SubscriberBase
{
public:
    Subscriber(const std::shared_ptr<SubscriberBase> &impl) : impl_(impl) {}
    Subscriber(std::shared_ptr<SubscriberBase> &&impl)
        : impl_(std::forward<decltype(impl_)>(impl)){}
    using type = _Ty;

private:
    std::shared_ptr<SubscriberBase> impl_;

};

class YT_API Participant : virtual public ParticipantBase
{
public:
    Participant(const std::shared_ptr<Context> &context) 
        : m_context(context) 
    {}
    virtual ~Participant() = default;

public:
    template<typename _Ty>
    std::shared_ptr<Subscriber<_Ty>> CreateSubscriber(
        const std::string &channel, 
        const Qos &qos,
        std::function<void(const LoanedPtr<_Ty> &)> &&callback)
    {
        using DataCallBack = std::remove_reference_t<decltype(callback)>;
        auto sub = detail::CreateSubscriber<_Ty>(
            m_context, channel, qos, std::forward<DataCallBack>(callback));
        return std::make_shared<Subscriber<_Ty>>(sub);
    }
    template<typename _Ty>
    std::shared_ptr<Publisher<_Ty>> CreatePublisher(const std::string &channel,
                                                    const Qos &qos)
    {
        auto pub = detail::CreatePublisher<_Ty>(m_context, channel, qos);
        return std::make_shared<Publisher<_Ty>>(pub);
    }

private:
    std::shared_ptr<Context> m_context;
    std::weak_ptr<ParticipantUnionBase> m_union;
};

class ParticipantUnion : public ParticipantUnionBase
{
public:
    using ParticipantUnionBase::ParticipantUnionBase;
    std::shared_ptr<Participant> EnlistmentParticipant(const std::string &name)
    {
        return std::make_shared<Participant>(CreateToken(name));
    }
};

}}