#include <string>
#include <iostream>

static inline std::string trim(std::string s) {
    while(s.size() && isspace(s.front())) 
        s.erase(s.begin());
    while(s.size() && isspace(s.back())) 
        s.pop_back();

    return s;
}

int lengthOfLastWord(std::string s) {
    if (s.empty())
        return 0;
    
    s = trim(s);
    int length = 0;

    for (std::string::const_reverse_iterator it = s.rbegin(); it != s.rend(); it++)
        if (!std::isspace(*it))
            length++;
        else
            break;
    
    return length;
}

int main(int argc, char** argv) {
    std::string str = std::string("Hello world!   ");
    std::cout << lengthOfLastWord(str);
}