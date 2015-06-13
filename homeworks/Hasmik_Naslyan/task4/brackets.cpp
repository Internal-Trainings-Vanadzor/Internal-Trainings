#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBracketsCorrect(char openedBracket, char closedBracket){	   
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

bool isApostrophe(char isApostrophe){
    if (isApostrophe=='"'||isApostrophe=='\'') {
        return true;
    } else {
        return false;
    }
}

int main (){
    static string  expression; // I am not sure that having static 
    static bool isAvarenny = false;      // variable is preferable approach for these cases 	
    int expLength, i=0; 
    stack<char> brackets;

    cout<<"Input an expression containing brackets: ";
    cin>>expression;

    expLength = expression.length();

    while (!isAvarenny && i<expLength)  {
        char bufer = expression.at(i);
        
	if (isOpened(bufer)) {brackets.push(bufer);}
	if (isApostrophe(bufer)){
	 if ( brackets.empty() || !isBracketsCorrect(brackets.top(), bufer)){
		brackets.push(bufer);
	 }else {brackets.pop();}
	}
	if (isClosed(bufer)){
                if(!brackets.empty() && isBracketsCorrect(brackets.top(), bufer)){brackets.pop();}
		else{isAvarenny=true;}
	}
	i++;
    }
    if(isAvarenny || !brackets.empty()) {
        cout<<"The order of the brackets is incorrect \n";
    }else{
       cout<<"The order of the brackets is correct \n" ;        
    } 
    return 0;
}
