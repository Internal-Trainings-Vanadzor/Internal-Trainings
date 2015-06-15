#include <iostream>
#include <string>
#include <stack>

using namespace std;

static bool isBracketsCorrect(char openedBracket, char closedBracket){	   
    if ((openedBracket=='{' && closedBracket =='}') || 
            (openedBracket=='[' && closedBracket==']') ||
            (openedBracket=='"' && closedBracket=='"') ||
            (openedBracket=='\'' && closedBracket=='\'') ||
            (openedBracket=='(' && closedBracket ==')')){
        return true;
    }else{
        return false;
    }
}

static bool isBracketsSequenceCorrect(string expression){
    int expLength = expression.length();
    stack<char> brackets;
    bool isSingleApostrophe=false;
    bool isDoubleApostrophe=false;
    for (int i=0; i<expLength; i++){
        char symbol = expression.at(i);
        switch(symbol) {
            case '{': case '(': case '[':
                brackets.push(symbol);
                break;
            case '}': case ')': case ']':
                if (brackets.empty() || !isBracketsCorrect(brackets.top(), symbol)) {
                    return false;
                }
                brackets.pop();
                break;
            case '\'':
                if (brackets.empty() || !isBracketsCorrect(brackets.top(), symbol)) {
                    if (isSingleApostrophe) {
                        return false;
                    } else {
                        brackets.push(symbol);
                        isSingleApostrophe = true;
                    }	
                } else {
                    brackets.pop();
                    isSingleApostrophe = false;
                }
                break;	   
            case '"':
                if (brackets.empty() || !isBracketsCorrect(brackets.top(), symbol)) {
                    if (isDoubleApostrophe) {
                        return false;
                    } else {
                        brackets.push(symbol);
                        isDoubleApostrophe = true;
                    }
                } else {
                    brackets.pop();
                    isDoubleApostrophe = false;
                }
                break;
        }
    }
    return brackets.empty();
}

int main (){
    string  expression; 
    cout<<"Input an expression containing brackets: ";
    cin>>expression;

    if (isBracketsSequenceCorrect(expression)) {
        cout<<"The order of the brackets is correct \n";
    } else {
        cout<<"The order of the brackets is incorrect \n" ;    
    }
    return 0;
}
