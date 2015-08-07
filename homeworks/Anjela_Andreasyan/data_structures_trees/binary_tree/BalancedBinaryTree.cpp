#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BalancedBinaryTree.hpp" 
using std::max;
using std::cout;
using std::setw;

BalancedBinaryTree::BalancedBinaryTree(){
    root=NULL;
}

BalancedBinaryTree::~BalancedBinaryTree(){
    delete root;
}

void BalancedBinaryTree::insert(int value){
    if (NULL == root){
        root = new Node(value, NULL, NULL);
    }else{
        root = insert(value, root);
    }

}

bool BalancedBinaryTree::search(int value){
    return search(value, root);
}

void BalancedBinaryTree::remove(int value){
    root = remove(value, root);
}

void BalancedBinaryTree::printTree(){
    prettyPrint(root,0);
}

Node* BalancedBinaryTree::insert(int value, Node* node){
    if (NULL != node){
        if (value < node->value){
            if (NULL == node->left){
                node->left = new Node(value, NULL, NULL);
            }else{
                node->left = insert(value, node->left);
                if (height(node->left) - height(node->right) == 2){
                    if (value < node->left->value){
                        node = leftRotate(node);
                    }else{
                        node = doubleLeftRotate(node);
                    }
                }
            }
        }else if (value > node->value){
            if (NULL == node->right){
                node->right = new Node(value, NULL, NULL);
            }else{
                 node->right = insert(value, node->right);
                 if (height(node->right) - height(node->left) == 2){
                     if (value > node->right->value){
                        node = rightRotate(node);
                     }else{
                         node = doubleRightRotate(node);
                     }
                 }
            }
        }
    }else{
        node= new Node(value, NULL, NULL);
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}
bool BalancedBinaryTree::search(int value, Node* node){
    if (NULL == node){
        return false;
    }
    if (value == node->value){
        return true;
    }
    if (value < node->value){
        return search(value, node->left);
    }else{
        return search(value, node->right);
    }

}
Node* BalancedBinaryTree::remove(int value, Node* node){
    if (NULL == node){
        return NULL;
    }
    if (value == node->value){
        if (NULL == node->left && NULL == node->right){
            return NULL;
        }
        if(NULL == node->left) return node->right;
        if (NULL == node->right) return node->left;
        Node * tmp = getSmallestNodeOfRightLeaf(node->right);
        node->value=tmp->value;
        node->right = remove( tmp->value, node->right);
        return node;
    }
    if (value < node->value){
        node->left=remove(value, node->left);
        return node;
    }else{
        node->right=remove(value, node->right);
        return node;
    }
}
Node* BalancedBinaryTree::getSmallestNodeOfRightLeaf(Node* node){
    if (NULL != node){
        if (NULL == node->left) return node;
        return getSmallestNodeOfRightLeaf(node->left);
    }
}

int BalancedBinaryTree::height(Node* node){
    if (NULL != node) {
        return node->height;
    }else{
        return -1;
    }
}

Node* BalancedBinaryTree::leftRotate(Node* node){
    Node *rotatedNode = node->left;
    node->left = rotatedNode->right;
    rotatedNode->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    rotatedNode->height = max(height(rotatedNode->left), node->height) + 1;
    return rotatedNode;
}

Node* BalancedBinaryTree::rightRotate(Node* node){
    Node *rotatedNode = node->right;
    node->right = rotatedNode->left;
    rotatedNode->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    rotatedNode->height = max(height(rotatedNode->right), node->height) + 1;
    return rotatedNode;
}

Node* BalancedBinaryTree::doubleLeftRotate(Node* node){
    node->left = rightRotate(node->left);
    return leftRotate(node);
}

Node* BalancedBinaryTree::doubleRightRotate(Node* node){
    node->right = leftRotate(node->right);
    return rightRotate(node);
}

void BalancedBinaryTree::prettyPrint(Node* node, int indent){
    if(node != NULL) {
        cout<< node->value << "\n ";
        if(node->left) prettyPrint(node->left, indent+4);
        if(node->right) prettyPrint(node->right, indent+4);
        if (indent) {
            cout << setw(indent) << ' ';
        }
    }
}
