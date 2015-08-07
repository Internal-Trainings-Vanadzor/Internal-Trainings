#include <cstdint>
#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
  destroyTree();
}


void BinaryTree::destroyTree(Node *leaf) {
    if(leaf != NULL) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int key, Node* leaf, Node* parent) {
  if(key < leaf->key_value) {
    if(leaf->left != NULL) {
        insert(key, leaf->left, leaf);
    } else {
            if (parent->right != NULL && parent->left != NULL) {
                leaf->left = new Node(key);
            } else {
		if (parent->right == NULL) {
                    int tempNode = parent->key_value;
                    parent->key_value = leaf->key_value;
		    parent->right = new Node(tempNode);
	            parent->left = new Node(key);
		} else {
                    int tempNode = parent->key_value;
                    parent->key_value = key;
		    parent->right = new Node(tempNode);
	            parent->left = new Node(leaf->key_value);
                    
                }
            }
     }  
  } else if(key > leaf->key_value) {
        if(leaf->right != NULL) {
            insert(key, leaf->right, leaf);
        } else {
            if (parent->right != NULL && parent->left != NULL) {
                leaf->right = new Node(key);
            } else {
                if (parent->left == NULL) {
                    int tempNode = parent->key_value;
                    parent->key_value = leaf->key_value;
		    parent->left = new Node(tempNode);
	            parent->right = new Node(key);
		} else {
                    int tempNode = parent->key_value;
                    parent->key_value = key;
		    parent->left = new Node(tempNode);
	            parent->right = new Node(leaf->key_value);
                }
            }
        }  
    } else if (!leaf->exists) {
         leaf->exists = true; 
    }
}


Node *BinaryTree::search(int key, Node *leaf) {
        if(leaf != NULL) {
            if(key == leaf->key_value && leaf->exists) {
               return leaf;
            }
            if(key < leaf->key_value) {
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
         } else {
              return NULL;
         }
}

bool  BinaryTree::exists(int key) {
    exists(key, root);
}

bool BinaryTree::exists(int key, Node *leaf) {
        if(leaf != NULL ) {
            if(key == leaf->key_value  && leaf->exists) {
               return true;
            }
            if(key < leaf->key_value) {
                return exists(key, leaf->left);
            } else {
                return exists(key, leaf->right);
            }
         } else {
              return false;
         }
}


void BinaryTree::insert(int key) {
  if(root != NULL) {
      if (key < root->key_value && root->left == NULL) {
           root->left = new Node(key);
      } else {
         if (key > root->key_value && root->right == NULL ) {
               root->right = new Node(key);
         } else {
	     if (key < root->key_value) {  
                 insert(key, root, root->left);
             } else {
		 if (key > root->key_value) {
                     insert(key, root, root->right);
                 }
	     }
         }
      }
  } else {
      root = new Node(key);
  }
}

Node *BinaryTree::search(int key) {
  return search(key, root);
}

void BinaryTree::destroyTree() {
  destroyTree(root);
}


void BinaryTree::removeElement(int key) {
    Node* updateNode = search(key, root);
    if (updateNode != NULL) {
        updateNode->exists = false;
    } else {
	std::cout << key << " element does not exist ..." << "\n";
    }
}

