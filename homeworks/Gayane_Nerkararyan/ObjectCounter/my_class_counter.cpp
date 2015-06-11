#include"my_class_counter.h"

int my_class_counter::m_count = 0;

my_class_counter::my_class_counter()
{
	m_count++;
}

my_class_counter::my_class_counter(my_class_counter& obj)
{
	m_count++;
}

const int my_class_counter::get_count()
{
	return my_class_counter::m_count;
}

my_class_counter::~my_class_counter()
{
	m_count--;
}


