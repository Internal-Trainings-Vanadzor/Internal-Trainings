shared_ptr: main.o
	@g++ $^ -o $@

main.o: main.cpp shared_ptr.h
	@g++ -c $< -o $@

clean:
	rm *.o shared_ptr
