#ifndef MY_AUTO_PTR
#define MY_AUTO_PTR

//my_auto_ptr is automatic pointer class defined by user. 
class my_auto_ptr
{
private:
	int* m_memory;
public:
	//This is default constructor of the my_auto_ptr class.
	my_auto_ptr();

	//This is constructor of the my_auto_ptr class.
	my_auto_ptr(int*);

	//This is copy constructor of the my_auto_ptr class.
	my_auto_ptr(my_auto_ptr&);

	//This is destructor of the my_auto_ptr class.
	~my_auto_ptr();

	//This is member function of the my_auto_ptr class,which returns the value of the m_memory pointer.
	const int get_value()const;

	//This is member function of the my_auto_ptr class,which sets the value of the m_memory pointer. This function is similar to the dereference operator. 
	void set_value(int);

	//Assignment operator of the my_auto_ptr class.
	my_auto_ptr& operator=(my_auto_ptr&); 
};

#endif