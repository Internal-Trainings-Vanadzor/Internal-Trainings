#include "interfaceList.h"

//TODO Need to implement functionality to parse command line arguments 
int main() 
{

	struct Node *head = new Node;
	
	List list_object(10);	
	
	list_object.printList();

	list_object.addMyNode(20,1);
	list_object.printList();
	
	list_object.addMyNode(3,2);
	list_object.printList();
	
	list_object.addMyNode(35,3);
	list_object.printList();
	
	list_object.addMyNode(40,4);
	list_object.printList();
	
	list_object.addMyNode(12,0);
	list_object.printList();
        
	list_object.deleteElement(0);
	list_object.deleteElement(1);
	list_object.printList();

	bool t = list_object.compareList(head,head);
	if (t){
		std::cout <<"The lits are compare"<<"\n";
	} else {
		std::cout <<"The lits are not compare"<<"\n";
	}
	list_object.searchNode(35);	
	list_object.printList();
	return 0;
}
