#include <iostream>

int myAtoi(std::string s) {
    int i = 0, scalar = 0;

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            if (i < INT32_MAX / 10 || (i == INT32_MAX / 10 && c <= (scalar == 1 ? '7' : '8')))
                i = (i * 10) + (c - '0');
            else
                return scalar >= 0 ? INT32_MAX : INT32_MIN;
            
            if (!scalar)
                scalar = 1;
        }
        else if (!scalar)
            scalar = c == '-' ? -1 : 1;
        else if (!(c == ' ' && i == 0))
            break;
    }

    return i * scalar;
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::string str = "";
        for (int i = 1; i < argc; i++)
            str += std::string(argv[i]);
        printf("%d", myAtoi(str)); //use 'printf' to help prove that the type has been changed to an integer
    }
    else
        std::cout << "Please enter a number to be converted to an integer";
}