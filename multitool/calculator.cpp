#include "calculator.h"
#include <iostream>
#include <string>
#include <algorithm>

// Define the function that you have declared in .h like this
void Calculator::interface()
{
    int x = {0};
    int y = {0};

    std::cout << "Insert X: ";
    std::cin >> x;
    std::cout << "Insert Y: ";
    std::cin >> y;

    std::string op;
    std::cout << "Chose the operator (ADD, SUBTRACT, MULTIPLY, DIVIDE): ";
    std::cin >> op;
    std::transform(op.begin(), op.end(), op.begin(), toupper);

    if (op == "ADD")
    {
        std::cout << "Result: " << Calculator::add(x, y) << std::endl;
    }
    else if (op == "SUBTRACT")
    {
        std::cout << "Result: " << Calculator::subtract(x, y) << std::endl;
    }
    else if (op == "MULTIPLY")
    {
        std::cout << "Result: " << Calculator::multiply(x, y) << std::endl;
    }
    else if (op == "DIVIDE")
    {
        std::cout << "Result: " << Calculator::divide(x, y) << std::endl;
    } else {
        std::cout << "Invalid operator." << std::endl;
    }
}

int Calculator::add(int x, int y)
{
    return x + y;
}

int Calculator::subtract(int x, int y)
{
    return x - y;
}

int Calculator::multiply(int x, int y)
{
    return x * y;
}

int Calculator::divide(int x, int y)
{
    return x / y;
}

// This is wrong
// class Calculator {
//     public:
//         static int add(int x, int y) {
//             return x + y;
//         };
// };