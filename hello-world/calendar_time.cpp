#include <iostream>
#include <chrono>


int main() {
    // Convert this to a time that can be printed.
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "A Timepoint representing Now: " << std::ctime(&now_c) << std::endl;

    return 0;
}