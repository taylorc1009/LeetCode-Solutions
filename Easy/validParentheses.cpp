#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>

std::unordered_map<char, char> map = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
};

bool isValid(std::string s) {
    std::stack<char> parentheses;

    for (int i = 0; i < s.length(); i++) {
        if (map.find(s[i]) != map.end())
            parentheses.push(s[i]);
        else if (!parentheses.empty() && map.at(parentheses.top()) == s[i])
            parentheses.pop();
        else
            return false;
    }

    if (!parentheses.empty())
        return false;
    return true;
}

int main(int argc, char** argv) {
    std::string parentheses = "({[]}){}[()]";
    std::cout << isValid(parentheses);
}