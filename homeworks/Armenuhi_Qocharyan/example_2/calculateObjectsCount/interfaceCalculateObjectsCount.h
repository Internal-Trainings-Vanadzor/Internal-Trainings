#include <iostream>

class CalculateObjectsCount { 
	// The count of objects
	private: static int ObjectsCount;
	
	public: CalculateObjectsCount();
	
	public: CalculateObjectsCount(CalculateObjectsCount& object);
	
	//returns object's count
	public: static int getCount();
	
	public: ~CalculateObjectsCount();
	
};

