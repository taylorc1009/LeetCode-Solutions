#include <vector>
#include <iostream>

int searchInsert(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;
        
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main(int argc, char** argv) {
    std::vector<int> numbers = { 1, 3 };
    int target = 2;

    std::cout << searchInsert(numbers, target);
}