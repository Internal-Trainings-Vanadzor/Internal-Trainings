#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

/**
 *@class - This is custom vector
 */

template <typename T>
class Vector {
    private:
        /**
         * @brief - the m_size is size of vector
         */
        unsigned int m_size;	
        /**
         * @brief - the m_index is index of vector
         */
        unsigned int m_index;	
        /**
         *@brief - the m_array is container for a vector
         */
        T* m_array;
    private: 
        /**
         *@brief this Increase vector size if necessary
         */
        void increase_vector();
    public:
        /**
         *@brief this Constructor for given size  
         */
        Vector(unsigned int m_size);
        /**
         *@brief this Constructor is a copy constructor  
         */
        Vector(const Vector<T>& arg);
        /*
         *@brief Destructor
         */
        ~Vector();
        /**
         *@brief the operator assignment 
         */
        Vector<T>& operator= (Vector<T>& arg );
        /*
         *@brief the operator returning obj
         */ 
        T& operator[] ( const unsigned int& arg );
        /*
         *@brief get index of Vector
         */ 
        unsigned int get_size();
        /*
         *@brief get size on Vector
         */ 
        unsigned int get_accptable_size();
        /*
         *@brief the operator checking  equality
         */ 
        bool operator== ( Vector<T>& arg);
        /*
         *@brief the operator checking non equality
         */ 
        bool operator!= ( Vector<T>& arg);
        /*
         *@brief the operator- 
         */ 
        friend Vector<T>& operator- (Vector<T>& arg1, Vector<T>& arg2);
        /*
         *@brief the operator+
         */ 
        friend Vector<T>& operator+ (Vector<T>& arg1, Vector<T>& arg2);
        /*
         *@brief update object by index
         */ 
        void update_obj_by_index(unsigned int index, const T& obj);
        /*
         *@brief add object from the end
         */ 
        void push(const T&);
        /*
         *@brief add object from the index
         */ 
        void push_index(unsigned int index, const T& obj);
            /*
             *@brief remove object from the end
             */ 
            T pop();
        /*
         *@brief remove object from the index
         */ 
        T pop_index(unsigned int index);
        /*
         *@brief clear the Vector
         */ 
        void clear();
        /*
         *@brief print all members of Vector
         */ 
        void print();
};
////////////////////////////////////////////////////////////
template <typename T>
Vector<T>::Vector(unsigned int arg = 10)
{
	m_size = arg;
    m_index = 0;
	m_array = new T[m_size];
}

