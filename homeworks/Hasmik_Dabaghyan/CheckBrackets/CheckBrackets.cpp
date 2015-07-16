#include <iostream>
#include <string>
#include <stack>

using namespace std;

// function checks if opening  bracket corresponds to the closing one
bool checkIfBracketsArePair(char opening, char closing)
{
    if(opening=='(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    else if(opening == '\'' && closing == '\'') return true;
    else if(opening == '"' && closing == '"') return true;
    return false;
}

//Checks if the specified expression contains valid sequence of brackets
bool checkBracketsValidation(string exp) 
{                                    
    stack<char> sequence;
    bool isQuote = false;
    for(int i = 0; i < exp.length(); i++){
        if(isQuote && !checkIfBracketsArePair(sequence.top(), exp[i])){
            return false;
        } else if(isQuote && checkIfBracketsArePair(sequence.top(), exp[i])) {
            sequence.pop();
            isQuote = false;
            continue;
        }  
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            sequence.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(sequence.empty() || !checkIfBracketsArePair(sequence.top(),exp[i]))
                return false;
            else
                sequence.pop();
        }
        else if((exp[i]=='\'' or exp[i]=='"') && !sequence.empty()){
            return false;
        } else if ((exp[i]=='\'' or exp[i]=='"') && sequence.empty()) {
            sequence.push(exp[i]);
            isQuote  = true;
        }
    }
    return sequence.empty() ? true:false;
}

int main()
{
    cout<<"Please enter an expression to check:\n";
    string expression;
    cin>>expression;
    if(checkBracketsValidation(expression))
    {
        cout<<":) You have entered valid sequence of brackest. \n";
    } else {
        cout<<":( You have entered invalid sequence of brackest. \n";
    }
    return 0;
}
