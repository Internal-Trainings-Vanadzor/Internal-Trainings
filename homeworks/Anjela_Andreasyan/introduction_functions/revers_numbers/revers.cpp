#include <iostream>
using std::cout;

namespace {
    unsigned int myReverse (unsigned int number, unsigned int reversedNumber){
        if (number < 10){
            return reversedNumber*10 + number;
        } else{
            return myReverse(number /10, reversedNumber*10 + number %10);
        }
    }
}

unsigned int reverse (unsigned int number){
    return myReverse(number,0);
}

static unsigned int reverse_human_way(unsigned int number){
    unsigned int reversedNumber=0;
    while (number !=0){
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10;
    }
    return reversedNumber;
}

int main(){
    unsigned int number = 123456;
    cout<<"Number to reverse: "<<number<<"\n";
    cout<<"Reversed number\t"<<reverse(number)<<"\n";
    cout<<"Reversed number\t"<<reverse_human_way(number)<<"\n";
    cout<<"Reversed number\t"<<reverse_human_way(987654321)<<"\n";
    cout<<"Reversed number\t"<<reverse(987654321)<<"\n";
    return 0;
}
