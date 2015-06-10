myClass: myClass.o
	@g++ $^ -o $@

myClass.o: myClass.cpp
	@g++ -c $< -o $@

clean:
	rm *.o myClass
