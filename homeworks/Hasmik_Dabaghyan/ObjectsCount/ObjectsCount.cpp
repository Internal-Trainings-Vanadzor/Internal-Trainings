#include <iostream>

//ObjectsCounter class returns the number of created objects
class ObjectsCounter {
  public:
	static int counter;
	ObjectsCounter() {
		counter++;
	}
	ObjectsCounter(ObjectsCounter &obj) {
		counter++;
	}
	~ObjectsCounter(){
		counter--;
	}
};
//Initialaize the static member
int ObjectsCounter::counter = 0;

int main(){
	ObjectsCounter object_1;
	std::cout<<"Objects count is: "<< ObjectsCounter::counter <<std::endl; 
	ObjectsCounter object_2;
	std::cout<<"Objects count is: "<< ObjectsCounter::counter <<std::endl; 
	ObjectsCounter object_3 = object_2;
	std::cout<<"Objects count is: "<< ObjectsCounter::counter <<std::endl; 
	return 0;
}
