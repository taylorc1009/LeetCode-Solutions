#include <vector>
#include <iostream>

int removeElement(std::vector<int>& nums, int val) {
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        if (*it == val) {
            nums.erase(it);
            it--;
        }
    }
    
    return nums.size();
}

int main(int argc, char** argv) {
    std::vector<int> numbers = { 2, 2, 3, 3, 4, 1, 5, 1, 3, 5, 1 };
    int target = 3;

    std::cout << removeElement(numbers, target) << '\n';
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << ' ';
}