#include <string>
#include <iostream>

using namespace std;


int main() {
    int original = 10;
    int* pointerOfOriginal = &original;

    // Prints the address of the value quite literally
    std::cout << pointerOfOriginal << std::endl;
}