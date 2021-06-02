#include <string>
#include <iostream>

int strStr(std::string haystack, std::string needle) {
    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
        int j = 0;
        
        for (j; j < needle.size(); j++)
            if (haystack[i + j] != needle[j])
                break;
        
        if (j == needle.size())
            return i;
    }
    
    return -1;
}

int main(int argc, char** argv) {
    std::string haystack = "mississippi";
    std::string needle = "issip";

    std::cout << strStr(haystack, needle);
}