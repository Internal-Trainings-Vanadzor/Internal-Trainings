#include<iostream>
#include "my_class_counter.h"

int main()
{
	//Examples using my_class_counter.
	my_class_counter a;
	std::cout << "Objects count of the class my_class_counter equals " << my_class_counter::get_count() << std::endl;

	my_class_counter b;
	std::cout << "Objects count of the class my_class_counter equals " << my_class_counter::get_count() << std::endl;

	my_class_counter c;
	std::cout << "Objects count of the class my_class_counter equals " << my_class_counter::get_count() << std::endl;

	my_class_counter d(c);
	std::cout << "Objects count of the class my_class_counter equals " << my_class_counter::get_count() << std::endl;

	system("pause");

return 0;
}