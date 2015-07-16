#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void remove_comments(ifstream source_file, string line_comment, string block_opening_comment, string block_closing_comment){
	string line;

	getline(source_file, line, '\0');
	while(line.find(line_comment) != string::npos) {
        size_t founded_comment = line.find(line_comment);
        line.erase(founded_comment, line.find("\n", founded_comment) - founded_comment);
    }

	while(line.find(block_opening_comment) != string::npos) {
        size_t founded_comment = line.find(block_opening_comment);
        line.erase(founded_comment, (line.find(block_closing_comment, founded_comment) - founded_comment) + block_closing_comment.length());
    }
  
	ofstream output;
	output.open ("file_without_comments.txt"); 
	output << line <<"\n";
	output <<"\n";
}

int main(void) {
	ifstream input_file("counter.cpp");
	remove_comments(input_file, "//", "/*", "*/");
	cout << "File is generated without comments." << endl;
    return 0;
}