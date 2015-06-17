#include <iostream>

/**
 * This function reverses the given integer
 */
static int reverse (int number) {
    static int coefficient = 1;
    int div = number / 10;
    if (0 == div) {
        return number;
    }
    int result = reverse(div);
    coefficient *= 10;
    return result + number % 10 * coefficient;
}

int main () {
    unsigned int n;
    std::cout << "Please input an integer:" << std::endl;
    std::cin >> n;
    std::cout << "RESULT: " << reverse(n) << std::endl;
    return 0;
}
