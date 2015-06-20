#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

static string removeTextInQuotes(string line){
size_t found1, found2;
size_t found=line.find('\"');
	while(found!=string::npos){
		found1=line.find('\"');
		found2=line.find('\"', found1+1);
		for (int i=found1; i<=found2; i++){
			line.replace(i,1,"#");
		}
	found=line.find('\"');
	}
	return line;
}

static string removeLineComment(string line){
	string tempLine;  size_t index; size_t blockCommentInLine=line.find("/*");
	tempLine = removeTextInQuotes(line);
		if (blockCommentInLine!=string::npos){
			while(tempLine.find("/*") != string::npos) {cout<<"while";

				tempLine.erase(tempLine.find("/*"),2); tempLine.erase(tempLine.find("*/"),2);
				index = line.find("/*");
        	         	line.erase(index, (line.find("*/", index) - index)+2);
			}
		}
		tempLine = removeTextInQuotes(line);
		index=tempLine.find("//");
		if (index!=string::npos){					
			line = line.erase(index, line.find("\n", index) - index);
		}
return line;	
}

int main(){

	vector<string> lines;	
	string line;

	ifstream file;
	file.open ("Code.txt");	
    
	while (getline(file, line))
	{
		size_t lineComment=line.find("//");		
		if (lineComment!=string::npos){
			if (lineComment!=0){	
				line = removeLineComment(line);
				lines.push_back(line);
				
			} 
		}else {lines.push_back(line);}
	}

	file.close();
	ofstream myfile;
	myfile.open ("Code.txt");
	int looper;
	for (looper = 0; looper < (int) lines.size(); looper++) {
		myfile << lines[looper] << endl;
	}

	myfile.close();
	return 0;
}
