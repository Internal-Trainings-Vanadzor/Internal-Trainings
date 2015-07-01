#include <iostream>
#include <fstream>


void writeInFile(std::string fileName, std::string fileContent){
    std::ofstream file (fileName);
    if (file.is_open()) {
        file << fileContent;
        file.close();
    } else { 
        std::cout << "Unable to open" +  fileName + "file";
    }
}

/**
*This function removes comments from given file 
*
*/
void remove(std::string fileName, std::string symbolLine, std::string startSymbolBlock, std::string endSymbolBlock) {
    std::ifstream file(fileName);
    std::string fileCodeContents = "";
    std::string fileCommentsContents = "";
    std::string endSymbolLine = "\n";
    std::string line;
    std::string lineCode;
    std::string lineComments;
    if (file) {
	bool inBlock = false;
    	while (std::getline(file, line)) {
	    lineComments = "";
	    lineCode = ""; 
	    while(line != "")  {
		if (inBlock) {
	            size_t positionBlockEnd = line.find(endSymbolBlock);
		    if (positionBlockEnd != std::string::npos) {
		        lineComments += line.substr(0, positionBlockEnd);
			line = line.substr(positionBlockEnd + endSymbolBlock.length(), line.length());
			inBlock = false;
		    } else {
                        lineComments = line;
                        line = "";
		    }
		}
                size_t positionSymbolLine = line.find(symbolLine);
	        size_t positionSymbolBlock = line.find(startSymbolBlock);
	        size_t positionStartString = line.find("\"");
		if (positionSymbolLine == std::string::npos && positionSymbolBlock == std::string::npos && positionStartString == std::string::npos){
		   lineCode += line;
		   line = "";
		} else {
	                if ((positionStartString < positionSymbolLine || positionSymbolLine ==  std::string::npos) && (positionStartString < positionSymbolBlock || positionStartString == std::string::npos) && positionStartString != std::string::npos) {
	                    size_t positionEndString = line.substr(positionStartString + 1, line.length()).find("\"");
	                    if (positionEndString != std::string::npos) {
	                        lineCode += line.substr(0, positionEndString + positionStartString + 2);
	            	        line = line.substr(positionEndString + positionStartString + 2, line.length() - -positionEndString - positionStartString - 2);
	                } 
	            } else {
	                if (positionSymbolLine != std::string::npos && positionSymbolLine < positionSymbolBlock) {
	                    lineComments = line.substr(positionSymbolLine + symbolLine.length(), line.length() - positionSymbolLine - symbolLine.length());
	                    lineCode += line.substr(0, positionSymbolLine);
	            	    line = "";
	                }  else {
	            positionSymbolLine = lineCode.find(startSymbolBlock);
                    if (positionSymbolBlock != std::string::npos && !inBlock) {
			lineCode += line.substr(0, positionSymbolBlock);
			line = line.substr(positionSymbolBlock + startSymbolBlock.length(), line.length() - positionSymbolBlock - startSymbolBlock.length());
                        inBlock = true;
	            }
		   }
		    if (line.find(endSymbolBlock) == std::string::npos){
		      lineComments += "\n";
		    }
		}
            }
	}
            fileCodeContents += lineCode + "\n";
	    fileCommentsContents += lineComments + "\n";
     }
	writeInFile("Comments.txt", fileCommentsContents);
	writeInFile("Code.txt", fileCodeContents);
     	file.close ();
    } else {
	std::cout << "Incorrect " + fileName + " file "<< "\n";
    }
}


int main() 
{
    remove("test","//", "/*", "*/");
    return 0;
}
