//Author: Naira
#include <iostream>

int invertNumber(int i_tiv){	

    static int i_invertNumber = 0; 
    if (i_tiv==0){return i_invertNumber;}
    i_invertNumber = i_invertNumber * 10 + i_tiv % 10;	
    invertNumber(i_tiv/10);

}

int main(){

    int i_inputNumber;
    std::cout << "Please input the number ..." <<'\n';
    std::cin >> i_inputNumber;
    int i_outputNamber=invertNumber(i_inputNumber);
    std::cout << "Results :  " <<i_outputNamber<<'\n';
    return 0;
}
