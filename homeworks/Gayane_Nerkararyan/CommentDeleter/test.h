#ifndef MY_CLASS_COUNTER_H
#define MY_CLASS_COUNTER_H

//This class contains a member, which counts a number of the created objects.
class my_class_counter
{
private:
//This is static member of the my_class_counter, which counts a number of the created objects.
	static int m_count;
public:
//This is constructor of the my_class_counter class.
	my_class_counter();

	/*This is copy constructor of the 
	my_class_counter class.*/
	my_class_counter(my_class_counter&);

	/*This is destructor of the my_class_counter class.*/
	~my_class_counter();

	//This is static member function of the my_class_counter, which returns number of the created objects.
	static const int get_count();	
};

#endif