#include "myClass.hpp"
#include <iostream>

void f (myClass h) {
    myClass a(new int(5));
    myClass c(new int(5));
    myClass b(h);
    b=a=c;
    b.set_ptr_value(777);
    std::cout << "Leaving function" << std::endl;
}

int main () {
    myClass a(new int(4));
    myClass n(new int(6));
    //myClass b(a);
    //myClass c(n);
    //c.set_ptr_value(290);
    //a = n;
    //n.print_ptr_value();
    //a.print_ptr_value();
    f(n);
    n.print_ptr_value();
    std::cout << "FINISH" << std::endl;
    return 0;
}
