#include <limits>
#include <iostream>
#include "objectsCounter.hpp"

unsigned int Counter::m_objects_count(0);

Counter::Counter(){
    unsigned int maxIntVal = std::numeric_limits<unsigned int>::max();
    if (m_objects_count< maxIntVal){
        ++m_objects_count;
    }else{
        std::cout<<"[Warning] The number of the class objects is greater than the max int number: " + maxIntVal;
    }
}

Counter::Counter( Counter& counterObj){
    int maxIntVal = std::numeric_limits<int>::max();
    if (m_objects_count< maxIntVal){
        ++m_objects_count;
    }else{
        std::cout<<"[Warning] The number of the class objects is greater than the max int number: " + maxIntVal;
    }
}

Counter::~Counter(){
    --m_objects_count;
}

unsigned int Counter::getObjectsCount(){
    return m_objects_count;
}


