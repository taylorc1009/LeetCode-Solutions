#include <iostream>
#include <climits>

int reverse(int x) {
    int rev = 0;
    
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        
        //prevents overflow of a 32-bit integer
        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) //'... > 7' as 7 is the last digit of INT_MAX ('2147483647')
            return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) //'... > -8' as 8 is the last digit of INT_MIN ('-2147483648')
            return 0;
        
        rev = rev * 10 + pop;
    }
    
    return rev;
}

int main(int argc, char** argv) {
    int intToReverse = 123;
    std::cout << reverse(intToReverse);
}