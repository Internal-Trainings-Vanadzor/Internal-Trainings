#ifndef Brackets
#define Brackets
#include <iostream>
#include <string>
#include <map>


//This class  for analyzing  brackets in the string, which need to opened and closed correctly
class StructureParser { 

	private: bool isCorrect;
	
	public: StructureParser();
	
	//Analyze the following brackets:
		// {}, [], '', ""
	public: bool analyze(std::string myString);
	
};


#endif
