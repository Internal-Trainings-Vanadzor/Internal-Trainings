#include <iostream>
template < class T >
class customAutoPtr {

    private:
             T* ptr;

    public:
	customAutoPtr (T* p) {
    		ptr = p;
	}

	customAutoPtr (customAutoPtr<T>& obj) {
    		ptr = obj.ptr;
    		obj.ptr = NULL;
	}

	customAutoPtr& operator=(customAutoPtr<T>& obj) {
		if (&obj!=this){
    			ptr = obj.ptr;
			obj.ptr = NULL;
		}
		return *this;

	}

	~customAutoPtr () {
		if (ptr){
    			delete ptr;
		}
	}

	void printPtr() {
		if (ptr) {
        		std::cout << ptr << std::endl;
    		} else {
        		std::cout << "NULL" << std::endl;
    		}
	}
};
