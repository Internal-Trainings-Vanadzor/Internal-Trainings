#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray array;
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(0);
    array.remove(5);
    array.insert(7, 48);
    array.set(4, 104);
    for(int i = 0; i < array.size(); ++i){
        std::cout << array.getValue(i) << std::endl;
    }

    return 0;
}
