//! must be faster than or equal to n*log(n) complexity

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> sortArray(std::vector<int>& nums) {// Counting Sort
    const int nums_length = nums.size(),
        max = *max_element(nums.begin(), nums.end()),
        min = *min_element(nums.begin(), nums.end()),
        range = max - min + 1;

    std::vector<int> count(range), output(nums_length);
    
    for (int i = 0; i < nums_length; i++)
        count[nums[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = nums_length - 1; i >= 0; i--) {
        output[count[nums[i] - min] - 1] = nums[i];
        count[nums[i] - min]--;
    }

    return output;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {5, 1, 3, 0, 9, 2, 8, 7}, result = sortArray(nums);
    std::string output = "";

    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); i++)
        output += std::to_string(*i) + (i < result.end() - 1 ? ", " : "");
    std::cout << output;
}