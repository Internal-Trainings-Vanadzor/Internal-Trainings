#include <iostream>
#include <cstdlib>
#include "BalancedBinaryTree.hpp"
using std::cout;

int main(){
    BalancedBinaryTree tree;
    int value;
    cout<<"\n ### Chosen numbers:\n";
    for (int i=1; i<20; i++){
        value=rand()%100 +1;
        cout<<value<<" , ";
        tree.insert(value);
    }
    cout<<"\n";
    cout<<"Searching existing element...\n found element: "<<tree.search(value)<<"\n";
    cout<<"Searching non existing element...\n found element: "<<tree.search(102)<<"\n";
    tree.printTree();
    tree.remove(value);
    cout<<"Searching removing element...\n found element: "<<tree.search(value)<<"\n";
    tree.printTree();
    return 0;
}

