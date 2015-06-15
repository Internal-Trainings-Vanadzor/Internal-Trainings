#include <iostream>

static long int reverseNumber(int number){
    static long int revNumber=0; 
    revNumber = revNumber*10+number%10;   
    if (number/10 == 0){
        return revNumber;
    } else {	
        reverseNumber(number/10);
    }
}

//The following case should be investigated
/*
static double reverseNumber(int number){
    static double revNumber=0; 
    revNumber = revNumber*10+number%10;   
    if (number/10 == 0){
        return revNumber;
    } else {	
        reverseNumber(number/10);
    }
}
*/

int main(){
    int number; long int reversedNumber;

    std::cout<<"Input a number greater than 10 and less than 987654321: ";
    std::cin>>number;

    if (number/10 != 0){
        reversedNumber = reverseNumber(number);
        std::cout<<"The reversed number is "<<reversedNumber<<"\n";
    } else{
        std::cout<<"Incorrect input \n";	
    }
    return 0;
}
