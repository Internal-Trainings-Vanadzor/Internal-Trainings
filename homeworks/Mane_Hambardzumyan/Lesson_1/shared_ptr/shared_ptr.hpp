#include <iostream>
#include <limits.h>

template <typename T>
class SharedPtr {

    private:
        T* m_pt_object;
        unsigned long* m_ref_count;

        void deleteSharedPtr();
        void updateSharedPtr(const SharedPtr<T>&);

    public:
        SharedPtr(T* val);
        SharedPtr(const SharedPtr<T>&);
        ~SharedPtr();

        SharedPtr<T>& operator=(const SharedPtr<T>&);

        unsigned long getPointersCount();
        T getObject();
};

template <typename T>
SharedPtr<T>::SharedPtr(T* val) {
    m_pt_object = val;
    m_ref_count = new unsigned long(1);
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& obj) {
    this->updateSharedPtr(obj);
}

template <typename T>
SharedPtr<T>::~SharedPtr() {
    this->deleteSharedPtr();
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& obj) {
    this->deleteSharedPtr();
    this->updateSharedPtr(obj);
}

template <typename T>
unsigned long SharedPtr<T>::getPointersCount() {
    return *m_ref_count;
}

template <typename T>
T SharedPtr<T>::getObject() {
    return *m_pt_object;
}

template <typename T>
void SharedPtr<T>::deleteSharedPtr() {
    if (0 == m_ref_count) {
        return;
    }
    --(*m_ref_count);
    if (0 == *m_ref_count) {
        delete m_pt_object;
        delete m_ref_count;
        m_pt_object = 0;
        m_ref_count = 0;
    }
}

template <typename T>
void SharedPtr<T>::updateSharedPtr(const SharedPtr<T>& obj) {
    m_pt_object = obj.m_pt_object;
    m_ref_count = obj.m_ref_count;
    if (*m_ref_count - 1 > ULONG_MAX) {
        std::cout << "[WARNING]: Pointers count at red limit !!!.\n"; 
    }
    ++(*m_ref_count);
}
