#include <iostream>

class autoPtr {
    private:
	int* ptr;
	
    public:
	 autoPtr (int* n);
	 autoPtr (autoPtr& object);
	 autoPtr& operator=(autoPtr& object);
         int getPtr();
	 ~autoPtr();

};
