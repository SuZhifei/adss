#include "DataChannelBase.hpp"

namespace yutong{
namespace adss{

class YT_API PublisherBase : virtual public DataChannelBase
{
public:
    virtual ~PublisherBase() = default;

};

using PublisherBasePtr = std::shared_ptr<PublisherBase>;

}}