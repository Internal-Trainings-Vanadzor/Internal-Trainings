#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> vector1;
    Vector<int> vector2(5);
	std::cout << "Size of vector1 " << vector1.get_size() << std::endl;
	std::cout << "Size of vector2 " << vector2.get_size() << std::endl;
    for (int i = 0; i < 15; ++i) {
        vector1.push(i);
    }
    std::cout << "Size of vector1 " << vector1.get_size() << std::endl;
    std::cout << "Size of vector2 " << vector2.get_size() << std::endl;
    vector2 = vector1;
    for (int i = 0; i < 15; ++i) {
        vector2.push_index(i,-1*i);
    }
    std::cout << "Size of vector1 " << vector1.get_size() << std::endl;
    std::cout << "Size of vector2 " << vector2.get_size() << std::endl;
    std::cout << "Actual size of vector1 " << vector1.get_accptable_size() << std::endl;
    std::cout << "Actual size of vector2 " << vector2.get_accptable_size() << std::endl;
    vector1.print();
    vector2.print();
    vector1.clear();
    vector2.clear();
    for (int i = 0; i < 50; ++i) {
        vector2.pop();
        vector1.pop_index(i);
    }
    std::cout << "Size of vector1 " << vector1.get_size() << std::endl;
    std::cout << "Size of vector2 " << vector2.get_size() << std::endl;
    Vector<double> vector3(6);
    Vector<double> vector4(7);
    if (vector4 != vector3) {
        std::cout <<" Not EQUAL "<< std::endl;
    }
    return 0;
}
