#include <iostream>
#include <vector>
#include <string>

void updateResult(std::vector<char>& result, char c, int count) {
    result.push_back(c);
    if (count > 1) {
        std::string numToStr = std::to_string(count);
        result.insert(result.end(), numToStr.begin(), numToStr.end());
    }
}

int compress(std::vector<char>& chars) {
    const int len = chars.size();
    if (len <= 1)
        return len;

    std::vector<char> result;
    char prevChar = chars[0];
    int curCount = 1;
    for (int i = 1; i < len; i++) {
        if (i == len - 1) {
            if (prevChar != chars[i]) {
                if (curCount > 1)
                    updateResult(result, prevChar, curCount);
                else
                    result.push_back(prevChar);
                prevChar = chars[i];
                curCount = 1;
            }
            else
                curCount++;
            updateResult(result, prevChar, curCount);
        }
        else if (prevChar != chars[i]) {
            updateResult(result, prevChar, curCount);
            prevChar = chars[i];
            curCount = 1;
        }
        else
            curCount++;
    }

    chars = result;
    return chars.size();
}

int main(int argc, char** argv) {
    std::vector<std::vector<char>> cases = {
        { 'a', 'a', 'b', 'b', 'c', 'c', 'c' },
        { 'a' },
        { 'a', 'b', 'c' },
        { 'a', 'a', 'b', 'b', 'c', 'c', 'c', 'a', 'a' },
        { 'a', 'a', 'a', 'a', 'b' }
    };

    for (std::vector<char>& _case: cases) {
        int size = compress(_case);

        for (char c : _case)
            std::cout << c;
        std::cout << " - " + std::to_string(size) + "\n";
    }
}