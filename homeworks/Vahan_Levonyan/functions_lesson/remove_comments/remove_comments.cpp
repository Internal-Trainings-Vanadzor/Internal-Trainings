#include <iostream>
#include <fstream>
#include <vector>


bool isOpenComment(const std::vector<char>& vect) {
    return ( (vect[0] == '/') && (vect[1] == '/') ) ||
           ( (vect[0] == '/') && (vect[1] == '*') );
}


bool isLineComment(const std::vector<char>& vect) {
    return( (vect[0] == '/') && (vect[1] == '/') && (vect.back() == '\n') );
}

bool isBlockComment(const std::vector<char>& vect) {
    return ( (vect[0] == '/') && (vect[1] == '*') &&
            (vect[vect.size() - 1] == '/') && (vect[vect.size() - 2] == '*') );
}

void writeToFile(std::vector<char>& content, std::ifstream& infile, std::ofstream& outfile) {
    char* buffer = new char[content.size()];
    infile.seekg (-content.size(), infile.cur);
    infile.read (buffer,content.size());
    outfile.write (buffer,content.size());
    delete[] buffer;
    content.clear();
}
int main()
{
    std::ifstream inputFile;
    std::ofstream noCommentFile;
    std::ofstream commentFile;
    
    inputFile.open ("code_with_comments.txt", std::ios::in | std::ios::binary);
    commentFile.open ("comments.txt", std::ios::out | std::ios::trunc | std::ios::binary);
    noCommentFile.open ("no_comments.txt", std::ios::out | std::ios::trunc | std::ios::binary);
    char ch;
    std::vector<char> fragment;
    if (inputFile.is_open()) {
        while(!inputFile.eof())
        {
            inputFile.get(ch);
            fragment.push_back(ch);

            if( isBlockComment(fragment) || isLineComment(fragment)) {
                writeToFile(fragment, inputFile, commentFile);
            }

            else if( (!isOpenComment(fragment)) && 
                    (ch != '/') && 
                    (ch != '*') && 
                    (ch != '\n') ) {
                writeToFile(fragment, inputFile, noCommentFile);
            }
            else {
                continue;
            }
        }
    }
    else {
        std::cout <<"Unable to open the file...";
    }

    commentFile.close();
    noCommentFile.close();
    inputFile.close();
    return 0;
}
