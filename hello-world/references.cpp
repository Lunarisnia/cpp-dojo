#include <string>
#include <iostream>

using namespace std;


int main() {
    int original = 10;
    int& referencesOfOriginal = original;

    // Prints the value
    std::cout << referencesOfOriginal << std::endl;
}