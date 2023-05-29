#include <iostream>
#include <vector>

void permuteHelper(std::vector<int>& nums, std::vector<int>& cur, const int depth, std::vector<std::vector<int>>& result) {
    if (nums.empty()) {
        result.push_back(cur);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        cur[depth] = nums[i];
        nums.erase(nums.begin() + i);

        permuteHelper(nums, cur, depth + 1, result);

        nums.insert(nums.begin() + i, cur[i]);
        nums[i] = cur[depth];
    }

    cur[depth] = 0;
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    if (nums.empty())
        return {};

    std::vector<int> cur(nums.size());
    std::vector<std::vector<int>> result;

    permuteHelper(nums, cur, 0, result);

    return result;
}

int main(int argc, char** argv) {
    std::vector<int> nums = { 1, 2, 3 };

    std::vector<std::vector<int>> result = permute(nums);

    for (std::vector<int> r : result) {
        for (int n : r)
            std::cout << n;
        std::cout << std::endl;
    }
}