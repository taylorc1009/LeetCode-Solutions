#include <vector>
#include <numeric>
#include <iostream>

int maxSubArray(std::vector<int>& nums) {
    if (nums.empty())
        return 0;
    
    int current = nums[0], next = nums[0];

    for (std::vector<int>::const_iterator it = nums.begin() + 1; it != nums.end(); it++) {
        next = std::max(next + *it, *it);
        current = std::max(next, current);
    }
    
    return current;
}

int main(int argc, char** argv) {
    std::vector<int> numbers = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    std::cout << maxSubArray(numbers);
}