#include <iostream>
#include "DynamicArray.hpp"

using std::cout;


int main(){
    DynamicArray dyn_arr;
    cout<<"Size in the beginning \t"<<dyn_arr.getSize()<<"\n";
    for(int i=1; i<=9; i++){
        dyn_arr.append(i);
    }
    cout<<"Size after appending 4 elements: "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    dyn_arr.insert(2,9);
    cout<<"Size after inserting an element in 2 position: "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    dyn_arr.removeLastEl();
    cout<<"Size after deleting the last element:  "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    dyn_arr.remove(2);
    cout<<"Size after deleting the second element:  "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    dyn_arr.removeRange(2,4);
    cout<<"Size after deleting the elements from 2 to 4 range:  "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    dyn_arr.set(1, 10);
    cout<<"Size after setting new value to the first element:  "<<dyn_arr.getSize()<<"\n";
    dyn_arr.printArray();
    cout<<dyn_arr[1];
    return 0;
}
