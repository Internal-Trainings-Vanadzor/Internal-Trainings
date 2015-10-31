SOURCE=$(wildcard ./src/main/*.cpp)
HEADERS=./src/main/headers
CFLAGS=-I$(HEADERS) -std=c++0x
GEOMETRY=geometry

CC=g++

all: $(GEOMETRY)

$(GEOMETRY): $(SOURCE)

	$(CC) $(CFLAGS) $(SOURCE) -o$(GEOMETRY)

clean:

	rm -f $(GEOMETRY)

