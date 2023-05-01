// NOLINT: This file starts with a BOM since it contain non-ASCII characters
//本文件是对不同通讯协议的配置和初始化，通讯协议包括ZMQ\DDS(ROS2)等

#include "basic/declare/DataChannelDeclare.hpp"
#include "basic/declare/DataChannelBase.hpp"
#include "basic/declare/ParticipantUnionBase.hpp"
#include "basic/declare/TypeSupport.hpp"
#include "basic/declare/Context.hpp"
#include "basic/declare/Qos.hpp"
#include "basic/declare/LoanedPtr.hpp"
#include "basic/declare/PublisherBase.hpp"
#include "basic/declare/SubscriberBase.hpp"
#include <iostream>

namespace yutong{
namespace adss{

class ParticipantUnionPrivate
{
public:
    std::string ns;
    //std::thread thread;
    //std::mutex lock;
    std::atomic_bool running;
    void Disband()
    {
         while (running) {
             break;
         }
         //if (thread.joinable()) {
         //    thread.join();
         //}
    }
};

ParticipantUnionBase::ParticipantUnionBase(const std::string &ns)
    : d(new ParticipantUnionPrivate)
{
    //Controller::Connect();
    d->ns = ns;
}

ParticipantUnionBase::~ParticipantUnionBase() 
{ 
    d->Disband(); 
}

std::shared_ptr<Context> ParticipantUnionBase::CreateToken(const std::string &name)
{
    return nullptr;
    // auto node = std::make_shared<ContextImpl>(name);
    // using Type = typename Context::RmwContext::element_type;
    // auto holder = std::make_shared<Context>();
    // holder->ctx = std::reinterpret_pointer_cast<Type>(node);
    // d->executor.add_node(node);
    // return holder;
}

void ParticipantUnionBase::Run()
{
    return;
    // bool ex = false;
    // if (d->running.compare_exchange_strong(ex, true)) {
    //     sleep(1);
    // }
}
void ParticipantUnionBase::RunBackground()
{
    return;
    // bool ex = false;
    // if (d->running.compare_exchange_strong(ex, true)) {
    //     sleep(1);
    // }
}

void ParticipantUnionBase::Disband() 
{ 
    d->Disband(); 
}

std::string ParticipantUnionBase::Namespace() const 
{
    return d->ns; 
}

bool ParticipantUnionBase::IsRunning() const 
{ 
    IsValid() && d->running; 
}

bool ParticipantUnionBase::IsValid() const 
{ 
    return 0; 
}


}}
