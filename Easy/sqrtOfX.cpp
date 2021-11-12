#include <iostream>
#include <string>

//LeetCode's problem description asks that "mySqrt" returns a whole number
//this implementation uses a float instead to show greater efficiency
float mySqrt(int x) {
    float r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        int num = std::stoi(std::string(argv[1]));
        printf("%f", mySqrt(num));
    }
    else
        std::cout << "Please enter an integer to get the square root of it";
    
    return 0;
}