#include "Array.h"

Array::Array() {
    this->maxSize = 8;
    this->maxIndex = 0;
    head->size = 8;
    head->array = new int[head->size];
    for (int i = 0; i < head->size; i++) {
        head->array[i] = 0;
    }
}
 
Array::Array(int initSize) {
    head->size = initSize;
    this->maxSize = initSize;
    head->array = new int[head->size];
    for (int i = 0; i < head->size; i++) {
        head->array[i] = 0;
    }
}

Array::Array(const Array &original) {
    this->maxSize = original.maxSize;
    this->maxIndex =  original.maxIndex;
    head->size = original.head->size;
    head->array = new int[head->size];
    for (int i = 0; i < head->size; i++) {
        head->array[i] = original.head->array[i];
    }
} 
 
Array::~Array() {
    delete[] head;
}

 
void Array::insert(int position, int value) {
    if (position > this->maxIndex){
	this->maxIndex = position;
	
    }
    if (this->maxIndex < this->maxSize) {
        head->array[position] = value;
     } else {
	Array::resize(2 * this->maxIndex);
	this->maxSize = 2 * this->maxIndex;
        head->array[position] = value;
     }
}

int Array::get(int position){
    if (position <= this->maxIndex) {
	return head->array[position];
    } else {
	std::cout << "Incorrect position ... " << "\n";
	return 0;
    }

}
 
int Array::getSize(){
     return this->maxIndex;
}

void Array::resize(int newSize){
    Node *temp = new Node;
    temp->size = newSize;
    temp->array = new int[newSize];
    for (int i = 0; i < (newSize); i++) {
	temp->array[i] = 0;
    }
    for (int i = 0; i < (head->size); i++) {
	temp->array[i] = head->array[i];
	//std::cout << head->array[i] << "  ";
    }
    
    delete[] head;
    head->array = temp->array;
    head->size = temp->size; 
}
	
bool Array::operator==(Array a){
    if (a.head->size != head->size) {
	return false;
    }
    for (int i = 0; i < (a.head->size); i++) {
        if (a.head->array[i] != head->array[i]) {
    	    return false;
    	}	
    return true; 
    }
}

void Array::printArray(){
    for (int i = 0; i <= this->maxIndex; i++) {
      std::cout << head->array[i] << "  ";
    }
    std::cout << "\n";
}	

