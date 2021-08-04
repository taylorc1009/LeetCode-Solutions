#include <string>
#include <unordered_map>
#include <bitset>
#include <iostream>

std::string addBinary(std::string a, std::string b) {
    int sum = 0, increment = 1, a_it = a.size() - 1, b_it = b.size() - 1;

    while (a_it >= 0 || b_it >= 0) {
        if (a_it >= 0) {
            if (a[a_it] == '1')
                sum += increment;
            a_it--;
        }

        if (b_it >= 0) {
            if (b[b_it] == '1')
                sum += increment;
            b_it--;
        }

        increment *= 2;
    }

    std::string binaryStr = std::bitset<32>(sum).to_string();
    binaryStr.erase(0, binaryStr.find_first_not_of('0'));
    
    return binaryStr;
}

int main(int argc, char** argv) {
    std::string a = "0";
    std::string b = "0";

    std::cout << addBinary(a, b);
}