#include <iostream>
#include <string>
using namespace std;

bool isBracketsCorrect(string brackets){
    int bLength = brackets.length();
    if (bLength%2 != 0){
        return false;
    }
    for (int i=0; i<bLength/2; i++){
        if ((brackets.at(i)=='{' && brackets.at(bLength-i-1)=='}')|| (brackets.at(i)=='[' && brackets.at(bLength-i-1)==']') || (brackets.at(i)=='(' && brackets.at(bLength-i-1)==')')){
            return true;
    }else{
        return false;
    }
    }
}

int main (){
    string  brackets;    
    cout<<"Input an expression containing brackets: ";
    cin>>brackets;
    if(isBracketsCorrect(brackets)){
        std::cout<<"The order of the brackets is correct \n";

    }
    else{
        std::cout<<"The order of the brackets is incorrect \n";
        
    }
    return 0;
}
