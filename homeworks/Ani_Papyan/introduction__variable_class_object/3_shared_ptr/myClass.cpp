#include "myClass.hpp"
#include <iostream>

myClass::myClass (int* n) {
    count = new int (1); 
    ptr = n;
}

myClass::myClass (myClass& object) {
    count = object.count;
    ptr = object.ptr;
    *count = *count + 1;
}
myClass& myClass::operator=(myClass& object) {
    if (1 == *count) {
        this->~myClass();
    }
    count = object.count;
    ptr = object.ptr;
    *count = *count + 1;
    return *this;
}
myClass::~myClass () {
    *count = *count - 1;
    //std::cout << "count: " << *count << std::endl;
    if (!(*count)) {
        delete ptr;
        delete count;
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
