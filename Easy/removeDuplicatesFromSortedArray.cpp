#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    int cur = INT_MIN;
    
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        if (*it != cur)
            cur = *it;
        else {
            nums.erase(it);
            it--;
        }
    }
    
    return nums.size();
}

int main(int argc, char** argv) {
    std::vector<int> sortedNumbers = { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5 };

    std::cout << removeDuplicates(sortedNumbers) << '\n';
    for (std::vector<int>::const_iterator it = sortedNumbers.begin(); it != sortedNumbers.end(); it++)
        std::cout << *it << ' ';
}