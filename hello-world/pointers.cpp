#include <string>
#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    int original = 10;
    int* pointerOfOriginal = &original;

    // Prints the address of the value quite literally
    std::cout << pointerOfOriginal << std::endl;

    int (*function_pointer) (int, int) = add;
    std::cout << function_pointer(5, 1) << std::endl;
}