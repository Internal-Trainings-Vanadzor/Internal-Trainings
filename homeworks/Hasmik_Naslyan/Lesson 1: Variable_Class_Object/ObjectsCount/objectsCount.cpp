#include "objectsCount.hpp"

int objectsCount::counter (0);

objectsCount::objectsCount () {
   counter++; 
}

objectsCount::objectsCount (objectsCount& object) {
    counter++;
}

objectsCount::~objectsCount () {
     counter--;
}

int objectsCount::getObjectsCount () {
    return counter;
}

