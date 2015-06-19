#include <iostream>
#include "auto_ptr.cpp"
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int *i = new int;
    auto_ptr<int> x(i);
    cout << x.get() << endl; 
    auto_ptr<int> y;
    y = x;
    cout << x.get() << endl; 
    cout << y.get() << endl;
    y.reset(new int);
    cout << y.get() << endl;
    y.reset(i);
    cout << y.get() << endl;
    return 0;
}
