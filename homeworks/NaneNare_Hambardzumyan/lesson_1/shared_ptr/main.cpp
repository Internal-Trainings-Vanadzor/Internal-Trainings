#include <iostream>
#include "shared_ptr.h"

struct A {
    int x;
    int y;
    ~A() {
        std::cout << " Destr A= " << x << ',' << y << std::endl;
    }
};

int main()
{
    my_shared_ptr<A> shPtr1(new A);
    shPtr1->x = 2;
    (*shPtr1).y = 4;

    my_shared_ptr<A> shPtr2(new A);
    shPtr2->x = 3;
    (*shPtr2).y = 6;

    my_shared_ptr<A> shPtr3 = shPtr1;   //initialization
    std::cout << shPtr3->x << std::endl;
    std::cout << shPtr3->y << std::endl;

    shPtr2 = shPtr1;                //assignment
    std::cout << shPtr2->x << std::endl;
    std::cout << shPtr2->y << std::endl;
    std::cout << "Use count=" << shPtr3.getUseCount() << std::endl;
    std::cout << "Use count=" << shPtr2.getUseCount() << std::endl;
    std::cout << "Use count=" << shPtr1.getUseCount() << std::endl;
    return 0;
}
