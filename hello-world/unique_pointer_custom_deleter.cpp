#include <iostream>
#include <memory>

/*
    C++ has the ability to assign callback when a unique_pointer
    goes out of scope. That sounds convinient.
*/
struct MyDeleter {
    void operator()(int* ptr) {
        std::cout << "Custom Deleter Called!" << std::endl;
        delete ptr;
    }
};

int main() {
    // For custom deleter you need to do it this way
    std::unique_ptr<int, MyDeleter> x(new int(1), MyDeleter());
    return 0;
}