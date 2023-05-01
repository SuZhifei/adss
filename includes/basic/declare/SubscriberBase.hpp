#include "DataChannelBase.hpp"

namespace yutong{
namespace adss{

class YT_API SubscriberBase : virtual public DataChannelBase
{
public:
    virtual ~SubscriberBase() = default;

};

using SubscriberBasePtr = std::shared_ptr<SubscriberBase>;

}}