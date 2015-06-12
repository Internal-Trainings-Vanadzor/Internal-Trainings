#ifndef SHARED_POINTER
#define SHARED_POINTER
template <typename T> class SharedPointer
{
private:
	T* pointer;
public:
	static int count;
	SharedPointer(){
		pointer = 0;
		count++;
	}
    //Shared pointer constructor
	SharedPointer(T* p){
		pointer = p;
		count++;
	}
    //Shared pointer destructor
	~SharedPointer()
	{
		if(count == 1){
			delete pointer;
			std::cout<<"SharedPointer destructor is invoked....\n";
        }
            count = count - 1;
	}

	T* operator->()
	{
		return pointer;
	}

	T& operator*()
	{
		return *pointer;
	}
    //override assignment operator
	SharedPointer<T>& operator = (const SharedPointer<T>& sp)
    	{
        if (this != &sp) // Avoid self assignment
        {
            if(count == 1){
                delete pointer;
            } 
            count = count - 1;
            pointer = sp.pointer;
	        count++;
        }
        return *this;
    }
};
#endif
