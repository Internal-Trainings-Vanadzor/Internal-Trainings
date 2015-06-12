#include <iostream>
#include <memory>
#include "my_auto_ptr.h"

int main()
{
	//Examples using std::auto_ptr - automatic pointer class template of the stl library.
	std::auto_ptr <int> my_ptr (new int);
	*my_ptr.get() = 10;
	std::cout << "my_ptr equals " << *my_ptr << std::endl;

	my_ptr.reset(new int);
	*my_ptr = 5;
	std::cout << "my_ptr equals " << *my_ptr << std::endl;

	my_ptr.reset(new int);
	*my_ptr = 1;
	std::cout << "my_ptr equals " << *my_ptr << std::endl;

	std::auto_ptr <int> my_ptr2 (my_ptr);
	std::cout << "my_ptr equals " << *my_ptr2 << std::endl;

	//Examples using my_auto_ptr - automatic pointer class defined by user. 
	int memory;
	int* obj_memory = &memory;
	my_auto_ptr obj(obj_memory);
	obj.set_value(89);
	std::cout << "The value of the obj equals: " << obj.get_value() << std::endl;
	
	my_auto_ptr obj1(obj); //copy constructor
	std::cout << "The value of the obj1 equals: " << obj1.get_value() << std::endl;
	//The value of the obj equals NULL. 

	int* obj_memory2 = new int(58);
	my_auto_ptr obj2(obj_memory2);
	std::cout << "The value of the obj2 equals: " << obj2.get_value() << std::endl;

	int* obj_memory3 = new int(33); //assignment operator
	my_auto_ptr obj3(obj_memory3);
	my_auto_ptr obj4 = obj3;
	std::cout << "The value of the obj4 equals: " << obj4.get_value() << std::endl;
	//The value of the obj3 equals NULL. 

	system("pause");

return 0;
}