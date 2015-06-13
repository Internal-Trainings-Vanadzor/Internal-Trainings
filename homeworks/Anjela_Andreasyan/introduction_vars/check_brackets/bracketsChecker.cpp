#include "bracketsChecker.hpp"


const int NUMBER_OF_BRACKET_TYPES = 3;
const int NUMBER_OF_SAME_BRACKET_TYPES = 2;

char leftBrackets[NUMBER_OF_BRACKET_TYPES] = {'{','[','<'};
char rightBrackets[NUMBER_OF_BRACKET_TYPES] = {'}',']','>'};
char sameBrackets[NUMBER_OF_SAME_BRACKET_TYPES] = {'"','\''};

BracketsChecker::BracketsChecker(){
}
BracketsChecker::~BracketsChecker(){
}

int BracketsChecker::getBracketIndex(char textEl, char brackets[], int length){
    for(int i=0; i<length; i++){
        if (textEl == brackets[i]){
            return i;
        }
    }
    return -1;
}

int BracketsChecker::getLeftBracketIndex(char textEl){
    return getBracketIndex(textEl, leftBrackets, NUMBER_OF_BRACKET_TYPES);
}

int BracketsChecker::getRightBracketIndex(char textEl){
    return getBracketIndex(textEl, rightBrackets,NUMBER_OF_BRACKET_TYPES);
}

int BracketsChecker::getSameBracketIndex(char textEl){
    return getBracketIndex(textEl, sameBrackets,NUMBER_OF_SAME_BRACKET_TYPES);
}


bool BracketsChecker::isCorrectRight(char leftBracket, char rightBracket){
    int foundLeftIndex = getLeftBracketIndex(leftBracket);
    return rightBracket == rightBrackets[foundLeftIndex];
}

bool BracketsChecker::isCorrectPairs(stack<char> &foundLeftBracketsStack, char rightBracket){
    if (foundLeftBracketsStack.empty() || !isCorrectRight(foundLeftBracketsStack.top(),rightBracket)){
        cout<<"[Info] The brackets sequence is not correct, found a right bracket, but did not found the apropriate right bracket\n";
        return false;
    }else{
        foundLeftBracketsStack.pop();
        return true;
    }
}

void BracketsChecker::checkSamePairs(stack<char> &foundLeftBracketsStack, char bracket){
    if( foundLeftBracketsStack.empty() || (foundLeftBracketsStack.top() != bracket)){
        foundLeftBracketsStack.push(bracket);
    }else{
        foundLeftBracketsStack.pop();
    }

}

bool BracketsChecker::isSequenceOfBracketsCorrect(const std::string& text){
    stack<char> foundLeftBracketsStack;
    int textSize = text.size();
    for(int i=0; i<textSize; i++){
        int foundLeftIndex = getLeftBracketIndex(text[i]);
        if(foundLeftIndex != -1){
            foundLeftBracketsStack.push(text[i]);
        }else{
            int foundRightIndex = getRightBracketIndex(text[i]);
            if(foundRightIndex != -1){
                if(!isCorrectPairs(foundLeftBracketsStack, text[i])) return false;
            }else{
                int foundIndex = getSameBracketIndex(text[i]);
                if(foundIndex != -1){
                    checkSamePairs(foundLeftBracketsStack, text[i]);
                }
            }
        }
    }                                                                   
    if(!foundLeftBracketsStack.empty()){
        cout<<"[Info] There are some left brackets which does not have the apropriate right brackets\n";
        return false;
    }
    cout<<"[Info] Congradulations!!! The brackets sequence is correct\n";
    return true;
}

