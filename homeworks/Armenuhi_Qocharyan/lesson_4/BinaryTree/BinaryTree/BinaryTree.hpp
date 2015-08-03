#ifndef Tree
#define Tree

#include "Node.hpp"

class  BinaryTree {
    public:
	/**
	*The constructor	
	*/
        BinaryTree();

	/**
	*The destructor
	*/
        ~BinaryTree();

	/**
	*Insert element
	*/
        void insert(int key);

	/**
	*Search element
	*/
        bool exists(int key);
        Node *search(int key);

	/**
	*Destroy tree
	*/
        void destroyTree();

	/**
	* Print for testing
	*/
	void print();
	
	/**
	*RemoveElement
	*/
	void removeElement(int key);

    private:
        bool exists(int key, Node *leaf);
        void destroyTree(Node *leaf);
        void insert(int key, Node *leaf, Node *parent);
        Node *search(int key, Node *leaf);
        Node *root; 
}; 

#endif
