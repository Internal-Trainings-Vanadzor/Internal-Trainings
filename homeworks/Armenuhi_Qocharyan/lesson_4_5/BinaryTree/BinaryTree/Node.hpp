#ifndef myNode
#define myNode

#include <iostream>

struct Node {
    public:
      int key_value;
      bool exists;
      Node *left;
      Node *right;

      Node(int value) {
          exists = false;
          left = NULL;
          right = NULL;
          exists = true;
          key_value  = value;
      }
};

#endif
