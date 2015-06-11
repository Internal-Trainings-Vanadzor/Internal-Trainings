#include <algorithm>


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
	        size_t openPosition =  example.find(mapOfSymbols["open"]);
	        size_t closePosition =  example.find(mapOfSymbols["close"]);
	        long openCount = std::count(example.begin(), example.end(), mapOfSymbols["open"]);
	        long closeCount = std::count(example.begin(), example.end(), mapOfSymbols["close"]);
	        if (openCount != closeCount) {
	            this->isCorrect = false;
	        }
	        if (openPosition < closePosition ){
		    example  =  example.erase(openPosition, 1);
		    example = example.erase(closePosition - 1,  1);
		    std::string s1 = example.substr(openPosition, closePosition - openPosition - 1);
		    std::string s2 = example.substr(closePosition + 1, example.length() - closePosition -1);
		    StructureParser::analyze(s1);
		    StructureParser::analyze(s2);
	       } else  {
	           if (openCount != 0){
		       this->isCorrect = false;
		   }
	       }
            }
        } 
    } catch (const std::out_of_range& oor) {
	this->isCorrect = false;
    }
    return this->isCorrect;
}

