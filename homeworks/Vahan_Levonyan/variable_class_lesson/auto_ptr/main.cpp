#include <iostream>
#include "auto_ptr.h"
#include <string>
int main () {
    auto_ptr<int> p;
    auto_ptr<int> p2;

    p = auto_ptr<int> (new int);

    *p = 11;

    p2 = p;

    std::cout << "p2 points to " << *p2 << std::endl;
    // (p is now null-pointer auto_ptr)

    return 0;
}
