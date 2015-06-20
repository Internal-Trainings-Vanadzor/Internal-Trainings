#include "interfaceRemoveComments.h"

RemoveComments::RemoveComments(std::string fileName) { 
    this->fileName = fileName;
}

void RemoveComments::remove(std::string symbolLine) {
    std::ifstream file(this->fileName);
    std::string fileContents = "";
    std::string line;
    if (file) {
    	while (std::getline(file, line))
        {
	    size_t position = line.find(symbolLine);
	    if (position != std::string::npos) {
	        line = line.substr(0, position);
	    }
            fileContents += line + "\n";
        }
        std::cout << fileContents << "\n";
    //writeInFile TBD
    } else {
	std::cout << "Incorrect " + this->fileName + " file "<< "\n";
    }
}

//TBD remove comments from block
void RemoveComments::remove(std::string openSymbolBlock, std::string closeSymbolBlock) {
}

RemoveComments::~RemoveComments() {
}
