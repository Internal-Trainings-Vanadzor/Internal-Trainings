#include "myClass.hpp"
#include <iostream>

void test () {
    myClass t;
    std::cout << myClass::get_count() << std::endl;
}

void test_with_param (myClass m) {
    std::cout << myClass::get_count() << std::endl;
}

int main () {
    myClass a;
    std::cout << myClass::get_count() << std::endl;
    myClass b;
    std::cout << myClass::get_count() << std::endl;
    myClass c(b);
    std::cout << myClass::get_count() << std::endl;
    myClass d;
    std::cout << myClass::get_count() << std::endl;
    d = a;
    std::cout << myClass::get_count() << std::endl;
    test();
    std::cout << myClass::get_count() << std::endl;
    test_with_param(c);
    std::cout << myClass::get_count() << std::endl;
    return 0;
}

