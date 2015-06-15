#include <iostream>

template < typename T > class shared_ptr
{
    private:
        T* m_ptr;
        int* refCount;

    public:
        shared_ptr(T* val=0){
            m_ptr=val;
            refCount = new int (1); 
        }

        shared_ptr(const shared_ptr<T>& sharedP){ 
            m_ptr=sharedP.m_ptr;
            refCount = sharedP.refCount;
            ++(*refCount);
        }

        shared_ptr<T>& operator= (shared_ptr<T>& sharedP){
            if (this != &sharedP){
                this->~shared_ptr();
                m_ptr=sharedP.m_ptr;
                refCount = sharedP.refCount;
                ++(*refCount);
            }
            return *this;
        }
        ~shared_ptr(){
            --(*refCount);
            if(0 == *refCount){
                delete m_ptr;
                delete refCount;
            }
        }

        T get(){
            return *m_ptr;
        }

        T* getPtr(){
            return m_ptr;
        }

        int getCount(){
            return *refCount;
        }
        void reset(T* val){
            if(m_ptr){
                m_ptr=val;
            }
        }

        void release(){
            --(*refCount);
        }
};

