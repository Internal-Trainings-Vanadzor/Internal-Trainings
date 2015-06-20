#include <iostream>

#include "auto_ptr.hpp"

int main(int arc, char **argv) 
{
    int* a = new int(5);
    AutoPtr<int> p_a(a);
    std::cout << "Address p_a = : " << p_a.get() << "\n";
    std::cout << "Value *p_a = : " << *p_a.get() << "\n";
    *p_a.get() = 7;
    std::cout << "--------------------\n";
    std::cout << "Address p_a = : " << p_a.get() << "\n";
    std::cout << "Value *p_a = : " << *p_a.get() << "\n";

    AutoPtr<int> p_b;
    p_b = p_a;
    std::cout << "--------------------\n";
    std::cout << "Address p_a = : " << p_a.get() << "\n";
    std::cout << "Address p_b = : " << p_b.get() << "\n";
    std::cout << "Value *p_b = : " << *p_b.get() << "\n";

    p_a.reset(new int);
    *p_a = 11;
    std::cout << "--------------------\n";
    std::cout << "Address p_a = : " << p_a.get() << "\n";
    std::cout << "Value *p_a = : " << *p_a.get() << "\n";

    std::cout << "--------------------\n";
    return 0;
}
