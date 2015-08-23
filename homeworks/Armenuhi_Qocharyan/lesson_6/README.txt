AUTHOR: Armenuhi 
GOALS: 
    - Investigate standard structures' usages (array, vector, tree, list)
    - Investigate valuation of complications for standard structures(insert, delete, searchByIndex, searchByValue)
DIRECTORY STRUCTURE: 
    TBD
USAGE:
   ROBOT:
	generate .so lib from cpp
	    - g++ -fpic -m32 -c test.cpp
	    - g++ -m32 -shared test.o

ENVIRONMENT:
    install g++-multilib:
	sudo apt-get install install g++-multilib
 
// TBD Investigate issues related to building and running robot tests

