#include <string>
#include <iostream>

using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int main() {
    int original = 10;
    int& referencesOfOriginal = original;

    // Prints the value
    std::cout << referencesOfOriginal << std::endl;

    referencesOfOriginal++;
    std::cout << "AFTER MODIFIED: " << original << std::endl;


    int x = 10;
    int y = 88;

    std::cout << "Before Swap" << " X: " << x << " Y: " << y << std::endl;

    swap(x, y);
    std::cout << "After Swap" << " X: " << x << " Y: " << y << std::endl;
}