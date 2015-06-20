#include "objectsCount.hpp"
#include <iostream>

static void testDestructorCall(){
objectsCount c;
std::cout << objectsCount::getObjectsCount() << std::endl;
}

int main () {
    objectsCount a, b;
    std::cout << objectsCount::getObjectsCount() << std::endl;
    objectsCount c(b);
    std::cout << objectsCount::getObjectsCount() << std::endl; 
    testDestructorCall();
    std::cout << objectsCount::getObjectsCount() << std::endl; 

    return 0;
}
