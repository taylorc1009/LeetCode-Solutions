#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    int len = 0, cur = INT_MIN;
    
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        if (*it != cur) {
            cur = *it;
            len++;
        }
        else {
            nums.erase(it);
            it--;
        }
    }
    
    return len;
}

int main(int argc, char** argv) {
    std::vector<int> sortedNumbers = { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5 };

    int length = removeDuplicates(sortedNumbers);

    std::cout << length << '\n';
    for (std::vector<int>::const_iterator it = sortedNumbers.begin(); it != sortedNumbers.end(); it++)
        std::cout << *it << ' ';
}