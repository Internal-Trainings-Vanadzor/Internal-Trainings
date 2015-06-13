#include <iostream>

class Counter{

	public:
		static int count;
		int number;
		
        Counter(){
			count++;
		}

		~Counter(){
			count--;
		}

		Counter(Counter &num_copy){
			number = num_copy.number;
            std::cout << "Copied number = " << number << std::endl;
		}

};

int Counter::count = 0;

int main(){

	Counter* objects = new Counter[50];
    std::cout << "Count in constructor = " << Counter::count << std::endl;
	Counter object_for_copy;
	Counter num_copy = object_for_copy;
    delete[] objects;
    std::cout << "Count in destructor = " << Counter::count << std::endl;
    return 0;

};
