#include "autoPtr.h"
	
autoPtr::autoPtr (int* n) {
    ptr = n;
}

autoPtr::autoPtr (autoPtr& obj) {
    ptr = obj.ptr;
    obj.ptr = NULL;
} 

autoPtr& autoPtr::operator=(autoPtr& obj) {
    ptr = obj.ptr;
    obj.ptr = NULL;
    return *this;
}

int autoPtr::getPtr() {
    return *ptr;    
}

autoPtr::~autoPtr() {
    if (ptr != NULL) {
	delete ptr;
    }
}


int main() {
    autoPtr a(new int (8));
    autoPtr b(new int(4));
    b = a;
    autoPtr c(new int(4));
    //std::cout <<"a= " << a.getPtr() << "\n";
    std::cout <<"b= " << b.getPtr() << "\n";
    std::cout <<"c= " << c.getPtr() << "\n";
    a.operator= (b);
    a = c;
    std::cout <<"a= " << a.getPtr() << "\n";
    b.~autoPtr(); 
    std::cout << a.getPtr() << "\n";
    return 0;
}
