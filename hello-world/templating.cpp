#include <iostream>
#include <string>

// <typename T> is basically creating a variable called T to store the typename
template <typename T>
void println(const T &s)
{ // Weird shit that the reference mark is in the front but I guess its C++.
    std::cout << s << std::endl;
}

/*
This is equivalent to typescript same shit that T is a variable.
const println<T>(T s) : T {
    console.log(s);
}
*/

int main()
{
    println("Hello, world!");
    println(1);
    println(0.22);
    return 0;
}