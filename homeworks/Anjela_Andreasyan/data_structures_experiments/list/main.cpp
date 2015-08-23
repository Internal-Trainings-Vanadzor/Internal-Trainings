#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>

void addNElement(std::list<int> &slist, int n){
    std::cout<<"Started pushing....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    for (int i=0; i<n; ++i){
        slist.push_back(i);
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

void insertElement(std::list<int> &slist,const int& val, int index){
    std::cout<<"Started inserting....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    slist.insert(slist.begin(), index, val);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

bool searchElement(std::list<int> &slist,int val){
    std::cout<<"Started searching....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    if(std::find(slist.begin(), slist.end(), val)!=slist.end()) isFound=true;
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}

bool searchElements(std::list<int> &slist,std::list<int> &slist2){
    std::cout<<"Started searching elements of one list in another....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    for(std::list<int>::iterator it=slist2.begin(); it != slist2.end(); ++it) {
        if(std::find(slist.begin(), slist.end(), *it)!=slist.end()) isFound=true;
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}

void getElByIndex(std::list<int> &slist, unsigned int index){
    std::cout<<"Started searching element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    std::list<int>::iterator it = slist.begin();
    std::advance(it, index);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

void deleteElement(std::list<int> &slist,int index){
    std::cout<<"Started deleting an element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    std::list<int>::iterator it = slist.begin();
    std::advance(it, index);
    slist.erase(it);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

int main(){
    std::list<int> slist;
    addNElement(slist, 1000000);
    insertElement(slist, 15 ,500000);
    searchElement(slist, 999999);
    std::list<int> slist2;
    addNElement(slist2, 1000);
    searchElements(slist, slist2);
    getElByIndex(slist, 1000000);
    deleteElement(slist, 500000);
    return 0;
}
