#include "DynamicArray.h"
#include <iostream>
#include <assert.h>
DynamicArray::DynamicArray():
    m_size(2),
    m_buffer_size(0),
    m_buffer(0)
{
    m_buffer = new int[m_size];
}

DynamicArray::~DynamicArray(){
    delete [] m_buffer;
}

void DynamicArray::resize(){ 
    m_size *= 2;
    int* tmp = new int[m_size];
    for(int i = 0; i < m_buffer_size; ++i){
        tmp[i] = m_buffer[i];
    }
    delete [] m_buffer;
    m_buffer = tmp;
    tmp = 0;
}
void DynamicArray::push_back(int value){
    if(m_buffer_size == m_size){
        resize();
    }
    m_buffer[m_buffer_size++] = value;
}

unsigned int DynamicArray::size(){
    return m_buffer_size;
}

bool DynamicArray::isEmpty(){
    return (m_buffer_size == 0);
}
void DynamicArray::pop_back(){
    if (isEmpty()){
        return;
    }
    --m_buffer_size;
}
void DynamicArray::remove(unsigned int index){
    if (isEmpty()){
        return;
    }
    while( index < (m_buffer_size - 1) ){
        m_buffer[index] = m_buffer[++index];
    }
    --m_buffer_size;
}
    
void DynamicArray::insert (unsigned int index, int value){
    assert (index <= m_buffer_size);
    if(m_buffer_size == m_size){
        resize();
    }
    int i = m_buffer_size;
    while(i > index){
        m_buffer[i] = m_buffer[--i];
    }
    m_buffer[index] = value;
    ++m_buffer_size;
}
void DynamicArray::clear(){
    delete [] m_buffer;
    m_buffer_size = 0;
}

void DynamicArray::set(unsigned int index, int value){
    assert(index < m_buffer_size);
    m_buffer[index] = value;
}

int DynamicArray::getValue(unsigned int index){
    return m_buffer[index];
}


