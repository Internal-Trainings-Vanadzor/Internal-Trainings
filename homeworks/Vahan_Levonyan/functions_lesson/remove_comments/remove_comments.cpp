#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
bool isLineComment(std::vector<char> vect) {
    return (vect[0] == '/') && (vect[1] == '/');
}

bool isBlockComment(std::vector<char> vect) {
    return (vect[0] == '/') && (vect[1] == '*');
}


int main()
{
    std::ifstream fin;
    fin.open("code_with_comments.txt", std::ios::in);

    char ch;
    std::vector<char> comment;
    std::string close_block = "*/";


    while(!fin.eof())
    {
        fin.get(ch);
        comment.push_back(ch);
        if(ch != '/' && ch != '*'){
            comment.pop_back();      
        } else if(isBlockComment(comment)){
            std::cout << "block comment" << std::endl;
            comment.erase (comment.begin(), comment.begin()+2);
          //  std::cin.ignore(256, std::stoi(close_block);
        } else if(isLineComment(comment)){
            std::cout << "line comment" << std::endl;
            comment.erase (comment.begin(), comment.begin()+2);
            //fin.putback(ch);
            fin.ignore(/*std::numeric_limits<std::streamsize>::max()*/256, '\n');
            fin.get(ch);
        }
        std::cout << ch;
    }


    return 0;
}
