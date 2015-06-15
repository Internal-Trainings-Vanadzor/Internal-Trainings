#include <iostream>
#include <string>
#include <stack>

using namespace std;

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

    cout<<"Input a number greater than 10 and less than 987654321: ";
    cin>>number;

    if (number/10 != 0){
        reversedNumber = reverseNumber(number);
        cout<<"The reversed number is "<<reversedNumber<<"\n";
    } else{
        cout<<"Incorrect input \n";	
    }
    return 0;
}
