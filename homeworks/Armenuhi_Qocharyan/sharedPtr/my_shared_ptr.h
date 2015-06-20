#include <iostream>

class sharedPtr {
    public: 
        sharedPtr(int i);
        sharedPtr(const sharedPtr& object);
        int getCount();
        void operator=(const sharedPtr& b);
        ~sharedPtr();

    private: 
        int* objectsCount;
        int* number;

};
/*
sharedPtr::sharedPtr(int i) {
    objectsCount = new int(0);
    number = new int (i);
}
    
sharedPtr::sharedPtr(const sharedPtr& object) {
    number = object.number;
    objectsCount = object.objectsCount;
    (*objectsCount)++;
}
    
void sharedPtr::operator=(const sharedPtr& b) {
    // if my space is not used DELETE
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

*/
