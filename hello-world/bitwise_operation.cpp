#include <iostream>
#include <string>

using namespace std;

void println(string message) {
    std::cout << message << std::endl;
}

int bitwise_and() {
    // 0000 0110 (6)
    // &
    // 0000 1010 (10)
    return 6 & 10; // 0000 0010 (2)
}

int bitwise_or() {
    // 0000 0101 (5)
    // |
    // 0000 1010 (10)
    return 5 | 10; // 0000 1111 (15)
}

int bitshift_left() {
    // 0000 0101 (5)
    // <<
    // 1
    return 5 << 1; // 0000 1010 (10) Shifting one step to the left
}

int bitshift_right() {
    // 0000 0101 (5)
    // >>
    // 1
    return 5 >> 1; // 0000 0010 (2) Shifting one step to the right
}

int main() {
    println("6 & 10: " + std::to_string(bitwise_and()));
    println("5 | 10: " + std::to_string(bitwise_or()));
    println("5 << 1: " + std::to_string(bitshift_left()));
    println("5 >> 1: " + std::to_string(bitshift_right()));
    return 0;
}
