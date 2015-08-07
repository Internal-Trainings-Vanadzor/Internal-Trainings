#include <iostream>
#include "Node.hpp"

Node::Node(int value, Node* left, Node* right){
    this->value = value;
    this->left = left;
    this->right = right;
    this->height = 0;
}

Node::~Node(){
    std::cout<<"Bye!";
}

