#ifndef CUSTOM_AUTO_PTR
#define CUSTOM_AUTO_PTR

#include <iostream>

template <typename T>
class my_auto_ptr {

public:
    // non member function
    /*
     *  param - output stream
     *  param - my_auto_ptr object for cout
     */
    template <typename A>
    friend std::ostream& operator<<(std::ostream&, const my_auto_ptr<A>&);
    // member functions
    /*
     *
     */
    T* release();
    /*
     * param - my_auto_ptr obj for assignment
     * return - assigned object
     */
    my_auto_ptr<T>& operator=(my_auto_ptr<T>&);
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
    explicit my_auto_ptr(T*);
    /*
     * param - my_auto_ptr obj which should be copied
     */
    my_auto_ptr(my_auto_ptr<T>&);
    ~my_auto_ptr();

private:
    T *m_pointer;
};

// non memeber functions
template <typename T>
std::ostream& operator<<(std::ostream& os, const my_auto_ptr<T>& obj) {
    os << *obj.m_pointer;
    return os;
}

// memeber functions
template <typename T>
T my_auto_ptr<T>::getValue() const {
    return *m_pointer;
}

template <typename T>
T* my_auto_ptr<T>::getPointer() const {
    return m_pointer;
}

template <typename T>
void my_auto_ptr<T>::setPointerValue(const T& arg) {
    *m_pointer = arg;
}

template <typename T>
my_auto_ptr<T>& my_auto_ptr<T>::operator=(my_auto_ptr<T>& arg) {
    if (&arg == this) {
        return *this;
    }
    // check my count and delete previous me
    delete m_pointer;
    // assign new value
    m_pointer = arg.release();
    return *this;
}

template <typename T>
T& my_auto_ptr<T>::operator*() const {
    return *m_pointer;
}

template <typename T>
T* my_auto_ptr<T>::operator->() const {
    return m_pointer;
}

template <typename T>
T* my_auto_ptr<T>::release() {
    T* tmp = m_pointer;
    m_pointer = 0;
    return tmp;
}

// constructors and destructor
template <typename T>
my_auto_ptr<T>::my_auto_ptr(T* arg = NULL) {
    m_pointer = arg;
}

template <typename T>
my_auto_ptr<T>::my_auto_ptr(my_auto_ptr<T>& arg) {
    if (this == &arg) {
        return;
    }
    // assign new value
    m_pointer =arg.release();
}

template <typename T>
my_auto_ptr<T>::~my_auto_ptr(){
    delete m_pointer;
}

#endif
