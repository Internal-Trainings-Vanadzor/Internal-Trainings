#include<iostream>
#include "my_shared_ptr.h"

int my_shared_ptr::m_count = 0;
my_shared_ptr::my_shared_ptr()
:m_memory(NULL)
{}

my_shared_ptr::my_shared_ptr(int* memory)
:m_memory(memory)
{
	if (memory != NULL)
	{
		++m_count;
	}
}

my_shared_ptr::my_shared_ptr(my_shared_ptr& memory)
:m_memory(memory.m_memory)
{
	if (memory.m_memory != NULL)
	{
		++m_count;
	}
}

const int my_shared_ptr::get_value()const
{
	return *m_memory;
}

int my_shared_ptr::use_count()
{
	return m_count;
}

void my_shared_ptr::set_value(int value)
{
	*m_memory = value;
}

my_shared_ptr& my_shared_ptr::operator=(my_shared_ptr& obj)
{
	m_memory = obj.m_memory;
	if (obj.m_memory != NULL)
	{
		++m_count;
	}
	return *this;
}

my_shared_ptr::~my_shared_ptr()
{
	if (m_count == 0) 
	{
		delete m_memory;
	}
	else 
		--m_count; 
}

