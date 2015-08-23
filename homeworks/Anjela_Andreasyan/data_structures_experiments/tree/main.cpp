#include <iostream>
#include <set>
#include <ctime>
#include <algorithm>

void addNElement(std::set<int> &mset, int n){
    std::cout<<"Started pushing....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    for (int i=0; i<n; ++i){
        mset.insert(i);
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

void insertElement(std::set<int> &mset,int val, int index){
    std::cout<<"Started inserting....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    std::set<int>::iterator it= mset.begin();
    std::advance(it, index);
    mset.insert(it, val);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

bool searchElement(std::set<int> &mset,int val){
    std::cout<<"Started searching....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    if(std::find(mset.begin(), mset.end(), val)!=mset.end()) isFound=true;
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}

bool searchElements(std::set<int> &mset,std::set<int> &mset2){
    std::cout<<"Started searching elements of one set in another....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    for(std::set<int>::iterator it=mset2.begin(); it != mset2.end(); ++it) {
         if(std::find(mset.begin(), mset.end(), *it)!=mset.end()) isFound=true;
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}
/*
int getElByIndex(std::set<int> &mset, int index){
    std::cout<<"Started searching element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    int el = mset[index];
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return el;
}

void deleteElement(std::set<int> &mset,int index){
    std::cout<<"Started deleting an element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    mset.erase(mset.begin() + index);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}
*/
int main(){
    std::set<int> mset;
    addNElement(mset, 1000000);
    std::cout<<"Size is" << mset.size()<<"\n";
    insertElement(mset, 15 ,500000);
    std::cout<<"New size is"<<mset.size()<<"\n";
    searchElement(mset, 999999);
    std::set<int> mset2;
    addNElement(mset2, 1000);
    searchElements(mset, mset2);
/*    getElByIndex(mset, 1000000);
    deleteElement(mset, 500000);*/
    return 0;
}
