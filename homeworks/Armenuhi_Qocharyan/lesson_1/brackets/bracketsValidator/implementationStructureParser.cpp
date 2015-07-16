#include <algorithm>
#include "interfaceStructureParser.h"


StructureParser::StructureParser() {
	this->isCorrect = true;
}


// TBD split function to logic parts
bool StructureParser::analyze(std::string  example) {
    std::map<std::string, char> elements [] = {
        {	
            {"open", '{'},
            {"close", '}'}
        }, 
        {	
            {"open", '['},
            {"close", ']'}
        }, 
        {	
            {"open", '"'},
            {"close", '"'}
        }, 
        {	
            {"open", '\''},
            {"close", '\''}
        } 
    };
    auto arrayLength = end(elements) - begin(elements);
    try {
        for(int i = 0; i < arrayLength; i++){
	    std::map<std::string, char> mapOfSymbols = elements[i];
	    for(std::map<std::string, char>::const_iterator 
	        it = mapOfSymbols.begin(); it != mapOfSymbols.end(); ++it) {
	        long openCount = std::count(example.begin(), example.end(), mapOfSymbols["open"]);
	        long closeCount = std::count(example.begin(), example.end(), mapOfSymbols["close"]);
		if (openCount == 0 && closeCount == 0) {
		    break;
                }
	        if (openCount != closeCount && (mapOfSymbols["open"] == '{' || mapOfSymbols["open"] == '[') || openCount % 2 != 0 && (mapOfSymbols["open"] == '\'' || mapOfSymbols["open"] == '"')) {
	            this->isCorrect = false;
		    return this->isCorrect;
		}
		size_t openPosition = - 1;
		std::string partOne;
		if (mapOfSymbols["open"] == '\'' || mapOfSymbols["open"] == '"') {
	            openPosition =  example.find(mapOfSymbols["open"]);
		    partOne = example.substr(openPosition, example.length()-openPosition);
		} else {
	            openPosition =  example.find_last_of(mapOfSymbols["open"]);
		    partOne = example.substr(openPosition, example.length()-openPosition);
		}
		std::string partTow = example.substr(openPosition, example.length()-openPosition);
	        if (openPosition > example.length()) {
			break;
		} 
		size_t closePosition =  partOne.find(mapOfSymbols["close"]) + openPosition ; 
	        if (openPosition < closePosition ){
		    std::string s1 = example.substr(openPosition + 1, closePosition - openPosition - 1);
		    std::string firstPart =  example.substr(0,openPosition);
		    std::string lastPart =  partTow.substr(partTow.find(mapOfSymbols["close"]) + 1,  partTow.length() - partTow.find(mapOfSymbols["close"]));
		    std::string s2 = firstPart + lastPart;
		    StructureParser::analyze(s1);
		    StructureParser::analyze(s2);
	       } 
            }
        } 
    } catch (const std::out_of_range& oor) {
	this->isCorrect = false;
        return this->isCorrect;
    }
    return this->isCorrect;
}

