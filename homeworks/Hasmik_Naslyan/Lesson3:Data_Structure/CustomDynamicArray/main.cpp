#include "dynamicArray.hpp"
#include <iostream>
using namespace std;

int main () {
    dynamicArray array;
    array.add(1); 
    array.add(2);
    array[2] = 3;
    array.add(4);
    for (int i = 0; i < array.getSize(); i++) 
        cout << array[i] << endl;
    cout <<"size before remove "<<array.getSize()<< endl;
    array.remove();
    cout <<"size after remove "<<array.getSize()<< endl;
    array.insert(0,0);
    cout <<"size after insert "<<array.getSize()<< endl;
    for (int i = 0; i < array.getSize(); i++) 
        cout << array[i] << endl;

    return 0; 
}
