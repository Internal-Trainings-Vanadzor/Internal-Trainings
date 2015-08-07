AUTHOR: Armenuhi 
GOALS: Investigate standard structures - Binary Tree 
DIRECTORY STRUCTURE: 
	BinaryTree/
		BinaryTree.h -> interface of tree
		BinaryTree.cpp -> implementation of tree
		Node.h -> Structure to tree
		BinaryTreeUnittest.cc -> google tests for Binary Tree
USAGE:
	cd BinaryTree/ directory
	build // TBD
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

 
BUILD/RUN GOOGLE TESTS
	build
	    g++ -I /usr/include  BinaryTreeUnittest.cc BinaryTree.cpp /usr/lib/libgtest_main.a -lgtest -lpthread -o mytest -std=c++1
        run
          ./mytest

//TBD add tests for checking all functionality

GENERATE DOC
	1. install doxygen 
		sudo apt-get install doxygen
	2. Generate doc
		doxygen BinaryTree.h
	3. open index.html
		${path_BinaryTreeDir}/html/index.html
