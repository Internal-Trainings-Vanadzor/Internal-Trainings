#include <iostream>
#include "BinaryTree.h"
using std::cout;

int main(){
    BinaryTree tree;
    for (int i=1; i<10; i++){
        tree.insert(i);
    }
    cout<<"Searching existing element...\n found element: "<<tree.search(5)<<"\n";
    cout<<"Searching non existing element...\n found element: "<<tree.search(15)<<"\n";
    cout<<"5 existis in tree with 1-9 values: "<<tree.exists(5)<<"\n";
    cout<<"25 existis in tree with 1-9 values: "<<tree.exists(25)<<"\n";
    tree.destroy();
    cout<<"Searching existing element after destroy...\n found element: "<<tree.search(5)<<"\n";
    cout<<"Is tree empty after destroying... "<<tree.isEmpty()<<"\n";
    return 0;
}

