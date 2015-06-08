#include "myClass.hpp"

int myClass::count (0);

myClass::myClass () {
    ++count; 
}

myClass::myClass (myClass& object) {
    ++count; 
}

myClass::~myClass () {
    --count;
}
int myClass::get_count() {
    return myClass::count;
}
