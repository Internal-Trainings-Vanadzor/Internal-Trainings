#ifndef DINAMIC_ARRAY
#define DINAMIC_ARRAY
template <typename T> 
class DinamicArray
{
	T* m_buffer;
	unsigned int m_size;
	unsigned int m_max_size;
public:
	DinamicArray<T>::DinamicArray()
	{
		m_size = 0;
		m_max_size = 5;
		m_buffer = new T[m_max_size];
	}
	DinamicArray<T>::~DinamicArray()
	{
		delete [] m_buffer;
	}
	int DinamicArray<T>::getSize()const
	{
		return m_size;	
	}
	void DinamicArray<T>::putBack(T element)
	{
		if (getSize() == m_max_size)
		{
			resizeBuffer();
		}
		m_buffer[getSize()] = element;
		++m_size;
	}
	void DinamicArray<T>::removeFromBack()
	{
		if (getSize() == 0)
		{
			std::cerr << "Your buffer is empty" << std::endl;
		} else {
			m_buffer[m_size - 1] = 0;
			--m_size;
		}
	}
	T DinamicArray<T>::getElemetById(unsigned int id)
	{
		return m_buffer[id];
	}
	void DinamicArray<T>::replaceElement(unsigned int id,T element)
	{
		m_buffer[id] = element;	
	}
	void DinamicArray<T>::resizeBuffer()
	{
		m_max_size = m_max_size * 2;
		T* newBuffer = new T[m_max_size];
		for (unsigned int i = 0; i < m_max_size; i++)
		{
			newBuffer[i] = m_buffer[i];
		}
		delete [] m_buffer;
		m_buffer = newBuffer;
	}
};

#endif