#include <iostream>

#include "shared_ptr.hpp"

int main(int arc, char **argv) 
{
    int* a = new int(7);
    int* b = new int(5);
    int* c = new int(11);

    SharedPtr<int> shp_a(a);
    SharedPtr<int> shp_b(b);
    SharedPtr<int> shp_c(c);

    SharedPtr<int> shp_d(shp_b);
    SharedPtr<int> shp_e = shp_a;
    
    std::cout << "a pointers count is: " << shp_a.getPointersCount() << "\n";
    std::cout << "a val is: " << shp_a.getObject() << "\n";
    std::cout << "b pointers count is: " << shp_b.getPointersCount() << "\n";
    std::cout << "b val is: " << shp_b.getObject() << "\n";
    std::cout << "c pointers count is: " << shp_c.getPointersCount() << "\n";
    std::cout << "c val is: " << shp_c.getObject() << "\n";
    std::cout << "d pointers count is: " << shp_d.getPointersCount() << "\n";
    std::cout << "d val is: " << shp_d.getObject() << "\n";
    std::cout << "e pointers count is: " << shp_e.getPointersCount() << "\n";
    std::cout << "e val is: " << shp_e.getObject() << "\n";

    shp_c = shp_a;
    shp_d = shp_a;
    shp_e = shp_a;

    std::cout << "--------------------\n";
    std::cout << "a pointers count is: " << shp_a.getPointersCount() << "\n";
    std::cout << "a val is: " << shp_a.getObject() << "\n";
    std::cout << "b pointers count is: " << shp_b.getPointersCount() << "\n";
    std::cout << "b val is: " << shp_b.getObject() << "\n";
    std::cout << "c pointers count is: " << shp_c.getPointersCount() << "\n";
    std::cout << "c val is: " << shp_c.getObject() << "\n";
    std::cout << "d pointers count is: " << shp_d.getPointersCount() << "\n";
    std::cout << "d val is: " << shp_d.getObject() << "\n";
    std::cout << "e pointers count is: " << shp_e.getPointersCount() << "\n";
    std::cout << "e val is: " << shp_e.getObject() << "\n";

    return 0;
}
