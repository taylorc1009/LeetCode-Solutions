#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int findKthPositive(std::vector<int>& arr, int k) {
    std::set<int> givenNums(arr.begin(), arr.end()), missingNums, result;
    int max = *std::max_element(arr.begin(), arr.end());

    //this is horrible, but there's no way to construct a set from 0 to n in C++
    for (int i = 1; i <= max; i++)
        missingNums.insert(missingNums.end(), i);

    std::set_difference(missingNums.begin(), missingNums.end(),
        givenNums.begin(), givenNums.end(),
        inserter(result, result.end()));

    int n;
    if (result.size() >= k)
        n = *next(result.begin(), k - 1);
    else
        n = max + (k - result.size());

    return n;
}

int main(int argc, char** argv) {
    std::vector<int> arr = { 4, 6, 7, 8, 9 };
    int k = 9;

    std::cout << findKthPositive(arr, k);
}