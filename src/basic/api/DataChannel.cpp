#include "basic/api/DataChannel.hpp"
#include <iostream>

void __attribute__((constructor)) init_function(void)
{
    std::cout << "data channel runtime is setting up." << std::endl;
}
