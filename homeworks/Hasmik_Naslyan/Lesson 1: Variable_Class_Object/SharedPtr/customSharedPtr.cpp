#include <iostream>
template < class T >
class customSharedPtr {

    private:
	int* counter;
        T* ptr;

    public:
	customSharedPtr (T* p) {
		counter = new int(1);
    		ptr = p;
	}

	customSharedPtr (customSharedPtr<T>& obj) {
    		ptr = obj.ptr;
		counter = obj.counter;
    		*counter = *counter + 1;
	}

	customSharedPtr& operator=(customSharedPtr<T>& obj) {
		if (&obj!=this){
    			ptr = obj.ptr;	
			*counter = *counter - 1;	
		}                
		return *this;
	}

	~customSharedPtr () {
		*counter = *counter - 1;
		if (*counter==0){
    			delete ptr;
			delete counter;
		}
	}

	int getPointersCount(){
		return *counter;
	}

	void printPtr() {
		if (ptr) {
        		std::cout << ptr << std::endl;
    		} else {
        		std::cout << "NULL" << std::endl;
    		}
	}
};
