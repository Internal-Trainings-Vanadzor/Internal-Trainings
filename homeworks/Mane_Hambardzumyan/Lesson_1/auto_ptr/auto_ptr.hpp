#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class AutoPtr {
    private:
        T* m_pointer;
        T* release();

    public:
        explicit AutoPtr(T* pointer = 0) {
            m_pointer = pointer;
        }

        AutoPtr(AutoPtr& other);
        ~AutoPtr();
        
        T* get() const;
        void reset(T* object = 0);

        AutoPtr& operator=(AutoPtr& other);
        T& operator*();
        T* operator->();
};

template <typename T>
AutoPtr<T>::AutoPtr(AutoPtr& object) {
    m_pointer = object.release();
}

template <typename T>
AutoPtr<T>::~AutoPtr() {
    if (m_pointer) {
        delete m_pointer;
    }
    m_pointer = 0;
}   

template <typename T>
T* AutoPtr<T>::get() const {
    return m_pointer; 
}

template <typename T>
void AutoPtr<T>::reset(T* object) {
    if (m_pointer != object) {
        delete m_pointer;
        m_pointer = object;
    }
}

template <typename T>
AutoPtr<T>& AutoPtr<T>::operator=(AutoPtr& object) {   
    if (this == &object) {
        return *this;
    }
    delete m_pointer;
    m_pointer = object.release();
    return *this;
}

template <typename T>
T& AutoPtr<T>::operator*() {
    return *m_pointer;
}

template <typename T>
T* AutoPtr<T>::operator->() {
    return m_pointer;
}

template <typename T>
T* AutoPtr<T>::release() {
    T* tmp = m_pointer;
    m_pointer = 0;
    return tmp;
}
