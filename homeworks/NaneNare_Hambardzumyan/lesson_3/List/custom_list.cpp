#include <iostream>
#include "custom_list.h"

int main()
{
    MyList<int> obj;
    for (int i = 0; i < 5; ++i) {
        obj.push_first(i);
    }
    std::cout << "Size is " << obj.get_size() << std::endl;
    obj.print_right_from(0);
    std::cout << " Removed " << obj.pop_index(2) << " object." << std::endl;
    std::cout << "Size is " << obj.get_size() << std::endl;
    obj.clear();
    std::cout << "Size is " << obj.get_size() << std::endl;
    return 0;
}
