#include <iostream>
#include "A.hpp"

int main(int arc, char **argv) {
    {
        A* p_a = new A();
        std::cout << "---1---\n" << A::getInstancesCount();
        std::cout << "\n";

        A* p_b = p_a;
        std::cout << "---2---\n" << A::getInstancesCount();
        std::cout << "\n";

        {
            A b;
            std::cout << "---3---\n" << A::getInstancesCount();
            std::cout << "\n";
        
        }

        std::cout << "---4---\n" << A::getInstancesCount();
        std::cout << "\n";

        A b;
        A c(*p_b);
        std::cout << "---5---\n" << A::getInstancesCount();
        std::cout << "\n";
        delete p_a;
    }
    return 0;
}
