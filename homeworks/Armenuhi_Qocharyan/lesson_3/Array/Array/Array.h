#ifndef DynamicArray
#define DynamicArray

#include "Node.h"

class Array {
 
    public:
	Array();
	Array(int initSize);
	Array(const Array &original);
	~Array();
 
	void insert(int position, int value);
	int get(int position);
	void printArray(); 
	int getSize();
	void resize(int newSize);
	bool operator==(Array);
	struct Node *head = new Node;
    private:
	int maxSize;
	int maxIndex;
 
}; 

#endif
