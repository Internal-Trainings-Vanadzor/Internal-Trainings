#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray{
    private:
        unsigned int size;
        unsigned int currentSize;
        int* arr;

        void reserve();

    public:
        DynamicArray();
        DynamicArray(unsigned int size);
        ~DynamicArray();

        int &operator[](unsigned int index);

        unsigned int getSize();
        void set(unsigned int index, int el);

        void append(int el);
        void insert(unsigned int index, int el);

        void removeLastEl();
        void remove(unsigned int index);
        void removeRange(unsigned int beginIndex, unsigned int endIndex);

        void printArray();
};

#endif
