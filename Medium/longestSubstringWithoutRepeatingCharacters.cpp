#include <string>
#include <iostream>

int lengthOfLongestSubstring(std::string s) {
    int longest = 0, current = 0;
    std::string substr = "";

    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        int pos = substr.find(*it);

        if (pos == std::string::npos) {
            current++;
            substr.push_back(*it);
        }
        else {
            substr = substr.substr(pos + 1);
            substr.push_back(*it);
            current = substr.length();
        }

        if (current > longest)
            longest = current;
    }

    return longest;
}

int main(int argc, char** argv) {
    //std::string str = "pwwkew";
    std::string str = "dvdf";
    //std::string str = "dddd";

    std::cout << lengthOfLongestSubstring(str);

    return 0;
}