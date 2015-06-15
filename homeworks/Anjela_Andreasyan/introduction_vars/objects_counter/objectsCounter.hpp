#ifndef OBJECTSCOUNTER_HPP
#define OBJECTSCOUNTER_HPP

#include <limits>
#include <iostream>

class Counter{
    private:
            static int m_objects_count;

    public:
        Counter();
        
        Counter( Counter& counterObj);
        
        ~Counter();

        int getObjectsCount();

};
#endif
