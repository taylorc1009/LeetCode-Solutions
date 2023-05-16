#include <iostream>

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

bool isPalindrome(int n) {
    int nTemp = n, nRev = 0;

    while(nTemp > 0) {
        nRev = nRev * 10 + (nTemp % 10);
        nTemp /= 10;
    }
    
    return n == nRev;
}

int primePalindrome(int n) {
    if (n == 1)
        return 2;
    if (n == 2 || n == 3)
        return n;

    int i = n % 2 ? n : n + 1; //since 2 is the only even prime number, we can start at n + 1 if n is even
    for (i; ; i += 2)
        if (isPalindrome(i) && isPrime(i))
            return i;
}

int main(int argc, char** argv) {
    int n = 13;

    std:: cout << primePalindrome(n);
}