#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree(){
    root=NULL;
}

void BinaryTree::insert(int value){
    if(root!=NULL)
        insert(value, root);
    else
    {
        root=new Node;
        root->value=value;
        root->left=NULL;
        root->right=NULL;
    }
}

void BinaryTree::insert(int value, Node *leaf){
    if(value< leaf->value)
    {
        if(leaf->left!=NULL)
            insert(value, leaf->left);
        else
        {
            leaf->left=new Node;
            leaf->left->value=value;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }  
    }
    else if(value>=leaf->value)
    {
        if(leaf->right!=NULL)
            insert(value, leaf->right);
        else
        {
            leaf->right=new Node;
            leaf->right->value=value;
            leaf->right->left=NULL;
            leaf->right->right=NULL; 
        }
    }

}


Node* BinaryTree::search(int value){
    return search(value, root);
}

Node* BinaryTree::search(int value, Node *leaf){
    if(leaf!=NULL)
    {
        if(value==leaf->value)
            return leaf;
        if(value<leaf->value)
            return search(value, leaf->left);
        else
            return search(value, leaf->right);
    }
    else return NULL;
}

void BinaryTree::destroy(){
    destroy(root);
    root=NULL;
}

void BinaryTree::destroy(Node *leaf){
    if(leaf!=NULL)
    {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
        leaf = NULL;
    }
}

bool BinaryTree::isEmpty(){
    if (root == NULL){
        return true;
    }
    return false;
}

bool BinaryTree::exists(int value){
    Node* node = search(value);
    if (node != NULL){
        return true;
    }
    return false;
}

BinaryTree::~BinaryTree(){
    destroy();
}

