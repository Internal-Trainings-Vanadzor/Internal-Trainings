validator: validation.o
	@g++ $^ -o $@

validation.o: validation.cpp
	@g++ -c $< -o $@

clean:
	rm *.o validator
