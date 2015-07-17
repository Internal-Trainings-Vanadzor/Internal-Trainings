#include<iostream>
#include"DinamicArray.h"

DinamicArray::DinamicArray()
{
	m_size = 0;
	m_max_size = 5;
	m_buffer = new int[m_max_size];
}
DinamicArray::~DinamicArray()
{
	delete [] m_buffer;
}
int DinamicArray::getSize()const
{
	return m_size;	
}
void DinamicArray::putBack(int element)
{
	if (getSize() == m_max_size)
	{
		resizeBuffer();
	}
	m_buffer[getSize()] = element;
	++m_size;
}
void DinamicArray::removeFromBack()
{
	if (getSize() == 0)
	{
		std::cerr << "Your buffer is empty" << std::endl;
	} else {
		m_buffer[m_size - 1] = 0;
		--m_size;
	}
}
int DinamicArray::getElemetById(unsigned int id)
{
	return m_buffer[id];
}
void DinamicArray::replaceElement(unsigned int id,int element)
{

	m_buffer[id] = element;	
}
void DinamicArray::resizeBuffer()
{
	m_max_size = m_max_size * 2;
	int* newBuffer = new int[m_max_size];
	for (unsigned int i = 0; i < m_max_size; i++)
	{
		newBuffer[i] = m_buffer[i];
	}
	delete [] m_buffer;
	m_buffer = newBuffer;
}