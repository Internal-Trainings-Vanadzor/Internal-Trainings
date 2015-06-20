#ifndef OBJECTSCOUNTER_HPP
#define OBJECTSCOUNTER_HPP

#include <limits>
#include <iostream>

class Counter{
    private:
            static unsigned int m_objects_count;

    public:
        Counter();
        
        Counter( Counter& counterObj);
        
        ~Counter();

        static unsigned int getObjectsCount();

};
#endif
