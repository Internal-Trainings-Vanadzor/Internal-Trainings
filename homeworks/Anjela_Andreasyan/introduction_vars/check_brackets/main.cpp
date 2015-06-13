#include "bracketsChecker.hpp"
using std::cin;

int main(){
    string textToCheck;
    cout<<"Please input the text which brackets order you want to check:\t";
    cin>>textToCheck;
    BracketsChecker checker;
    checker.isSequenceOfBracketsCorrect(textToCheck);
    return 0;
}
