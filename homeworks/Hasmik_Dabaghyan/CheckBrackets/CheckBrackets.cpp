#include <iostream>
#include "string.h"

using namespace std;
//Checks if the specific expression contains valid sequence of brackets.
bool checkBrackets(string expression)
{
    char brackets[] = {'{', '}','[', ']', '(', ')'};
    bool isValidSequence = true;
    for(int j = 0; j < 3; j++){
        int openingBracketsCount = 0;
        int closingBracketsCount = 0;
        for(int i = 0; i < expression.length(); i++)
        {
            if(expression.at(i) == brackets[j*2]){
                openingBracketsCount++;
            }
            if(expression.at(i) == brackets[j*2+1]){
                closingBracketsCount++;
            }
        }
        if(openingBracketsCount != closingBracketsCount){
            cout<<"Invald sequence of \""<< brackets[j*2]<<", "<< brackets[j*2+1]<<"\" brackets \n";
            isValidSequence = false;
        }
    }
    return isValidSequence;
}

int main()
{
    cout<<"Please enter an expression which contains {}[]() brackets:\n";
    string expression;
    cin>>expression;
    if(checkBrackets(expression))
    {
        cout<<"You have entered valid sequence of brackest. \n";
    }
    return 0;
}
