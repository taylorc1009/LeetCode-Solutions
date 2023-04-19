#include <iostream>
#include <string>

std::string mergeAlternately(std::string word1, std::string word2) {
    const int len1 = word1.size(), len2 = word2.size();
    if (!len1 && !len2)
        return "";

    std::string result = "";
    int it1 = 0, it2 = 0;
    bool wordSwitch = true;

    for(;;) {
        if (wordSwitch) {
            if (it1 < len1)
                result += word1[it1++];
            else {
                result.append(word2.substr(it2, len2 - 1));
                break;
            }
        }
        else {
            if (it2 < len2)
                result += word2[it2++];
            else {
                result.append(word1.substr(it1, len1 - 1));
                break;
            }
        }
        wordSwitch = !wordSwitch;
    }

    return result;
}

int main(int argc, char** argv) {
    std::string word1 = "ab", word2 = "pqrs";

    std::cout << mergeAlternately(word1, word2);
}