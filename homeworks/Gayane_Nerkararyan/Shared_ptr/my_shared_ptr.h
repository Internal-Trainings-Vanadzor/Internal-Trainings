#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

//my_shared_ptr is shared pointer class defined by user. 
class my_shared_ptr
{
private:
	int* m_memory;
	static int m_count;
public:
	//This is default constructor of my_shared_ptr class.
	my_shared_ptr();

	//This is constructor of my_shared_ptr class.
	my_shared_ptr(int*);

	//This is copy constructor of my_shared_ptr class.
	my_shared_ptr(my_shared_ptr&);

	//This is destructor of my_shared_ptr class.
	~my_shared_ptr();

	//This is member function of my_shared_ptr class,which returns count of the my_shared_ptr class objects.
	static int use_count();

	//This is member function of my_shared_ptr class,which returns the value of the m_memory pointer.
	const int get_value()const;

	//This is member function of my_shared_ptr class,which sets the value of the m_memory pointer. This function is similar to the dereference operator. 
	void set_value(int);

	//Assignment operator of my_shared_ptr class.
	my_shared_ptr& operator=(my_shared_ptr&); 
};

#endif