#ifndef myNode
#define myNode

#include <iostream>

struct Node {
    public:
      int key_value;
      bool exists = false;
      Node *left = NULL;
      Node *right = NULL;

      Node(int value) {
          exists = false;
          left = NULL;
          right = NULL;
          exists = true;
          key_value  = value;
      }
};

#endif
