#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> nums = {1, 2, 9, 4};

    std::istream_iterator<int> input;
    std::copy(input, std::istream_iterator<int>(), std::back_inserter(nums));
    std::cout << "Hey" << std::endl;
    return 0;
}