#include <iostream>
#include <vector>

class Solution {
    public:
        int maxProduct(std::vector<int>& nums) {
            int numsLength = nums.size();
            if (numsLength == 2) {
                return (nums[0] - 1) * (nums[1] - 1);
            }

            int maxP = 0;
            int j = 0;
            for (int i = 0; i < numsLength; i++) {
                for (int j = 0; j < numsLength; j++) {
                    if (i == j) {
                        continue;
                    }

                    int tempProduct = (nums[i] - 1) * (nums[j] - 1);
                    if (tempProduct > maxP) {
                        maxP = tempProduct;
                    }
                } 
            }
            
            return maxP;
        }
};

int main() {
    Solution* solution = new Solution();

    std::vector<int> nums{3, 4, 5, 2};
    std::cout << solution->maxProduct(nums) << std::endl;
    
    free(solution);
    // Solution so1 = new Solution();

    return 0;
}