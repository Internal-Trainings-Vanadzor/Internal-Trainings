#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
    m_head = new Node();
    m_tail = 0;
}
DoubleLinkedList::~DoubleLinkedList()
{
    erase();
}

bool DoubleLinkedList::isEmpty(){
    return (this->m_tail == 0);
}

void DoubleLinkedList::push_back(int value){
    if (this->isEmpty()){
        this->m_head->data = value;
        this->m_tail = this->m_head;
        return;
    }
    Node* node = new Node(value);
    node->p_prev = this->m_tail;
    this->m_tail->p_next = node;
    this->m_tail = node;
}

void DoubleLinkedList::push_front(int value){
    if (this->isEmpty()){
        this->m_head->data = value;
        this->m_tail = this->m_head;
        return;
    }
    Node* node = new Node(value);
    node->p_next = this->m_head;
    this->m_head->p_prev = node;
    this->m_head = node;
}

void DoubleLinkedList::pop_back(){
    if(this->m_tail->p_prev == 0){
        delete this->m_head;
        this->m_head = 0;
        this->m_tail =0; 
        return;
    }
    this->m_tail = this->m_tail->p_prev;
    delete this->m_tail->p_next;
    this->m_tail->p_next = 0;
}
void DoubleLinkedList::pop_front(){
    if(this->m_head->p_next == 0){
        delete this->m_head;
        this->m_head = 0;
        this->m_tail =0; 
        return;
    }
    this->m_head = this->m_head->p_next;
    delete this->m_head->p_prev;
    this->m_head->p_prev = 0;
}
void DoubleLinkedList::insertAfter(int pos, int value){
    Node* iter = this->m_head;
    for(int i = 0; i < pos; ++i){
        iter = iter->p_next;
    }
    if(iter == m_tail){
        this->push_back(value);
    }
    else{
        Node* node = new Node(value);
        node->p_next = iter->p_next;
        iter->p_next = node;
        node->p_prev = iter;
    }
}
void DoubleLinkedList::remove(int pos){
    Node* iter = this->m_head;
    for(int i = 0; i < pos; ++i){
        iter = iter->p_next;
    }
    iter->p_prev->p_next = iter->p_next;
    iter->p_next->p_prev = iter->p_prev;
}

void DoubleLinkedList::print()
{
    if(this->isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    Node* iter = this->m_head;
    while(iter != this->m_tail) {
        std::cout << iter->data << std::endl;
        iter = iter->p_next;
    }
    std::cout << iter->data << std::endl;
}

void DoubleLinkedList::erase(){
    if(this->isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    Node* iter = this->m_head;
    while(iter != this->m_tail){
        iter = iter->p_next;
        this->pop_front();
    }
    this->pop_front();
}
