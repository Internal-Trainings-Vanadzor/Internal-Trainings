#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void addNElement(std::vector<int> &vect, int n){
    std::cout<<"Started pushing....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    for (int i=0; i<n; ++i){
        vect.push_back(i);
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

void insertElement(std::vector<int> &vect,int val, int index){
    std::cout<<"Started inserting....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    vect.insert(vect.begin()+index, val);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

bool searchElement(std::vector<int> &vect,int val){
    std::cout<<"Started searching....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    if(std::find(vect.begin(), vect.end(), val)!=vect.end()) isFound=true;
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}

bool searchElements(std::vector<int> &vect,std::vector<int> &vect2){
    std::cout<<"Started searching elements of one vector in another....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    bool isFound = false;
    for(std::size_t i = 0; i <vect2.size(); i++) {
        if(std::find(vect.begin(), vect.end(), vect2[i])!=vect.end()) isFound=true;
    }
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return isFound;
}

int getElByIndex(std::vector<int> &vect, int index){
    std::cout<<"Started searching element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    int el = vect[index];
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
    return el;
}

void deleteElement(std::vector<int> &vect,int index){
    std::cout<<"Started deleting an element by index....\n";
    long  startTime = time(0) *1000;
    std::cout<<"Current time is:\t" <<startTime<<"\n";
    vect.erase(vect.begin() + index);
    long  endTime = time(0) *1000;
    std::cout<<"End time is:\t" <<endTime<<"\n";
    std::cout<<"Operation duration is:\t" <<endTime - startTime<<"ms \n";
}

int main(){
    std::vector<int> vect;
    addNElement(vect, 1000000);
    std::cout<<"Size is" << vect.size()<<"\n";
    insertElement(vect, 15 ,500000);
    std::cout<<"New size is"<<vect.size()<<"\n";
    searchElement(vect, 999999);
    std::vector<int> vect2;
    addNElement(vect2, 1000);
    searchElements(vect, vect2);
    getElByIndex(vect, 1000000);
    deleteElement(vect, 500000);
    return 0;
}
