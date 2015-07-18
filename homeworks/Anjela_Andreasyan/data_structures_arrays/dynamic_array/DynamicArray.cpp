#include <iostream>
#include <cstdlib>
#include "DynamicArray.hpp"

using std::cout;

DynamicArray::DynamicArray(){
    size = 5;
    arr = new int[size];
    currentSize=0;
}

DynamicArray::DynamicArray(unsigned int length){
    size = length;
    arr = new int[size];
    currentSize=0;
}


DynamicArray::~DynamicArray(){
    delete[] arr;
}

unsigned int DynamicArray::getSize(){
    return currentSize;
}
void DynamicArray::set(unsigned int index, int el){
    if (index < size){
        arr[index] = el;
    }else{
        cout<<"There is no "<<index<<" index in the arr. Please use insert method if you want to add an element in the given index\n";
    }
}

void DynamicArray::append(int el){
    reserve();
    arr[currentSize-1] = el;
}


void DynamicArray::insert(unsigned int index, int el){
    reserve();
    if (index < currentSize){
        for (int i = index; i < currentSize; i++){
            int temp = arr[i];
            arr[i] = el;
            el = temp;
        }
    }
}

void DynamicArray::removeLastEl(){
    --currentSize;
}
void DynamicArray::remove(unsigned int index){
    --currentSize;
    for(int i=index; i<currentSize; i++){
        arr[i] = arr[i+1];
    }
}

void DynamicArray::removeRange(unsigned int beginIndex,unsigned int endIndex){
    int diff =  endIndex - beginIndex + 1;
    currentSize -= diff;
    for (int i = beginIndex; i < currentSize; i++){
        arr[i] = arr[i + diff];
    }
}

int &DynamicArray::operator[](unsigned int index) {
    if (index < currentSize) {
        return arr[index]; 
    }else{
        cout<<"The given index is out of range\n";
        exit(1);
    }
} 

/**
 * Ensure that the allocated size of the array is satisfactory and realocate the memory if required
 * 
 * */
void DynamicArray::reserve(){
    if (++currentSize > size ){
        cout<< "Re-alocating the memory...\n";
        size *= 2;
        int* temp = new int[size];
        for (int i=0; i < currentSize; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
}

void DynamicArray::printArray(){
    for (int i=0; i< currentSize; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
