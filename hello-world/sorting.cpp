#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> unsorted = {3, 1, 7, 8, 5, 2};
    std::sort(unsorted.begin(), unsorted.end());

    for (int num : unsorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}