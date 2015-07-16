#include "my_auto_pointer.h"
#include <iostream>

int main() {
	int g = 5;
	my_auto_pointer a(new int(g));
	my_auto_pointer c(new int(2));
	std::cout << a.get() << std::endl;
	c = a;
	std::cout << c.get() << std::endl;
	return 0;
}