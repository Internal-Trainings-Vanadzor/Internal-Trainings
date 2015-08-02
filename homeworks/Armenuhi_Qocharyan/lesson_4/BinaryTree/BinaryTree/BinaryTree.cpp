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

void BinaryTree::insert(int key, Node *leaf) {
  if(key < leaf->key_value) {
    if(leaf->left != NULL) {
        insert(key, leaf->left);
    } else {
      leaf->left = new Node;
      leaf->left->key_value = key;
      leaf->left->exists = true;
    }  
  } else if(key > leaf->key_value) {
        if(leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
              leaf->right = new Node;
              leaf->right->key_value = key;
              leaf->right->exists = true;
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
            if(key < leaf->key_value && leaf->exists) {
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
        if(leaf != NULL && leaf->exists) {
            if(key == leaf->key_value) {
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
      insert(key, root);
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
