#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits) {
    if (digits.empty())
        return {};
    
    int index = digits.size() - 1;

    do {
        digits[index] == 9 ? digits[index] = 0 : digits[index]++;

        if (!digits[index])
            index--;
    } while(index > -1 && !digits[index + 1]);

    if (index == -1)
        digits.insert(digits.begin(), 1);
    
    return digits;
}

int main(int argc, char** argv) {
    std::vector<int> digits = { 9, 9, 9 };

    digits = plusOne(digits);
    for (std::vector<int>::const_iterator it = digits.begin(); it != digits.end(); it++)
        std::cout << *it;
}