///////////////////////////////////////////////
template <typename T>
Vector<T>::Vector(const Vector<T>& arg)
{
	m_size = arg.m_size;	
    m_index = arg.m_index;
	m_array = new T[m_size];	
	for (int i = 0; i < m_size; ++i) {
		m_array[i] = arg.m_array[i];
	}
} 
///////////////////////////////////////////////
template <typename T>
Vector<T>::~Vector()
{
    m_size = 0;
    m_index = 0;
    delete[] m_array;
}
///////////////////////////////////////////////
template <typename T>
T& Vector<T>::operator[] (const unsigned int& index )
{
    if (m_size < index) {
       return m_array[m_index]; 
    }
	return m_array[index];
}
///////////////////////////////////////////////
template <typename T>
unsigned int Vector<T>::get_size()
{
	return m_index;
}
///////////////////////////////////////////////
template <typename T>
unsigned int Vector<T>::get_accptable_size()
{
	return m_size;
}
///////////////////////////////////////////////
template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T>& arg)
{
    if (m_size != arg.get_accptable_size()) {
        std::cout << "The sizes of vectors do not equal." << std::endl;
    } else {
        for(int i = 0; i < m_index; ++i) {
            m_array[i] = arg[i];
        }
    }
    return *this;
}	
///////////////////////////////////////////////
template <typename T>
bool Vector<T>::operator==(Vector<T>& arg)
{
    if (m_size != arg.get_accptable_size()) {
		std::cout << "The sizes of comparing vectors do not equal." << std::endl;
		return false;
	} else {
        for(int i = 0; i < m_index; ++i) {
            if ( m_array[i] != arg[i]) {
                return false ;
            }
        }
    }
	return true;
}
///////////////////////////////////////////////
template <typename T>
bool Vector<T>::operator!= (Vector<T>& arg)
{
    if (m_size != arg.get_accptable_size()) {
		std::cout << "The sizes of comparing vectors do not equal." << std::endl;
    } else {
        for(int i = 0; i < m_index; ++i) {
            if ( m_array[i] != arg[i]) {
                return true ;
            }
        }
    }
    return false;
}
//////////////////////////////////////////////////
template <typename T>
Vector<T>& operator- (Vector<T>& arg1, Vector<T>& arg2)
{
    if (arg1.m_size != arg2.m_size) {
        std::cout << "The size of vectors do not equal." << std::endl;
        return NULL;
    }
    Vector<T>* arr = new Vector<T> (5);
    for(int i = 0; i < arg1.m_index; ++i) {
        arr->m_array[i] = arg1[i] - arg2[i];
    }
	return *arr;
}
//////////////////////////////////////////////////
template <typename T>
Vector<T>& operator+ (Vector<T>& arg1, Vector<T>& arg2)
{
    if (arg1.m_size != arg2.m_size) {
        std::cout << "The size of vectors do not equal." << std::endl;
        return NULL;
    }
    Vector<T>* arr = new Vector<T> (5);
    for(int i = 0; i < arg1.m_index; ++i) {
        arr->m_array[i] = arg1[i] + arg2[i];
    }
	return *arr;
}
///////////////////////////////////////////////////
template <typename T>
void Vector<T>::update_obj_by_index(unsigned int index, const T& obj) 
{
    if (m_size < index) {
        std::cout << "There is no object with " << index << " index." << std::endl;
        return; 
    }
    m_array[index] = obj;
}
//////////////////////////////////////////////////
template <typename T>
void Vector<T>::increase_vector()
{
    if (m_size < 1) {
        delete[] m_array;
        m_array = new T[100];
        m_size = 100;
    }
    if (m_size < m_index + 1) {
        m_size = m_size * 5;
        T* arr = new T[m_size];
        for( int i = 0; i < m_index; ++i) {
            arr[i] = m_array[i];
        }
        delete[] m_array;
        m_array = arr;
    }
}
//////////////////////////////////////////////////
template <typename T>
void Vector<T>::push(const T& obj)
{
    increase_vector();
    m_array[m_index] = obj;
    m_index++;
}
//////////////////////////////////////////////////
template <typename T>
void Vector<T>::push_index(unsigned int index, const T& obj)
{
    if (m_size < index) {
        std::cout << "There is no object with " << index << " index." << std::endl;
        return; 
    }
    if (m_index <= index) {
        push(obj);
        return;
    }
    increase_vector();
    for(int i = m_index; i >= index; --i) {
        m_array[i+1] = m_array[i];
    }
    m_array[index] = obj;
    m_index++;
}
//////////////////////////////////////////////////
template <typename T>
T Vector<T>::pop()
{
    if (m_index < 1) {
        std::cout << "There is no object to pop." << std::endl;
        return NULL; 
    }
    m_index--;      // or return m_array[m_index--]
    return m_array[m_index+1]; 
}
//////////////////////////////////////////////////
template <typename T>
T Vector<T>::pop_index(unsigned int index)
{
    if (m_size < index) {
        std::cout << "There is no object with " << index << " index." << std::endl;
        return 0; 
    }
    if (m_index <= index) {
        return pop();
    }
    T tmp = m_array[index];
    for(int i = index; i < m_index; ++i) {
        m_array[i] = m_array[i+1];
    }
    m_index--;
    return tmp;
}
//////////////////////////////////////////////////
template <typename T>
void Vector<T>::clear()
{
    m_index = 0;
}
//////////////////////////////////////////////////
template <typename T>
void Vector<T>::print()
{
    for(int i = 0; i < m_index; ++i) {
        std::cout << "Vector[" << i << "]= " << m_array[i] << std::endl;
    }
}
#endif
