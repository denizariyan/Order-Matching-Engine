#include "../common.hpp"
#include "order_handler.hpp"

void order_handler(std::atomic<bool>& enabled)
{
    while (enabled)
    {    
        std::cout << "RUNNING INTO 99s" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}