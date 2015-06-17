#include "my_auto_pointer.h"
#include <iostream>

my_auto_pointer::my_auto_pointer(int* ptr) : pointer(ptr)
{
}

/*my_auto_pointer::my_auto_pointer(my_auto_pointer& object) {
	pointer = object.pointer;
	object.pointer = NULL;
}*/
my_auto_pointer& my_auto_pointer::operator=(my_auto_pointer& ptr)
{
	pointer = ptr.pointer;
	ptr.pointer = NULL;
	return *this;
}
my_auto_pointer::~my_auto_pointer()
{
	if (pointer) {
		delete pointer;
	}
}

const int my_auto_pointer::get()const
{
	if (pointer) {
		return *pointer;
	}
}

void my_auto_pointer::reset(int value)
{
	if (pointer) {
		*pointer = value;
	}
}