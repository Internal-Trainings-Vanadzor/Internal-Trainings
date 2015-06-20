#include <fstream>
#include "implementationRemoveComments.h"

int main() 
{
    RemoveComments *a = new RemoveComments ("test");
    a->remove("//");
    return 0;
}
