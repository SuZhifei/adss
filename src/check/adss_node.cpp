#pragma once

#include "check/adss_node.hpp"
#include "check/adss_msg.hpp"

namespace yutong {
namespace adss {

AdssNode::AdssNode()
{
    Init();
}

AdssNode::~AdssNode()
{
}

void AdssNode::SubLocationCallback(const yutong::adss::LoanedPtr<IBUS::LocationService> &msg)
{
    AdssMsg::GetInstance().AddLocalization(*msg);
}

void AdssNode::SubVehInfoCallback(const yutong::adss::LoanedPtr<IBUS::VehicleInfo> &msg)
{
    AdssMsg::GetInstance().AddVehInfo(*msg);
}

void AdssNode::SubVehCmdCallback(const yutong::adss::LoanedPtr<IBUS::VehicleCmd> &msg)
{
    AdssMsg::GetInstance().SetVehCmd(*msg);
}

void AdssNode::SubFaultDetectCallback(const yutong::adss::LoanedPtr<IBUS::FaultDetectMsg> &msg)
{
    AdssMsg::GetInstance().AddFaultDetect(*msg);
}

void AdssNode::PubFaultProc(const IBUS::FaultProcMsg &fault_proc)
{

}

bool AdssNode::Init()
{
    ParticipantUnion parUnion("adss_node");
    auto participant = parUnion.EnlistmentParticipant("test");

    //创建订阅者：
    participant->CreateSubscriber<IBUS::LocationService>("test", 10, std::bind(&AdssNode::SubLocationCallback, this, std::placeholders::_1));
    participant->CreateSubscriber<IBUS::VehicleInfo>("test", 10, std::bind(&AdssNode::SubVehInfoCallback, this, std::placeholders::_1));
    participant->CreateSubscriber<IBUS::VehicleCmd>("test", 10, std::bind(&AdssNode::SubVehCmdCallback, this, std::placeholders::_1));
    participant->CreateSubscriber<IBUS::FaultDetectMsg>("test", 10, std::bind(&AdssNode::SubFaultDetectCallback, this, std::placeholders::_1));

    //创建发布者：
    pubFaultProc_ = participant->CreatePublisher<IBUS::FaultProcMsg>("demo", 10);
    pubFaultReport_ = participant->CreatePublisher<IBUS::FaultReportMsg>("demo", 10);
    
    parUnion.Run();
    return true;
}

}}