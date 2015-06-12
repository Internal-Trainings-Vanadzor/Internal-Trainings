#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBracketsCorrect(char openedBracket, char closedBracket){	   
    if ((openedBracket=='{' && closedBracket =='}') || 
            (openedBracket=='[' && closedBracket==']') ||
            (openedBracket=='(' && closedBracket ==')')){
        return true;
    }else{
        return false;
    }
}

bool isOpened(char openedBracket){
    if (openedBracket=='{'||openedBracket=='['||openedBracket=='(') {
        return true;
    } else {
        return false;
    }
}

bool isClosed(char closedBracket){
    if (closedBracket=='}'||closedBracket==']'||closedBracket==')') {
        return true;
    } else {
        return false;
    }
}

int main (){
    static string  expression; // I am not sure that having static 
    static bool k = true;      // variable is preferable approach
    static bool m = false;     // for these cases 	
    int expLength; 
    stack<char> brackets;

    cout<<"Input an expression containing brackets: ";
    cin>>expression;
    expLength = expression.length();
    for (int i=0; i<expLength; i++){
        char bufer = expression.at(i);
        if (isOpened(bufer)) {
            brackets.push(bufer);
            m = true;
        }else{
            if (isClosed(bufer)){
                if(!brackets.empty()){
                    if (isBracketsCorrect(brackets.top(), bufer)){				
                        brackets.pop();
                    }else{
                        k = false;					
                    }
                }
            }
        }			
    }

    if(k&&brackets.empty()&&m) {
        cout<<"The order of the brackets is correct \n";
    }else{
        cout<<"The order of the brackets is incorrect \n" ;        
    } 
    return 0;
}
