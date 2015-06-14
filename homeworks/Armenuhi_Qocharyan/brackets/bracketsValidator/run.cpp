#include "interfaceStructureParser.h"
#include "implementationStructureParser.h"

//TODO Need to implement functionality to parse command line arguments 

int main() 
{
    std::string myString = "test";
    StructureParser test = StructureParser();
    bool t = test.analyze(myString);
    std::cout <<"true "<<t<<"\n";
    myString = "t[{t}t]test";
    t = test.analyze(myString);
    std::cout <<"true "<<t<<"\n";
    myString = "{[r}m]test";
    t = test.analyze(myString);
    std::cout <<"false "<<t<<"\n";
    return 0;
}
