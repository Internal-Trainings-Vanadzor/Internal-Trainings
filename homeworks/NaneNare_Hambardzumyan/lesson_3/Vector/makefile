vector: vector.o
	@g++ $^ -o $@

vector.o: main.cpp vector.h
	@g++ -c $< -o $@

clear:
	@rm *.o vector
