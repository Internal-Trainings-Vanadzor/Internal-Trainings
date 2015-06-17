#include "myClass.hpp"
#include <iostream>

void f (myClass h) {
    myClass a(new int(5));
    myClass c(new int(5));
    myClass b(h);
    b.set_ptr_value(777);
    std::cout << "Leaving function" << std::endl;
}

int main () {
    myClass a(new int(4));
    myClass n(new int(6));
    myClass c(a);
    n = a;
    f(n);
    a.print_ptr_value();
    n.print_ptr_value();
    c.print_ptr_value();
    return 0;
}
