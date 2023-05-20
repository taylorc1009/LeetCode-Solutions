#include <iostream>

int fib(int n) {
    return n <= 1 ? n : fib(n - 2) + fib(n - 1);
}

int main(int argc, char **argv) {
    int n = 10;

    std::cout << fib(n) << std::endl;
}