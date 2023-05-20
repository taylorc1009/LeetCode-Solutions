#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);

    for (int i = 1; i <= n; i++)
        if (!(i % 15))
            result[i - 1] = "FizzBuzz";
        else if (!(i % 3))
            result[i - 1] = "Fizz";
        else if (!(i % 5))
            result[i - 1] = "Buzz";
        else
            result[i - 1] = std::to_string(i);

    return result;
}

int main(int argc, char** argv) {
    int n = 15;

    std::vector<std::string> result = fizzBuzz(n);

    for (std::string str : result)
        std::cout << str << std::endl;
}