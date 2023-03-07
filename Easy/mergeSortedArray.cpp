#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (!m) {
        nums1 = nums2;
        return;
    }
    if (!n)
        return;

    //you can also use "copy" instead of "erase" & "insert", but this is slower
    //copy(nums2.begin(), nums2.end(), nums1.begin() + m);

    nums1.erase(nums1.begin() + m, nums1.end());
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());
}

int main(int argc, char** argv) {
    std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 }, nums2 = { 2, 5, 6 };
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (int num : nums1)
        std::cout << num;
}