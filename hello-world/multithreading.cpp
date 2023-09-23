#include <iostream>
#include <thread>
#include <chrono>

void sayHello(int sleepSeconds) {
    std::this_thread::sleep_for(std::chrono::seconds(sleepSeconds));
    std::cout << "Hello!" << " After " << sleepSeconds << " Seconds!" << std::endl;
}

// This is multithreading in C++, actually not that bad
// I was expecting something more complex than this
// But probably this is just the start.
int main() {
    std::thread t1(sayHello, 2);
    std::thread t2(sayHello, 1);

    t1.join();
    t2.join();
    std::cout << "All Thread Finished!" << std::endl;

    return 0;
}