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
	        long openCount = std::count(example.begin(), example.end(), mapOfSymbols["open"]);
	        long closeCount = std::count(example.begin(), example.end(), mapOfSymbols["close"]);
	        if (openCount != closeCount) {
	            this->isCorrect = false;
		    return this->isCorrect;
		}
	        size_t openPosition =  example.find_last_of(mapOfSymbols["open"]);
		std::string ex2 = example.substr(openPosition +1, example.length()-openPosition);
	        if (openPosition > example.length()) {
			break;
		}
		std::string a= example.substr(openPosition, example.length()-openPosition);
		size_t closePosition =  a.find(mapOfSymbols["close"]) + openPosition; 
	        if (openPosition < closePosition ){
		    std::string s1 = example.substr(openPosition +1, closePosition - openPosition -1);
		    std::string fierstPart =  example.substr(0,openPosition);
		    std::string lastPart =  ex2.substr(ex2.find(mapOfSymbols["close"]) + 1,  ex2.length() - ex2.find(mapOfSymbols["close"]));
		    std::string s2 = fierstPart + lastPart;
		    StructureParser::analyze(s1);
		    StructureParser::analyze(s2);
	       } else  {
	           if (openCount != 0){
		       this->isCorrect = false;
		       return this->isCorrect;
		   }
	       }
            }
        } 
    } catch (const std::out_of_range& oor) {
	this->isCorrect = false;
        return this->isCorrect;
    }
    return this->isCorrect;
}

