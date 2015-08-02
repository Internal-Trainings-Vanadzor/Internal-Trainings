#ifndef myNode
#define myNode

#include <iostream>

struct Node {
    public:
      int key_value;
      bool exists = false;
      Node *left = NULL;
      Node *right = NULL;
};

#endif
