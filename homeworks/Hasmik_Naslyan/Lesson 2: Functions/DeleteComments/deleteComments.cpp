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

int main(){

	vector<string> lines;	
	string line;

	ifstream file;
	file.open ("Code.txt");	
    
	while (getline(file, line))
	{
		size_t found=line.find("//");
		if (found!=string::npos){
			if (found!=0){
				string tempLine = removeTextInQuotes(line);
				size_t index=tempLine.find("//");
				if (index!=std::string::npos){
					
				line = line.erase(index, line.find("\n", index) - index);
				}
				lines.push_back(line);
				
			} 			
		} else {
			lines.push_back(line);
		}
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
