AUTHOR: Armenuhi 
GOALS: Investigate standard structures
DIRECTORY STRUCTURE: 
	List/
		interfaceList.h -> interface List functionality
		implementationList.pp -> implementation List functionality
		Node.h -> Structure to List
		run.cpp
		listUnittest.cc -> google tests for List
USEAG:
	cd List directory
	build run.cpp
		g++ -std=c++11 run.cpp -o out
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
            g++ -I /usr/include listUnittest.cc implementationList.cpp /usr/lib/libgtest_main.a -lgtest -lpthread -o mytest -std=c++11
        run
          ./mytest

//TBD add tests for checking all functionality
