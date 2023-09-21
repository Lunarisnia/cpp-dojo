#include <iostream>
#include <stdexcept>

void openDoor(int clearanceLevel) {
    if (clearanceLevel < 2) {
        throw std::runtime_error("Clearance level too low");
    }
    std::cout << "Welcome in" << std::endl;
}

int main() {
    int clearanceLevel = {0};
    std::cout << "Insert your clearance level: ";
    std::cin >> clearanceLevel;

    try
    {
        openDoor(clearanceLevel);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}