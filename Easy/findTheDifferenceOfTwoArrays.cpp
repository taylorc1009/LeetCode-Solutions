#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> nums1Set(nums1.begin(), nums1.end()),
                            nums2Set(nums2.begin(), nums2.end());
    std::vector<std::vector<int>> results(2);

    for (int num : nums1Set)
        if (nums2Set.find(num) == nums2Set.end())
            results[0].push_back(num);

    for (int num : nums2Set)
        if (nums1Set.find(num) == nums1Set.end())
            results[1].push_back(num);

    return results;
}

int main(int argc, char** argv) {
    std::vector<int> nums1 = { 1, 2, 3 }, nums2 = { 2, 4, 6 };

    std::vector<std::vector<int>> results = findDifference(nums1, nums2);

    for (int num : results[0])
        std::cout << num << ' ';
    std::cout << std::endl;
    for (int num : results[1])
        std::cout << num << ' ';
}