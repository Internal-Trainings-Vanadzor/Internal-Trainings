#ifndef CUSTOM_SHARED_PTR
#define CUSTOM_SHARED_PTR

#include <iostream>

template <typename T>
class my_shared_ptr {

public:
    // non member function
    /*
     *  param - output stream
     *  param - my_shared_ptr object for cout
     */
    template <typename A>
    friend std::ostream& operator<<(std::ostream&, const my_shared_ptr<A>&);
    // member functions
    /*
     *  return - count of objects which share the memory
     */
    unsigned int getUseCount() const;
    /*
     * param - my_shared_ptr obj for assignment
     * return - assigned object
     */
    my_shared_ptr<T>& operator=(my_shared_ptr<T>&);
    /*
     * return - the reference to the object
     */
    T& operator*() const;
    /*
     * return - the stored m_pointer
     */
    T* operator->() const;
    /*
     *  return - get value of m_pointer
     */
    T getValue() const;
    /*
     *  return - get m_pointer
     */
    T* getPointer() const;
    /*
     *  param - set new value for pointer
     */
    void setPointerValue(const T&);
    // constructors and destructor
    /*
     * param - value for pointer
     */
    explicit my_shared_ptr(T*);
    /*
     * param - my_shared_ptr obj which should be copied
     */
    my_shared_ptr(const my_shared_ptr<T>&);
    ~my_shared_ptr();

private:
    T *m_pointer;
    unsigned int* m_counter;
};

// non memeber functions
template <typename T>
std::ostream& operator<<(std::ostream& os, const my_shared_ptr<T>& obj) {
    os << *obj.m_pointer;
    return os;
}

// memeber functions
template <typename T>
unsigned int my_shared_ptr<T>::getUseCount() const {
    return *m_counter;
}

template <typename T>
T my_shared_ptr<T>::getValue() const {
    return *m_pointer;
}

template <typename T>
T* my_shared_ptr<T>::getPointer() const {
    return m_pointer;
}

template <typename T>
void my_shared_ptr<T>::setPointerValue(const T& arg) {
    *m_pointer = arg;
}

template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr<T>& arg) {
    if (&arg == this) {
        return *this;
    }
    // check my count and delete previous me
    if (1 == *m_counter) {
        delete m_pointer;
    }
    // assign new value
    std::cout << "operator m_counter " << *m_counter << std::endl;
    (*arg.m_counter)++;
    m_pointer = arg.m_pointer;
    *m_counter = *arg.m_counter;
    std::cout << "operator m_counter " << *m_counter << std::endl;
}

template <typename T>
T& my_shared_ptr<T>::operator*() const {
    return *m_pointer;
}

template <typename T>
T* my_shared_ptr<T>::operator->() const {
    return m_pointer;
}

// constructors and destructor
template <typename T>
my_shared_ptr<T>::my_shared_ptr(T* arg = NULL) {
    m_counter = new unsigned int(1);
    m_pointer = arg;
}

template <typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<T>& arg) {
    if (this == &arg) {
        return;
    }
    // assign new value
    (*arg.m_counter)++;
    m_pointer = arg.m_pointer;
    m_counter = arg.m_counter;
}

template <typename T>
my_shared_ptr<T>::~my_shared_ptr(){
    (*m_counter)--;
    if (0 == *m_counter) {
        delete m_pointer;
        delete m_counter;
    }
}

#endif
