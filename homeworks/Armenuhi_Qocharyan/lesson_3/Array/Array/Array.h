#ifndef DynamicArray
#define DynamicArray

#include "Node.h"

class Array {
 
    public:
	/**
	* The Constructor
	*/
	Array();
	
	/**
	* The Constructor with array size 
	*/
	Array(int initSize);

	/**
	* The copy Constructor  
	*/
	Array(const Array &original);
	
	/**
	* The Destructor	
	*/
	~Array();

	/**
	* Insert element by position
	*/ 
	void insert(int position, int value);
	
	/**
	* Get element by position
	*/
	int get(int position);

	/**
	* Print array
	*/
	void printArray(); 

	/**
	* Get size of array
	*/
	int getSize();
	
	/**
	* Checks equality of two arrays
	*/
	bool operator==(Array);

	/**
	* Structure of array
	*/
	struct Node *head = new Node;
    private:
	/**
	* Max Size
	*/
	int maxSize;
	
	/**
	* Max index	
	*/
	int maxIndex;
 
	/**
	* Change size of array 
	*/	
	void resize(int newSize);
	
}; 

#endif
