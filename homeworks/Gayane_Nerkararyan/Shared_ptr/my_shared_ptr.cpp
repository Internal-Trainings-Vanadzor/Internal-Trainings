#include<iostream>
#include "my_shared_ptr.h"

my_shared_ptr::my_shared_ptr()
:m_memory(NULL)
{
	m_count = new int (0);
}

my_shared_ptr::my_shared_ptr(int* memory)
:m_memory(memory)
{
	if (memory != NULL)
	{
		m_count = new int (1);
	}
	else 
	{
		m_count = new int (0);
	}
}

my_shared_ptr::my_shared_ptr(my_shared_ptr& memory)
:m_memory(memory.m_memory)
{
	if (memory.m_memory != NULL && memory.m_memory == m_memory)
	{
		m_count = memory.m_count;
		*m_count = *m_count + 1;
	}
}

const int my_shared_ptr::get_value()const
{
	return *m_memory;
}

int my_shared_ptr::use_count()
{
	if (*m_count != NULL)
	{
		return *m_count;
	}
	else
	{
		return 0;
	}
}

void my_shared_ptr::set_value(int value)
{
	*m_memory = value;
}

my_shared_ptr& my_shared_ptr::operator=(my_shared_ptr& obj)
{
	m_memory = obj.m_memory;
	if (obj.m_memory != NULL && obj.m_memory == m_memory)
	{
		*m_count = *m_count + 1;
	}
	return *this;
}

my_shared_ptr::~my_shared_ptr()
{
	if(m_memory != NULL)
	{
		*m_count = *m_count - 1;
		if (*m_count == 0) 
		{
			delete m_memory;
			delete m_count;
		}		
	}
}

