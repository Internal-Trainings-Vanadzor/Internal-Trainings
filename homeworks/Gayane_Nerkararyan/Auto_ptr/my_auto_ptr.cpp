#include<iostream>
#include "my_auto_ptr.h"

my_auto_ptr::my_auto_ptr(int* memory)
:m_memory(memory)
{}

my_auto_ptr::my_auto_ptr(my_auto_ptr& memory)
:m_memory(memory.m_memory)
{
	memory.m_memory = NULL;
}

const int my_auto_ptr::get_value()const
{
	return *m_memory;
}

void my_auto_ptr::set_value(int value)
{
	*m_memory = value;
}

my_auto_ptr& my_auto_ptr::operator=(my_auto_ptr& obj)
{
	m_memory = obj.m_memory;
	obj.m_memory = NULL;
}

my_auto_ptr::~my_auto_ptr()
{
	delete m_memory;
}

