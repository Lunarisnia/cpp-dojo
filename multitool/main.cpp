#include "calculator.h"
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string appMenu;
    
    std::cout << "Which app do you want to use (CALCULATOR, PGEN)? ";
    std::cin >> appMenu;
    std::transform(appMenu.begin(), appMenu.end(), appMenu.begin(), toupper);
    
    if (appMenu == "CALCULATOR") {
        Calculator::interface();
    } else if (appMenu == "PGEN") {
        std::cout << "Not Implemented" << std::endl;
    } else {
        std::cout << "Invalid app." << std::endl;
    }

    return 0;
}