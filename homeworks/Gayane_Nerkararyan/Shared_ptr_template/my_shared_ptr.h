#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

//my_shared_ptr is shared pointer class defined by user. 
template <typename T>
class my_shared_ptr
{
private:
	T* m_memory;
	int* m_count;
public:
	//This is default constructor of my_shared_ptr class.
	my_shared_ptr()
	:m_memory(NULL)
	{
		m_count = new int (0);
	}

	//This is constructor of my_shared_ptr class.
	my_shared_ptr(T*memory)
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

	//This is copy constructor of my_shared_ptr class.
	my_shared_ptr(my_shared_ptr& memory)
	:m_memory(memory.m_memory)
	{
		if (memory.m_memory != NULL && memory.m_memory == m_memory)
		{
			m_count = memory.m_count;
			*m_count = *m_count + 1;
		}
	}

	//This is destructor of my_shared_ptr class.
	~my_shared_ptr()
		{
			if (m_count == 0) 
		{
			delete m_memory;
			delete m_count;
		}		
		else 
		{
			*m_count = *m_count - 1;
		}
	}

	//This is member function of my_shared_ptr class,which returns count of the my_shared_ptr class objects.
	int use_count()
	{
		if (m_count != NULL)
		{
			return *m_count;
		}
		else 
		{
			return 0;
		}
	}

	//This is member function of my_shared_ptr class,which returns the value of the m_memory pointer.
	const T get_value()const
	{
		return *m_memory;
	}

	//This is member function of my_shared_ptr class,which sets the value of the m_memory pointer. This function is similar to the dereference operator. 
	void set_value(T value)
	{
		*m_memory = value;
	}

	//Assignment operator of my_shared_ptr class.
	my_shared_ptr& operator=(my_shared_ptr& obj)
	{
		m_memory = obj.m_memory;
		if (obj.m_memory != NULL && obj.m_memory == m_memory)
		{
			*m_count = *m_count + 1;
		}
		return *this;
	}
};

#endif