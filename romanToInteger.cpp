#include <unordered_map>
#include <iostream>

std::unordered_map<char, int> numerals = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    
};

int romanToInt(std::string s) {
    int integer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1) {
            if (numerals[s[i]] < numerals[s[i + 1]]) {
                integer += numerals[s[i + 1]] - numerals[s[i]];
                i++;
                continue;
            }
        }
        integer += numerals[s[i]];
    }
    
    return integer;
}

int main(int argc, char** argv) {
    std::string romanNumeral = "MCMXCIV"; //1994 (M = 1000, CM = 900, XC = 90 and IV = 4)
    std::cout << romanToInt(romanNumeral);
}