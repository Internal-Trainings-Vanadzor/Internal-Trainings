#ifndef BALANCED_BINARY_TREE_HPP
#define BALANCED_BINARY_TREE_HPP
#include "Node.hpp"

class BalancedBinaryTree
{
    public:
        BalancedBinaryTree();
        ~BalancedBinaryTree();

        void insert(int value);
        bool search(int value);
        void remove(int value);
        void printTree();

    private:
        Node* root;
        Node* insert(int value, Node* node);
        bool search(int value, Node* node);
        Node* remove(int value, Node* node);
        Node* getSmallestNodeOfRightLeaf(Node* node);
        int height(Node* node);
        Node* leftRotate(Node* node);
        Node* rightRotate(Node* node);
        Node* doubleLeftRotate(Node* node);
        Node* doubleRightRotate(Node* node);
        void prettyPrint(Node* node, int indent);
};

#endif
