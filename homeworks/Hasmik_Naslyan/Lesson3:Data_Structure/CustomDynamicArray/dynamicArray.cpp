#include "dynamicArray.hpp"
#include <iostream>
using namespace std;

dynamicArray::dynamicArray()
{
    myArray = new int[1];
    for (int i = 0; i < 1; i++)
        myArray[i] = 0;
    size = 1;
    length = 0; 
}

dynamicArray::~dynamicArray(){
    delete [] myArray;
}

void dynamicArray::add (int el) {
    int *tmp;  
    if (length == size) {
        size = size*2;
        tmp = new int[size];
        for (int i = 0; i < length; i++)
            tmp[i] = myArray[i];
        for (int j = length; j < size; j++)
            tmp[j] = 0;
        delete [] myArray;
        myArray = tmp;
    }
    myArray[length++] = el;   
}

void dynamicArray::remove () {
    int *tmp; tmp = new int[length]; 
    if (isEmpty()){
        cout<<"Array is already empty";
    } else {
        length--;
        for (int i = 0; i < length; i++)
            tmp[i] = myArray[i];
        delete [] myArray;
        myArray = tmp;
    }
}

int dynamicArray::getSize () {
    return length;   
}
bool dynamicArray::isEmpty () {
    if (length==0) return true;
    else return false;
}

void dynamicArray::insert (int pos, int el) {
    int *tmp;  tmp = new int[length+1]; 
    for (int i = 0; i < pos; i++)
        tmp[i] = myArray[i];
    tmp[pos] = el; length;
    for (int i = pos; i < length; i++)
        tmp[i+1] = myArray[i];
    delete [] myArray;length++;
    myArray = tmp;
}

int& dynamicArray::operator[](int index) {
    int *tmp;
    if (index >= size) { 
        tmp = new int[index*2]; for (int i = 0; i < length; i++) 
            tmp[i] = myArray[i];
        for (int j = length; j < index*2; j++) 
            tmp[j] = 0;
        size = index *2; 
        delete [] myArray;
        myArray = tmp;
    }
    if (index >= length)
        length = index + 1;
    return *(myArray + index);
} 
