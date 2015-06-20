#include "my_shared_ptr.h"

//TODO Need to implement functionality to parse command line arguments 

int main() 
{
    sharedPtr a(8);
    //sharedPtr b = a;
    sharedPtr b(4);
    sharedPtr c(4);
    std::cout <<"a= " << a.getCount() << "\n";
    std::cout <<"b= " << b.getCount() << "\n";
    std::cout <<"c= " << c.getCount() << "\n";
    a.operator= (b);
    a = c;
    std::cout <<"a= " << a.getCount() << "\n";
    std::cout <<"b= " << b.getCount() << "\n";
    std::cout <<"c= " << c.getCount() << "\n";
    b.~sharedPtr(); 
    std::cout << a.getCount() << "\n";
    return 0;
}
