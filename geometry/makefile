SOURCE=$(wildcard ./src/main/*.cpp)
HEADERS=./src/main/headers
CFLAGS=-I$(HEADERS) -std=c++0x
MYPROGRAM=geometry

CC=g++

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)

	$(CC) $(CFLAGS) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)

