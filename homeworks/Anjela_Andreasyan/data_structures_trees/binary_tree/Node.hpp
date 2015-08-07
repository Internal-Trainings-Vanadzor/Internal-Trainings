#ifndef NODE_HPP
#define NODE_HPP

class Node {
    public:
        int value;
        Node* left;
        Node* right;
        int height;
        Node(int value, Node* left, Node* right);
        ~Node();
};
#endif
