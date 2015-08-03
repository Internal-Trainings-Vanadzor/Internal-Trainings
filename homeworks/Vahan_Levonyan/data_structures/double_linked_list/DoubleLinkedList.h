#ifndef LINKED_LIST
#define LINKED_LIST
#include <iterator>
class Node {
    public:
        Node(int value = 0) :
            p_next(0),
            p_prev(0),
            data(value)
        {}
        Node* p_next;
        Node* p_prev;
        int data;
};

class DoubleLinkedList {
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void push_back(int value);
        void push_front(int value);
        void pop_back();
        void pop_front();
        void insertAfter(int pos, int value);
        void remove(int pos);
        void print();
        void erase();
        bool isEmpty();
        Node* getHead() const { return m_head; }
        Node* getTail() const { return m_tail; }

    private:
        Node* m_head;
        Node* m_tail;
};
#endif
