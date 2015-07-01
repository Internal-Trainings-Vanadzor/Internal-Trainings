//TDOD

AUTHOR: Armenuhi 
GOALS: Create mechanism for analyzing  brackets in the string, which need to opened and closed correctly
DIRECTORY STRUCTURE:
	README.txt/ This is README file :) 
	bracketsValidator/
		interfaceStructureParser.h -> interface StructureParser class
		implementationStructureParser.h -> implementation StructureParser class
		run.cpp //examples
	bracketsValidator/unitTests/
		//TODO: Need to investigate Google tests to run and write new unit tests.
		https://code.google.com/p/googletest/wiki/Primer
		https://code.google.com/p/googletest/
USEAGE:
	cd bracketsValidator/ directory
	build run.cpp
		g++ run.cpp -o out -std=c++11
	run out file
		./out
 
ENVIRONMENT:
    gtest-1.7.0
    Installation: //TBD Need to write script for installation gtest
         1. Get the googletest framework
             wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
	 2. Unzip and build google test
	     unzip gtest-1.7.0.zip
             cd gtest-1.7.0
             ./configure
             make
	3. Install
            sudo cp -a include/gtest /usr/include
            sudo cp -a lib/.libs/* /usr/lib/
        4. Update the cache of the linker and check implicitly if the GNU Linker knows the libs 
	    sudo ldconfig -v | grep gtest
            If the output looks like this:
                libgtest.so.0 -> libgtest.so.0.0.0
 	        libgtest_main.so.0 -> libgtest_main.so.0.0.0
	        everything is fine. :)

  
	

