program: main.o AutoPointer.o
	@g++ $^ -o $@

main.o: main.cpp AutoPointer.hpp
	@g++ -c $< -o $@

myClass.o: AutoPointer.cpp AutoPointer.hpp
	@g++ -c $< -o $@

clean:
	rm *.o program
