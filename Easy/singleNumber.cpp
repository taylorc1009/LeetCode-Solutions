#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int c = 0, n = nums.size();

    for(int i = 0; i < n; i++)
        c = c ^ nums[i];

    return c;
}

int main(int argc, char** argv) {
    std::vector<int> nums = { 4, 1, 2, 1, 2 };

    std::cout << singleNumber(nums);
}