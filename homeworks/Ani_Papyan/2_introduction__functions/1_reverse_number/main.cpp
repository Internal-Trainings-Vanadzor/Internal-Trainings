#include <iostream>

/**
 * This function will be called in another function which reverses the given iteger
 */
static int reverse (int number, int step, int& max) {
    if (0 == number / 10) {
        return number;
    }
    max *= 10;
    return reverse(number / 10, step * 10, max) + (number%10) * max / step;
}

/**
 * This function reverses the given integer
 */
static int reverse (int number) {
    int ref = 1;
    return reverse(number, 1, ref);
}

int main () {
    unsigned int n;
    std::cout << "Please input an integer:" << std::endl;
    std::cin >> n;
    std::cout << "RESULT: " << reverse(n) << std::endl;
    return 0;
}
