#include <iostream>
#include <limits.h>

#include "A.hpp"

unsigned long A::s_instances_count = 0;

A::A() {

    if (s_instances_count - 1 > ULONG_MAX) {
        std::cout << "[WARNING]: Elements count at red limit !!!.\n";
    }
    ++s_instances_count;
}

A::A(const A& obj) {
    if (s_instances_count - 1 > ULONG_MAX) {
        std::cout << "[WARNING]: Elements count at red limit !!!.\n";
    }
    ++s_instances_count;
}

A::~A() {
    --s_instances_count;
    if (!s_instances_count) {
        std::cout << "[INFO]: All elements were destroyed !!!.\n";
    }
}

unsigned long A::getInstancesCount() {
    return s_instances_count;
}
