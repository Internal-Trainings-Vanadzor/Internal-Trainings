#ifndef MY_OBJECT 
#define MY_OBJECT 

#include <iostream>
#include "point.h"

class MyObject {
    public:
        virtual float area() = 0;
        virtual bool isContains(const MyPoint&) = 0;
};

#endif
