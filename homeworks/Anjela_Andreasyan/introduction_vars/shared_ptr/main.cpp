#include <iostream>
#include "shared_ptr.cpp"
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    shared_ptr<int> x(new int(5));
    cout << x.get() << endl; 
    x.reset(new int(7));
    cout << x.get() << endl; 
    shared_ptr<int> y = x;
    {
        shared_ptr<int> z1(new int(9));
        cout << z1.get() << endl;
        cout << z1.getPtr() << endl;
        shared_ptr<int> z2(y);
        cout << z2.get() << endl;
        cout << z2.getPtr() << endl;
        cout << y.getPtr() << endl;
        y=z1;
        cout << y.getPtr() << endl;
        cout<<"Y ref count in scope: "<< y.getCount()<<endl;
    }
    cout << x.get() << endl; 
    cout << y.get() << endl;
    cout << y.getPtr() << endl;
    cout<<"Y ref count: "<< y.getCount()<<endl;
    return 0;
}
