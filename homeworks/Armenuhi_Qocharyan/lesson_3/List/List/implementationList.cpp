#include "interfaceList.h"

List::List(int n){
	head->data = n;
	head->next = NULL;
	head->previous = NULL;
}

void List::addMyNode(int element, int position){
	Node *newNode = new Node;
	newNode->next = NULL;
	newNode->previous = NULL;
	Node *tempNode = new Node;
	tempNode->next = NULL;
	tempNode->previous = NULL;
	newNode->data = element;
	Node *current = head;
	int i = 0;
	if (position == 0){
		//addFirstElement(element);
	} 
	while (current){
		if (i < position - 1){
			i++;
			current = current->next;
		}
		tempNode->next = current->next;
		current->next = newNode;
		newNode->next = tempNode->next;
		return;
	}
	std::cout << "Can not add element in the list from the given position.\n";
	
}


void addFirstElement(int element) {
	Node *tempNode = new Node;
	tempNode->next = NULL;
	tempNode->previous = NULL;
	//TODO
	return;
}

struct Node *List::searchNode(int element) {
	Node *current = head;
	while(current) {
		if(current->data == element) { 
			std::cout << "The " << element << " exits in the list.\n";
			return current;
		}
		current = current->next;
	}
	std::cout << "No search " << element << " in the list.\n";
}

bool List::compareList(struct Node *node1, struct Node *node2)
{
	static bool t;
	if(node1 == NULL && node2 == NULL) {
		t = true;
	}
	else {
		if(node1 == NULL || node2 == NULL) 
			t = false;
		else if(node1->data != node2->data) 
			t = false;
		else
			compareList(node1->next, node2->next);
	}
	return t;
}


void List::printList() {
	Node *list = head;
	while(list) {
		std::cout << list->data << " ";
		list = list->next;
	}
	std::cout << "\n";
}

void List::deleteElement(int position){
	int i = 0;
	Node *current = head;
	Node *previous_current = head;
	if (position == 0){
		current = current->next;
		*head = *current->next;
		return;
	} 
	while (current){
		if (i <= position - 1){
			previous_current = current;
			current = current->next;
		} else {
			previous_current->next = current->next;
			delete current;
			return;
		} 
		i++;
}
	
	std::cout << "Can not delete element in the list from the given position.\n";
}

List::~List(){
	while(head == NULL){
		Node *n = head->next;
		delete head;
		head = n;
	}
}
