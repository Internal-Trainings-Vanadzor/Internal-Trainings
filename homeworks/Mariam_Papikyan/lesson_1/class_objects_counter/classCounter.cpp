#include "classCounter.hpp"

int classCounter::count(0);

classCounter::classCounter(){
    ++count;
}

classCounter::classCounter(const classCounter& counter){
    ++count;
}

classCounter::~classCounter(){
    --count;
}

int classCounter::getObjectsCount(){
    return count;
}