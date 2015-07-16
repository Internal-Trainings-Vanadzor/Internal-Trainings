#include "ObjectCounter.h"
#include <iostream>

int main()
{
	ObjectCounter a;
	ObjectCounter b;
	std::cout << ObjectCounter::s_object_counter << std::endl;
	std::cin;

	return 0;
}
