#include <iostream>
#include <vector>
#include <algorithm>

// this solution was accepted but I'm not sure why because it's not O(n), which is what the problem description asks for
// std::sort is O(Nlog(N)) (C++20) and the loop following it is O(n), so the complexity equals these combined

int firstMissingPositive(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int cur = 1;

    for(int n : nums)
        if(cur == n)
            cur++;

    return cur;
}

int main(int argc, char** argv) {
    std::vector<int> nums = { 3, 4, -1, 1 };

    std::cout << firstMissingPositive(nums);
}