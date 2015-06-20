#ifndef AUTO_POINTER_CPP
#define AUTO_POINTER_CPP

#include "AutoPointer.hpp"
#include <iostream>

AutoPointer::AutoPointer(int* p)
{
    m_pointer = p;
}

AutoPointer::AutoPointer(AutoPointer& obj)
{
    m_pointer = obj.release();
}

AutoPointer::~AutoPointer()
{
    if(m_pointer) {
        delete m_pointer;
        this->m_pointer = NULL;
    }
}

int* AutoPointer::operator->()
{
    return m_pointer;
}

int& AutoPointer::operator*()
{
    return *m_pointer;
}

AutoPointer& AutoPointer::operator = (AutoPointer& ap)
{
    if(this == &ap )
    {
        return *this;
    }
    delete m_pointer;
    m_pointer = ap.release();
    return *this;
}

int* AutoPointer::getPointer()
{
    return m_pointer;
}

int* AutoPointer::release()
{
    int* temp = this->m_pointer;
    this->m_pointer = NULL;
    return temp;
}
#endif
