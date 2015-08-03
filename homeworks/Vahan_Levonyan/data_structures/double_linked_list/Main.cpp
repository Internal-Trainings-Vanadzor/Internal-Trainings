#include "DoubleLinkedList.h"
#include <iostream>

int main()
{
    DoubleLinkedList list;
    list.push_back(18);
    list.push_back(20);
    list.push_back(36);

    list.insertAfter(2, 55);
    list.remove(2);
    list.print();
    //  std::cout << list.getHead()->data << std::endl;
    //  std::cout << list.getTail()->data << std::endl;
    //  std::cout << "******************************" << std::endl;
    list.push_front(154);
    list.print();
    return 0;
}
