#include <iostream>
#include <fstream>
#include <vector>


bool isOpenLineComment(std::vector<char> vect) {
    return (vect[0] == '/') && (vect[1] == '/');
}

bool isOpenBlockComment(std::vector<char> vect) {
    return (vect[0] == '/') && (vect[1] == '*');
}

bool isLineComment(std::vector<char> vect) {
    return( (vect[0] == '/') && (vect[1] == '/') && (vect.back() == '\n') );
}

bool isBlockComment(std::vector<char> vect) {
    return ( (vect[0] == '/') && (vect[1] == '*') &&
            (vect[vect.size() - 1] == '/') && (vect[vect.size() - 2] == '*') );
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

            if( isBlockComment(fragment) ){
                char* buffer = new char[fragment.size()];
                inputFile.seekg (-fragment.size(), inputFile.cur);
                inputFile.read (buffer,fragment.size());
                commentFile.write (buffer,fragment.size());
                delete[] buffer;
                fragment.clear();
            }

            else if( isLineComment(fragment) ){
                char* buffer = new char[fragment.size()];
                inputFile.seekg (-fragment.size(), inputFile.cur);
                inputFile.read (buffer,fragment.size());
                commentFile.write (buffer,fragment.size());
                delete[] buffer;
                fragment.clear();
            }
            else if( (!isOpenLineComment(fragment)) && (!isOpenBlockComment(fragment))
                    && (ch != '/') && (ch != '*') && (ch != '\n') ){
                char* buffer = new char[fragment.size()];
                inputFile.seekg (-fragment.size(), inputFile.cur);
                inputFile.read (buffer,fragment.size());
                noCommentFile.write (buffer,fragment.size());
                delete[] buffer;
                fragment.clear();
            }
            else {
                std::cout << "test";
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
