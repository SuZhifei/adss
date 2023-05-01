#include "catch2/catch.hpp"
#include "basic/api/DataChannel.hpp"
#include "protobuf/fault_detect.pb.h"
#include "msg/FaultDetectMsg.h"

#define PROJECT_NAME	"check"

using namespace yutong::adss;
using namespace IBUS;

TEST_CASE(PROJECT_NAME, std::string("[") + PROJECT_NAME + "]")
{
    // ParticipantUnion pU("adss_check");
    // auto p = pU.EnlistmentParticipant("test");
    // auto sub = p->CreateSubscriber<yutong::adss::msg::FaultDetectMsg_t>("test", 10, 
    // [](const auto& d) {
    //     std::cout << " sub_system:" << d->u8Modulestatus << std::endl;
    // });

    // auto pub = p->CreatePublisher<yutong::adss::msg::FaultDetectMsg_t>("demo1", 10);
    // pU.Run();
    // int i = 0;
    while (true)
    {
        //auto s = pub->Loan();
        //s->set_stamp(std::chrono::duration_cast<std::chrono::seconds>(TimeBase::now().time_since_epoch()).count());
        //s->set_frame_id(std::to_string(i++));
        //pub->Write(std::move(s));
        //usleep(1000000);
    }

}
