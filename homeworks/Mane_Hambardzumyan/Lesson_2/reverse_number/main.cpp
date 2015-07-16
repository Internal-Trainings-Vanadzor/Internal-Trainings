#include<iostream>
#include <limits.h>

static long reverseByLoop(long number) {
    if (0 == number / 10) {
        return number; 
    }       

    long rev_num = 0;
    while(0 != number) {
        rev_num = rev_num * 10;
        rev_num = rev_num + number % 10;
        number = number / 10;
    }
    return rev_num;
}

static long reverseRecursive(long number, long rev) {
    if (0 == number / 10) {
        return rev * 10 + number; 
    }       
    return reverseRecursive(number / 10, rev * 10 + number % 10);
}

int main(int arc, char **argv) 
{
    long n = 0;
    long r = 0;
    
    std::cout << "Please input number lover than " << LONG_MAX << " ;) : ";
    std::cin >> n;
    std::cout << "The reverted number by loop: " << reverseByLoop(n) << "\n";
    std::cout << "The reverted number by recursive: " << reverseRecursive(n, 0) << "\n";
    return 0;
}

