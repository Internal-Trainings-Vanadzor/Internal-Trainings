#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream fileIn ("input.txt");
    ofstream fileOut ("output.txt");
    bool isCommentedLine = false;
    if (fileIn.is_open() && fileOut.is_open())
    {
        while (getline (fileIn, line))
        {
            if(line.at(0)=='/' and line.at(1)=='/')
            {
                continue;
            }
            if((line.at(0)=='/' and line.at(1)=='*'))
            {
                isCommentedLine = true;
                continue;
            } 
            if((line.at(line.length()-2) =='*') and line.at(line.length()-1)=='/')
            {
                isCommentedLine = false;
                continue;
            }
            if(!isCommentedLine)
            {
                fileOut<<line<<'\n';
                isCommentedLine = false;
            }
        }
        fileIn.close();
        fileOut.close();
    } else {
        cout << "Unable to open file"; 
    }
    cout<< "See the commented text in \"input.txt\" file "<<'\n';
    cout<< "See the uncommented text in \"output.txt\" file "<<'\n';
    return 0;        
}
