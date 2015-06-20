#include<iostream>
#include "objectsCounter.hpp"
using std::cout;

int main(){
    Counter a1;
    Counter a2;
    Counter a3;
    Counter a4;
    Counter a5;
    Counter a6;
    Counter a7;
    Counter a8;
    cout<<"[Info] Current count of objects is: "<<a1.getObjectsCount()<<"\n";
    {
        Counter a[10];
        cout<<"[Info] In this scope the count of objects is: "<<a5.getObjectsCount()<<"\n";
    }
    cout<<"[Info] After the scope the count of objects is: "<<a2.getObjectsCount()<<"\n";
    cout<<"[Info] After the scope the count of objects is: "<<Counter::getObjectsCount()<<"\n";
    return 0;
}

