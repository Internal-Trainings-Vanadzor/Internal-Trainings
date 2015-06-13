#include <iostream>
#include <memory>
#include "my_shared_ptr.h"

int main()
{
	//Examples using my_shared_ptr - shared pointer class defined by user. 
	int memory;
	int* obj_memory = &memory;
	my_shared_ptr obj(obj_memory);
	obj.set_value(89);
	std::cout << "The value of the obj equals: " << obj.get_value() << std::endl;
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;
	
	my_shared_ptr obj1(obj); //copy constructor
	std::cout << "The value of the obj1 equals: " << obj1.get_value() << std::endl;
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;
	
	int* obj_memory2 = new int(58);
	my_shared_ptr obj2(obj_memory2);
	std::cout << "The value of the obj2 equals: " << obj2.get_value() << std::endl;
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;

	int* obj_memory3 = new int(33);
	my_shared_ptr obj3(obj_memory3);
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;
	
	my_shared_ptr obj4 = obj3;//assignment operator
	std::cout << "The value of the obj4 equals: " << obj4.get_value() << std::endl;	
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;

	my_shared_ptr obj5;
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;

	my_shared_ptr obj6(NULL);
	std::cout << "The count of the my_shared_ptr class objects equals: " << my_shared_ptr::use_count() << std::endl;

	system("pause");

return 0;
}