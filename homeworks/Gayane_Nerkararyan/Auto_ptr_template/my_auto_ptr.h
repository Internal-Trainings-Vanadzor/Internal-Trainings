#ifndef MY_AUTO_PTR
#define MY_AUTO_PTR

//my_auto_ptr is automatic pointer class defined by user. 
template < typename T>
class my_auto_ptr
{
private:
	T* m_memory;
public:
	//This is constructor of the my_auto_ptr class.
	my_auto_ptr(T* memory)
	:m_memory(memory)
	{}

	//This is copy constructor of the my_auto_ptr class.
	my_auto_ptr(my_auto_ptr& memory)
	:m_memory(memory.m_memory)
	{
		memory.m_memory = NULL;
	}

	//This is destructor of the my_auto_ptr class.
	~my_auto_ptr()
	{
		delete m_memory;
	}

	//This is member function of the my_auto_ptr class,which returns the value of the m_memory pointer.
	const T get_value()const
	{
		return *m_memory;
	}

	//This is member function of the my_auto_ptr class,which sets the value of the m_memory pointer. This function is similar to the dereference operator. 
	void set_value(T value)
	{
		*m_memory = value;
	}

	//Assignment operator of the my_auto_ptr class.
	my_auto_ptr& operator=(my_auto_ptr& obj)
	{
		m_memory = obj.m_memory;
		obj.m_memory = NULL;
	}
};

#endif