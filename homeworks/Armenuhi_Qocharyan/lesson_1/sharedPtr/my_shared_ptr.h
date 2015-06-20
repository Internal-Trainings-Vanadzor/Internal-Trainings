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
