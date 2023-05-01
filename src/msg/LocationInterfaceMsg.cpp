#include "msg/LocationInterfaceMsg.h"
#include "protobuf/LocationInterface.pb.h"

namespace yutong::adss::msg
{
    using MsgType = IBUS::LocationService;

    LocationInterfaceMsg::LocationInterfaceMsg()
    {
        data_= std::reinterpret_pointer_cast<void>(std::make_shared<MsgType>());
    }

    LocationInterfaceMsg::LocationInterfaceMsg(const data_ptr_mgr &&d) 
    {
        data_ = d;
    }

}