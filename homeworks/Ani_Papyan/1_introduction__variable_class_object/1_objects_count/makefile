program: main.o myClass.o
	@g++ $^ -o $@

main.o: main.cpp myClass.hpp
	@g++ -c $< -o $@

myClass.o: myClass.cpp myClass.hpp
	@g++ -c $< -o $@

clean:
	@rm -f *.o program
