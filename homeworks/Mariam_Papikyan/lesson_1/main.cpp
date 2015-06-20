#include <iostream>
#include "classCounter.hpp"

using std::cout;
using std::endl;

int main()
{
    classCounter c;
    cout <<"Created object(s) count is "<<classCounter::getObjectsCount()<<endl;
    classCounter a=c;
    cout <<"Created object(s) count is "<<classCounter::getObjectsCount()<<endl;
    classCounter* b=new classCounter();
    cout <<"Created object(s) count is "<<classCounter::getObjectsCount()<<endl;
    delete b;
    cout <<"Created object(s) count is "<<classCounter::getObjectsCount()<<endl;
   
    return 0;
}