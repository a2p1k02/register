CC=gcc
CFLAGS=-Wall -ledit
SOURCES=src/main.c
EXECUTABLE=registration

all:
	mkdir -p build && cd build
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) 
	mv $(EXECUTABLE) build

run:
	./build/$(EXECUTABLE)

