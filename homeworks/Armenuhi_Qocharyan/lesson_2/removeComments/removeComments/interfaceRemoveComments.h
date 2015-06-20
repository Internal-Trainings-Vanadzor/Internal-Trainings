#include <iostream>

class RemoveComments { 
	
	public: RemoveComments(std::string fileName);
	
	private: std::string fileName;
	
	public: void remove(std::string symbolLine);
	
	public: void remove(std::string openSymbolBlock, std::string closeSymbolBlock);
	
	public: ~RemoveComments();
	
};

