#include "customSharedPtr.cpp"
#include <iostream>
using namespace std;

int main () {
    customSharedPtr<int> a(new int(11));
    customSharedPtr<int> c(new int(15));
    customSharedPtr<int> d(new int(17));
    cout<<"a's pointer is ";
    a.printPtr();
    cout<<"c's pointer is ";
    c.printPtr(); 
    c=a;
    cout<<"c's pointer after assignment ";
    c.printPtr();   
    cout<<"a's pointer after assignmnet ";
    a.printPtr();  

    customSharedPtr<int> b(a);

    cout<<"b's pointer after copy ";
    b.printPtr();   
    cout<<"a's pointer after copy ";
    a.printPtr();  

    cout<<"The number of the pointer is "<<a.getPointersCount()<<endl;
   
    return 0;
}
