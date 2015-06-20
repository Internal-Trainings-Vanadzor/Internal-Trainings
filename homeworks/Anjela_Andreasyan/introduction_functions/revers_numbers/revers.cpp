#include <iostream>
using std::cout;

static unsigned int reverse (unsigned int number){
    static unsigned int reversedNumber=0;
    if (number == 0){
        return reversedNumber;
    } else{
        reversedNumber = reversedNumber * 10 + number % 10;
        reverse(number/10);
    }
}

int main(){
    unsigned int number = 123456;
    cout<<"Number to reverse: "<<number<<"\n";
    cout<<"Reversed number\t"<<reverse(number)<<"\n";
    return 0;
}
