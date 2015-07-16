#ifndef BRACKETSCHECKER_HPP
#define BRACKETSCHECKER_HPP

#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::string;
using std::stack;

class BracketsChecker{
    private:
        int getBracketIndex(char textEl, char brackets[], int length);
        int getLeftBracketIndex(char textEl);
        int getRightBracketIndex(char textEl);
        int getSameBracketIndex(char textEl);
        bool isCorrectRight(char leftBracket, char rightBracket);
        bool isCorrectPairs(stack<char> &foundLeftBracketsStack, char rightBracket);
        bool checkSamePairs(stack<char> &foundLeftBracketsStack, char bracket, int foundIndex);
    public:
        bool isSequenceOfBracketsCorrect(const std::string& text);
        BracketsChecker();
        ~BracketsChecker();
};
#endif
