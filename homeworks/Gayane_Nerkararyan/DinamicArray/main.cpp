#include<iostream>
#include"DinamicArray.h"

int main()
{
	std::cout << ">>>>>>>>>> This is DinamicArray proramm <<<<<<<<<<" << std::endl;
	DinamicArray my_array;
	std::cout << "getSize" << my_array.getSize() << std::endl;
	my_array.removeFromBack();
	my_array.putBack(0);
	std::cout << my_array.getElemetById(0) << std::endl;
	my_array.putBack(1);
	std::cout << my_array.getElemetById(1) << std::endl;
	my_array.putBack(2);
	std::cout << my_array.getElemetById(2) << std::endl;
	my_array.putBack(3);
	std::cout << my_array.getElemetById(3) << std::endl;
	my_array.putBack(4);
	std::cout << my_array.getElemetById(4) << std::endl;
	my_array.putBack(5);
	std::cout << my_array.getElemetById(5) << std::endl;
	my_array.putBack(6);
	std::cout << my_array.getElemetById(6) << std::endl;
	my_array.putBack(7);
	std::cout << my_array.getElemetById(7) << std::endl;
	std::cout << "getSize" << my_array.getSize() << std::endl;
	my_array.replaceElement(7,77);
	std::cout << my_array.getElemetById(7) << std::endl;
	my_array.removeFromBack();
	std::cout << my_array.getElemetById(7) << std::endl;
	std::cout << "getSize" << my_array.getSize() << std::endl;
	std::cout << my_array.getElemetById(my_array.getSize()) << std::endl;

	system("pause");
	return 0;
}