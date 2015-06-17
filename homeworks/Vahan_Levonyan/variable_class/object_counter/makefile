all: create_cars

create_cars: main.o object_counter.o
	g++ main.o object_counter.o -o create_cars

main.o: main.cpp
	g++ -c main.cpp

create_cars.o: object_counter.cpp
	g++ -c object_counter.cpp

clean:
	rm *o create_cars
