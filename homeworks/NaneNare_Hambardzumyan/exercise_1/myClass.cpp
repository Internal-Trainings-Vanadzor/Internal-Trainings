#include <iostream>

class MyClass {
    private:
        static unsigned int counter ;

    public:
        static int getInstenceCount() {
            return counter;
        }

        MyClass() {
            counter++;
        }

        MyClass(const MyClass& arg) {
            counter++;
        }

        ~MyClass() {
            counter--;
        }

};

unsigned int MyClass::counter = 0;

int main() {
    MyClass obj1;
    std::cout << "Count is " << MyClass::getInstenceCount() << std::endl; 

    MyClass* array = new MyClass [99] ;
    std::cout << "Count is " << MyClass::getInstenceCount() << std::endl; 
    for (int i = 0; i < 99; ++i) {
        array[i].~MyClass();
    }
    std::cout << "Count is " << MyClass::getInstenceCount() << std::endl; 
    return 0;
}
