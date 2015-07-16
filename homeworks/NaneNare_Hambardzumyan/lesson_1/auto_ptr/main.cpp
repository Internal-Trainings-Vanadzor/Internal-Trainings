#include <iostream>
#include <string>
#include "auto_ptr.h"

struct A {
    int x;
    int y;
    ~A() {
        std::cout << " Destr A= " << x << ',' << y << std::endl;
    }
};

int main()
{
    my_auto_ptr<A> auSh1(new A);
    auSh1->x = 2;
    (*auSh1).y = 4;

    my_auto_ptr<A> auSh2(new A);
    auSh2->x = 3;
    (*auSh2).y = 6;

    my_auto_ptr<A> auSh3 = auSh1;   //initialization
    std::cout << auSh3->x << std::endl;
    std::cout << auSh3->y << std::endl;

    auSh2 = auSh3;                //assignment
    std::cout << auSh2->x << std::endl;
//    std::cout << auSh2->y << std::endl;

//   my_auto_ptr<std::string> film (new std::string("Goose Eggs"));
//   my_auto_ptr<std::string> pwin;
//   pwin = film;
//
//   std::cout << "The nominees for best avian baseball film are\n";
//   std::cout << "The winner is " << *pwin << "!\n";
    return 0;
}
