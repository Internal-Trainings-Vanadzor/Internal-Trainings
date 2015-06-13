#include "myClass.hpp"
#include <iostream>

myClass::myClass (int* n) {
    ptr = n;
}

myClass::myClass (myClass& object) {
    ptr = object.ptr;
    object.ptr = NULL;
}
myClass& myClass::operator=(myClass& object) {
    ptr = object.ptr;
    object.ptr = NULL;
    return *this;
}
myClass::~myClass () {
    if (ptr) {
        delete ptr;
        //std::cout << "Deleted" << std::endl;
    }
}

void myClass::print_ptr_value () {
    if (ptr) {
        std::cout << *ptr << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }
}
void myClass::set_ptr_value(int new_value) {
    if (ptr) {
        *ptr = new_value;
    }
}
