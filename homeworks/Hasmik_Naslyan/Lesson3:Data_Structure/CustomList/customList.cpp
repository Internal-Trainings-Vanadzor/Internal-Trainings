#include <iostream>

struct node {
	int data;
	node* next;
};
node* head = NULL;
node* tail = NULL;


void add_first(node* element)
{
	if (head == NULL){
		head = element;
		tail = head;
	} else { 
		element->next = head;
		head = element;
	}

	std::cout<<"First element has been entered"<<std::endl;
}


void print(node* element)
{
	std::cout << "element = " << element->data;
}

void add_last(node* element)
{
	if (tail == NULL){
		tail = element;
		head = tail;
	} else { 
		tail->next = element;
		tail = element;
	}

	std::cout<<"Last element has been entered"<<std::endl;
}

void add_middle(int i, node* element){
	node* t = new node;
	t = head;
	for(int j = 0; j < i; ++j){
		t=t->next;
	}
	node* tt = t;
	t->next = element;
 	element->next = tt;
}

int main()
{
	node* element = new node;
	int i = 7;	
	element->data = 7;
	add_first(element);
	
	return 0;
}
