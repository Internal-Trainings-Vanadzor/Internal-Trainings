#include <iostream>

struct node {
	int data;
	node* next;
};
node* head = NULL;
node* tail = NULL;


void add_first(node* par)
{
	if (head == NULL){
		head = par;
		tail = head;
	} else { 
		par->next = head;
		head = par;
	}

	std::cout<<"First element has been entered"<<std::endl;
}


void print(node* par)
{
	std::cout << "par = " << par->data;
}

void add_last(node* par)
{
	if (tail == NULL){
		tail = par;
		head = tail;
	} else { 
		tail->next = par;
		tail = par;
	}

	std::cout<<"Last element has been entered"<<std::endl;
}

void add_middle(int i, node* par){
	node* t = new node;
	t = head;
	for(int j = 0; j < i; ++j){
		t=t->next;
	}
	node* tt = t;
	t->next = par;
 	par->next = tt;
}

int main()
{
	node* element = new node;
	int i = 7;	
	element->data = 7;
	add_first(element);
	
	return 0;
}
