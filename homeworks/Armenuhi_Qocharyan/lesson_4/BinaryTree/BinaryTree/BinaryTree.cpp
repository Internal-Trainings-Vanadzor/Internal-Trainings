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
                leaf->left = new Node;
                leaf->left->key_value = key;
                leaf->left->exists = true;
            } else {
		if (parent->right == NULL) {
                    int tempNode = parent->key_value;
                    parent->key_value = leaf->key_value;
		    parent->right = new Node;
	            parent->right->key_value = tempNode;
                    parent->right->exists = true;
	            parent->left = new Node;
                    parent->left->key_value = key;
                    parent->left->exists = true;
		} else {
                    int tempNode = parent->key_value;
                    parent->key_value = key;
		    parent->right = new Node;
                    parent->right->exists = true;
	            parent->right->key_value = tempNode;
	            parent->left = new Node;
                    parent->left->exists = true;
                    parent->left->key_value = leaf->key_value;
                    
                }
            }
     }  
  } else if(key > leaf->key_value) {
        if(leaf->right != NULL) {
            insert(key, leaf->right, leaf);
        } else {
            if (parent->right != NULL && parent->left != NULL) {
                leaf->right = new Node;
                leaf->right->key_value = key;
                leaf->right->exists = true;
            } else {
                if (parent->left == NULL) {
                    int tempNode = parent->key_value;
                    parent->key_value = leaf->key_value;
		    parent->left = new Node;
	            parent->left->key_value = tempNode;
                    parent->left->exists = true;
	            parent->right = new Node;
                    parent->right->key_value = key;
                    parent->right->exists = true;
		} else {
                    int tempNode = parent->key_value;
                    parent->key_value = key;
		    parent->left = new Node;
                    parent->left->exists = true;
	            parent->left->key_value = tempNode;
	            parent->right = new Node;
                    parent->right->exists = true;
                    parent->right->key_value = leaf->key_value;
                   
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
           root->left = new Node;
           root->left->key_value = key;
           root->left->exists = true;
           root->left->left = NULL;
           root->left->right = NULL;
      } else {
         if (key > root->key_value && root->right == NULL ) {
               root->right = new Node;
               root->right->key_value = key;
               root->right->exists = true;
               root->right->left = NULL;
               root->right->right = NULL;
	 
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
      root = new Node;
      root->key_value = key;
      root->exists = true;
      root->left = NULL;
      root->right = NULL;
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

//int main() { 
//   BinaryTree tree;	
//   tree.insert(8);
//   tree.insert(6);
//   tree.insert(12);
//   Node *b = tree.removeElement(12);
//   Node *a = tree.search(8);
//   std::cout << a->exists << "\n";
//   std::cout << b->exists << "\n";
//   return 0;
//}
