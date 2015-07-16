#include <iostream>
#include <assert.h> 
#include "AutoPointer.hpp"

using namespace std;

int main()
{
    AutoPointer obj(new int(5));
    cout<<*obj<<'\n';    
    AutoPointer obj1(new int(10));
    obj = obj1;
    cout<<*obj<<'\n';    
    assert(NULL == obj1.getPointer());

    AutoPointer obj2(new int(100));
    AutoPointer obj3(obj2);
    cout<<*obj3<<endl;
    assert(NULL == obj2.getPointer());

    int* nonAutoPtrObj1 = new int(2);
    int* nonAutoPtrObj2 = new int(4);
    nonAutoPtrObj1 = nonAutoPtrObj2;
    assert(NULL != nonAutoPtrObj2);
    return 0;
}
