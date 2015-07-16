#include "my_shared_ptr.h"

sharedPtr::sharedPtr(int i) {
    objectsCount = new int (1);
    number = new int (i);
}
    
sharedPtr::sharedPtr(const sharedPtr& object) {
    number = object.number;
    objectsCount = object.objectsCount;
    (*objectsCount)++;
}
    
void sharedPtr::operator=(const sharedPtr& b) {
    (*objectsCount)--; 
    if ((*objectsCount) == 0){
        delete number;
        delete objectsCount;
    };
    number = b.number;
    objectsCount = b.objectsCount;
    (*objectsCount)++;
}


int sharedPtr::getCount() {
    return *objectsCount;
}

sharedPtr::~sharedPtr() {
    (*objectsCount) --;
    if (*objectsCount == 0) {
        delete number;
        delete objectsCount;
    }
}
