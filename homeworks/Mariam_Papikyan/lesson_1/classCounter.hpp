#ifndef CLASS_COUNTER
#define CLASS_COUNTER

class classCounter{
private:
    static int count;
    
public:
    classCounter();
    classCounter(const classCounter& counter);
    ~classCounter();
    static int getObjectsCount();
};

#endif