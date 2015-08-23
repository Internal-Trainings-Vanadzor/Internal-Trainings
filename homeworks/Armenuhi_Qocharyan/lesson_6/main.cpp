#include<iostream>
#include <array>
#include <vector>
#include<algorithm>

std::vector<int> initVector(int size){
    clock_t startTime = clock();
    std::vector<int> myVector = {};
    for (int i=0; i< size; ++i) {
      auto it = myVector.emplace ( myVector.begin(), i );
    }
    std::cout << "Init time for vector "<< size<< " elements " << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return myVector;

}


std::vector<int> addElement(std::vector<int> myVector, int element){
    clock_t startTime = clock();
    myVector.push_back (element);
    std::cout << "Time for adding element in the vector "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return myVector;

}


std::vector<int> deleteElementByIndex(std::vector<int> myVector, int index){
    clock_t startTime = clock();
    myVector.erase(myVector.begin()+index); 
    std::cout << "Time for deleting element in the vector by index "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return myVector;

}


std::vector<int> deleteElementByValue(std::vector<int> myVector, int value){
    clock_t startTime = clock();
    myVector.erase(std::remove(myVector.begin(), myVector.end(), value), myVector.end());
    std::cout << "Time for deleting element in the vector by index "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return myVector;

}

int searchElementByIndex(std::vector<int> myVector, int index){
    clock_t startTime = clock();
    int element = myVector[index];
    std::cout << "Time for searching element in the vector "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return element;

}


int searchElementByValue(std::vector<int> myVector, int value){
    clock_t startTime = clock();
    int index = myVector.at(value);
    std::cout << "Time for searching index in the vector "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << "\n";
    return index;

}


int main(){
	std::vector<int> v;
	v = initVector(100000);
	std::vector<int> v1 = addElement(v, 8);
	std::vector<int> v2 = deleteElementByIndex(v, 8);
	std::vector<int> v3 = deleteElementByValue(v, 8);
	int element = searchElementByIndex(v, 10000);
	int element1 = searchElementByValue(v, 100);
	return 0;
}
