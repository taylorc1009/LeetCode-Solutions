#include <unordered_map>
#include <iostream>

class Solution {
private:
    std::unordered_map<char, int> numerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
        
    };
public:
    int romanToInt(std::string s) {
        int integer = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1) {
                if (this->numerals[s[i]] < this->numerals[s[i + 1]]) {
                    integer += this->numerals[s[i + 1]] - this->numerals[s[i]];
                    i++;
                    continue;
                }
            }
            integer += this->numerals[s[i]];
        }
        
        return integer;
    }
};

int main(int argc, char** argv) {
    std::string romanNumeral = "MCMXCIV"; //1994 (M = 1000, CM = 900, XC = 90 and IV = 4)
    Solution solution; //the class can't be static as it has a member that cannot be a "const": "numerals" is an unordered map and only integral/enumerated types can be consts
    std::cout << solution.romanToInt(romanNumeral);
}