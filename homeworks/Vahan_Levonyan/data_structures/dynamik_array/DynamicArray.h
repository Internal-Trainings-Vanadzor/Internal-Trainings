#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
class DynamicArray {
    public:
        DynamicArray();
        ~DynamicArray();
        void push_back(int value);
        void pop_back();
        void remove(unsigned int index);
        void insert (unsigned int index, int value);
        void clear();
        void set(unsigned int index, int value);
        int getValue(unsigned int index);
        bool isEmpty();
        unsigned int size();

    private:
        unsigned int m_size;
        int* m_buffer;
        unsigned int m_buffer_size;
        void resize();

};
#endif
