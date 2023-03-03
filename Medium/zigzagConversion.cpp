#include <iostream>
#include <string>
#include <vector>

std::string convert(std::string s, int numRows) {
    std::vector<std::vector<char>> zigzag(numRows);
    int i = 0, sLen = s.size();

    while (i < sLen) {
        int j = 0;
        while (i < sLen && j < numRows) {
            zigzag[j].push_back(s[i]);
            i++; j++;
        }

        j = numRows - 2;
        while (i < sLen && j > 0) {
            zigzag[j].push_back(s[i]);
            i++; j--;
        }
    }

    std::string output = "";
    for (std::vector<char> i : zigzag)
        for (char j : i)
            output += j;

    return output;
}

int main(int argc, char** argv) {
    std::string s = "PAYPALISHIRING";
    int numRows = 3;

    std::cout << convert(s, numRows);
}