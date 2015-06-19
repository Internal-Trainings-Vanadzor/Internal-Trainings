#include "customAutoPtr.cpp"
#include <iostream>
using namespace std;

int main () {
    customAutoPtr<int> a(new int(11));
    customAutoPtr<int> c(new int(15));
    customAutoPtr<int> d(new int(17));
    cout<<"a's pointer before copy ";
    a.printPtr();

    customAutoPtr<int> b(a);

    cout<<"a's pointer after copy ";
    a.printPtr();   
    cout<<"b's pointer after copy ";
    b.printPtr(); 
    cout<<"c's pointer before assignment ";
    c.printPtr(); 
    cout<<"d's pointer before assignment ";
    d.printPtr();     

    c = d;
    cout<<"c's pointer after assignment ";
    c.printPtr(); 
    cout<<"d's pointer after assignment ";
    d.printPtr(); 

    c=c;
    cout<<"c's pointer after self assignment ";
    c.printPtr(); 
   
    return 0;
}
