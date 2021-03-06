#include "common.hpp"
#include "core.hpp"
#include "order/OrderHandler.hpp"

int main() {
    std::vector<std::thread> threads;

    // KILL SWITCHES FOR THREADS
    std::atomic<bool> enable_order_handler(false);

    //TODO: INITIAL THREAD CREATION

    // What we will do is basically stop the whole order handler thread if we want to stop it
    // And when we want to restart it we have a place where we can send a request to which will
    // Launch the thread and add it to threads vector again.


    //threads.emplace_back(OrderHandler, std::ref(enable_order_handler));

    // While this might try to join an ended thread that should not be a problem since joining
    // a thread that finished its execution is basically a no-op. Still a good idea to remove
    // threads from the vector when they end their execution but a low priority one
    for (auto &&thread : threads)
    {
        thread.join();
    }

    return 0;
}