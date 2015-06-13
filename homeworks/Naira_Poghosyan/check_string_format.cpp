//Authors: Tamara & Naira
#include <iostream>
#include <string>
#include <stdlib.h>

std::string s_input_text;
void check_brackets(char c_symbol, int i_pos){
	for (int k = i_pos; k < s_input_text.length(); ++k){
		if (s_input_text[k] == ')' || s_input_text[k] == '}' || s_input_text[k] == ']' || s_input_text[k] == '"' || s_input_text[k] == '\''){
			if(s_input_text[k] == c_symbol){
				s_input_text[k]='0';
				s_input_text[i_pos]='0';
		    	break;
			}else{
				std::cout<<"Opss! :( The brackets format is not correct!"<<'\n';
				exit(1);
			}
		}
	}
}

int main(){
	
	std::cout<< "Please input the text ..." <<'\n';
	std::cin>> s_input_text;
   	for (int i = s_input_text.length(); i >= 0; --i){
		if(i==0 && s_input_text.length()!=1){
			std::cout<<"The brackets format is correct :)"<<'\n';
		}		
	    switch (s_input_text[i]){
			case '(':
				check_brackets(')',i);break;
			case '{':
				check_brackets('}', i);break;
			case '[':
				check_brackets(']', i);break;
			case '"':
				check_brackets('"', i); break;
			case '\'':
				check_brackets('\'', i); break;
		}
	}
	return 0;
}
