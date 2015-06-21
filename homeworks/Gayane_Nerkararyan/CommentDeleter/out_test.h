#ifndef MY_CLASS_COUNTER_H
#define MY_CLASS_COUNTER_H

class my_class_counter
{
private:
static int m_count;
public:
my_class_counter();

my_class_counter(my_class_counter&);

~my_class_counter();

static const int get_count();
};

#endif
