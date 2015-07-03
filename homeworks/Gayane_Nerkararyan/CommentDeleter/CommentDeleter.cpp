#include<iostream>
#include <fstream>
#include<string>

std::string trim(const std::string& str, const std::string& whitespace = " \t");
int main()
{
	std::ifstream infile;
	std::string filename;
	std::string my_str,str;
	std::ofstream outfile;
	std::string::iterator it;

	std::cout << "Please enter name of the file: ";
	std::cin >> filename;

	infile.open(filename.c_str());
	outfile.open(("out_"+filename).c_str());

	if (infile.is_open())
	{
		bool commented_line = false;
		const std::string& whitespace = " \t";
		while(!infile.eof())
		{		
			std::getline(infile,my_str);
			str = trim(my_str,whitespace);
			
			if(str[0] == '/' && str [1] == '/' )
			{
				commented_line = true;
			}
			else if(str[0] == '/' && str [1] == '*')
			{
				commented_line = true;
			}					
			else if(str.length() != 0 && str[str.length()-1] == '/' && str[str.length()-2] == '*')
			{
				commented_line = true;
			} else {
				commented_line = false;
			}
			if(!commented_line)
			{
				outfile << str << '\n';
				commented_line = false;
			}
		}	
		infile.close();
		outfile.close();
	}
system("pause");
return 0;
}

std::string trim(const std::string& str,const std::string& whitespace)
{
    const int strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const int strEnd = str.find_last_not_of(whitespace);
    const int strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
