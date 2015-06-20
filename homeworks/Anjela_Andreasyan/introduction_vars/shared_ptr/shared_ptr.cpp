#include <iostream>
#include <limits>

template < typename T > class shared_ptr
{
    private:
        T* m_ptr;
        unsigned int* refCount;
        void increaseRefCount(){
            unsigned int maxIntVal = std::numeric_limits<unsigned int>::max();
            if (*refCount < maxIntVal){
                ++(*refCount);
            }else{
                std::cout<<"[Warning] The number of the shared pointers is greater than the max int number: " + maxIntVal;
            }
        }

    public:
        shared_ptr(T* val=0){
            m_ptr=val;
            refCount = new unsigned int (1); 
        }

        shared_ptr(const shared_ptr<T>& sharedP){ 
            m_ptr=sharedP.m_ptr;
            refCount = sharedP.refCount;
            increaseRefCount();
        }

        shared_ptr<T>& operator= (shared_ptr<T>& sharedP){
            if (this != &sharedP){
                this->~shared_ptr();
                m_ptr=sharedP.m_ptr;
                refCount = sharedP.refCount;
                increaseRefCount();
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
                *refCount=1; // TODO check / test this function
                m_ptr=val;
            }
        }

        void release(){
            if(*refCount > 0){
                --(*refCount);
            }else{
                std::cout<<"[Warning] The number of the shared pointers is already 0";
                m_ptr=NULL;
            }
        }
};

