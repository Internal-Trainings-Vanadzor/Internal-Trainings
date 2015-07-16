#ifndef Brackets
#define Brackets
#include <iostream>
#include "Node.h"

class List { 
	
	public: 	
		struct Node *head = new Node;
	/**
	*Constructor for initialisation Node
	*/
	public: List(int n);

	/**
	*Append element in the list from the given position
	*/
	public: void addMyNode(int element, int position);

	/**
	*Delete element in the list
	*/
	public: void deleteElement(int position);
	
	/**
	*Search element in the list
	*/
	public: struct Node *searchNode(int element);
	
	/**
	*Compare two Lists
	*/
	public: bool compareList(struct Node *node1, struct Node *node2);

	/**
	*Print given List
	*/
	public: void printList();
	
	/**
	*Append element from the 0 position
	*/
	private: void addFirstElement(int element);
	
	/**
	*Destructor for deleting Node
	*/
	public: ~List();
};

#endif
