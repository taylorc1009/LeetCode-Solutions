#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, std::string> mappings = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void combinationsHelper(std::string digits, std::string& combination, std::vector<std::string>& results) {
    if (!digits.empty())
        for (char c : mappings[digits[0]])
            combinationsHelper(digits.substr(1), combination += c, results);
    else
        results.push_back(combination);

    combination.pop_back();
}

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty())
        return {};

    std::vector<std::string> results;
    std::string combination = ""; //using a reference to save memory
    combinationsHelper(digits, combination, results);
    return results;
}

int main(int argc, char** argv) {
    std::string digits = "23";

    std::vector<std::string> results = letterCombinations(digits);

    for (std::string result : results)
        std::cout << result << std::endl;
}