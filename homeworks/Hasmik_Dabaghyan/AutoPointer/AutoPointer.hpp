#ifndef AUTO_POINTER_HPP
#define AUTO_POINTER_HPP

//This class can be used for creating auto_ptr pointers.
class AutoPointer
{
private:
	int* m_pointer;
public:
	AutoPointer(int* p);
    AutoPointer(AutoPointer& obj);
	~AutoPointer();
	int* operator->();
	int& operator*();
	AutoPointer& operator = (AutoPointer& sp);
    // releases current pointer and creates a new one
    int* release();
    //returns current object pointer
    int* getPointer();
};
#endif

