auto_ptr: main.o
	@g++ $^ -o $@

main.o: main.cpp auto_ptr.h
	@g++ -c $< -o $@

clean:
	rm *.o auto_ptr
