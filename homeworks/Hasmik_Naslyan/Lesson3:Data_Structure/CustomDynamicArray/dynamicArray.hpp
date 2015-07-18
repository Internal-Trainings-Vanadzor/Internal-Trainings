#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
/**
 * This is a custom dynamic array class.
 */
class dynamicArray{
    private:
        int* myArray;
        int length, size;

    public:
        dynamicArray();
        ~dynamicArray();
        void add(int element);
        void remove();
        void insert(int pos, int element);
        void erase(int from, int to);
        int getSize();
        bool isEmpty();
	/**
         * array indexing operation([] operator) has been overloaded to serve as both left and righthand values.
         */
        int& operator[](int index); 
};
#endif
