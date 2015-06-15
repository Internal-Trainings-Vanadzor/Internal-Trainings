#include <iostream>

template < typename T > class auto_ptr
{
    private:
        T*    m_ptr;

    public:
        auto_ptr(T* val=0){
            m_ptr=val;
        }

        auto_ptr(const auto_ptr<T>& autoP){
            m_ptr=autoP.m_ptr;
            autoP.m_ptr=NULL;
        }

        auto_ptr<T>& operator = (auto_ptr<T>& autoP){
            m_ptr=autoP.m_ptr;
            autoP.m_ptr=NULL;
            return *this;
        }
        ~auto_ptr(){
            if(m_ptr){
                delete m_ptr;
            }
        }

        T* get(){
            return m_ptr;
        }
        void reset(T* val){
            if(m_ptr){
                m_ptr=val;
            }
        }
};

