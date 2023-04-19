#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    std::string sStripped = "", sRev = "";

    for (char c : s)
        if (isalnum(c)) {
            if (isupper(c)) {
                const char lower = tolower(c);
                sStripped += lower;
                sRev.insert(0, 1, lower);
            }
            else {
                sStripped += c;
                sRev.insert(0, 1, c);
            }
        }

    return sStripped == sRev;
}

int main(int argc, char** argv) {
    std::string s = "A man, a plan, a canal: Panama";

    std::cout << isPalindrome(s);
}