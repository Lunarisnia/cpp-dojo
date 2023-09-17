#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> oldOwner = std::make_unique<int>(99);
    std::unique_ptr<int> x = std::move(oldOwner);

    if (oldOwner) {
        std::cout << "Owner is OldOwner: " << *oldOwner << std::endl;
    } else if (x) {
        std::cout << "Owner is X: " << *x << std::endl;
    }
    return 0;
}