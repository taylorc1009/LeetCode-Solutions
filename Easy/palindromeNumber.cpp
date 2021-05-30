#include <iostream>
#include <climits>

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    
    int rev = 0;
    int num = x;

    while (num != 0) {
        int pop = num % 10;
        num /= 10;

        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7))
            return 0;

        rev = rev * 10 + pop;
    }

    return rev == x;
}

int main(int argc, char** argv) {
    int number = 121;
    std::cout << isPalindrome(number);
}