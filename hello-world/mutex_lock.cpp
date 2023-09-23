#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>

int counter = 0;
// Remove everything regarding to this
// To allow race conditions
std::mutex mtx;

void add_counter_by_5(std::string counterId)
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 5 + 1));
        mtx.lock();
        counter++;
        std::cout << "[" << counterId << "]"
                  << "Added 1. Current Total: " << counter << std::endl;
        mtx.unlock();
    }
}

int main()
{
    std::thread t1(add_counter_by_5, "HADAR");
    std::thread t2(add_counter_by_5, "BUTT");

    t1.join();
    t2.join();
    return 0;
}