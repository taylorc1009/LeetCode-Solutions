#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    
    //for (std::vector<int>::iterator num = nums.begin(); num != nums.end(); num++) {
    for (int i = 0; i < nums.size(); i++) {
        //int complement = target - *num;
        int complement = target - nums.at(i);
        
        if (map.find(complement) != map.end())
            //return { map.at(complement), (int)std::distance(nums.begin(), num) };
            return { map.at(complement), i };
        
        //map.insert(std::pair<int, int>(std::distance(nums.begin(), num), *num));
        map.insert(std::pair<int, int>(nums.at(i), i));
    }
    return {};
}

int main(int argc, char** argv) {
    std::vector<int> result = twoSum({2, 7, 11, 15}, 9);
    
    for (std::vector<int>::const_iterator it = result.begin(); it != result.end(); it++)
        std::cout << *it << ' ';
}
