#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
    std::vector<int> nums(n);

    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; i++)
        if (i1 == n1)
            for (i; i < n; i++)
                nums[i] = nums2[i2++];
        else if (i2 == n2)
            for (i; i < n; i++)
                nums[i] = nums1[i1++];
        else
            nums[i] = nums1[i1] < nums2[i2] ? nums1[i1++] : nums2[i2++];

    return n % 2 ? nums[n / 2] : (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
}

int main(int argc, char** argv) {
    std::vector<int> nums1 = { 1, 2 }, nums2 = { 3, 4 };

    std::cout << findMedianSortedArrays(nums1, nums2);
}