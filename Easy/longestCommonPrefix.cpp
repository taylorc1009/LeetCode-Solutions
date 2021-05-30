#include <string>
#include <vector>
#include <iostream>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.size() == 0)
        return "";
    
    std::string prefix = strs[0];
    
    for (std::vector<std::string>::iterator it = strs.begin() + 1; it != strs.end(); it++) {
        while ((*it).find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            
            if (prefix.empty())
                return "";
        }
    }
    
    return prefix;
}

int main(int argc, char** argv) {
    std::vector<std::string> strings = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(strings);
}