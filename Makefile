CC=gcc
CFLAGS=-Wall -ledit
SOURCES=src/main.c
EXECUTABLE=registration
BUILD_DIR=build

all:
	mkdir -p $(BUILD_DIR) && cd
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) 
	mv $(EXECUTABLE) $(BUILD_DIR)

run:
	./build/$(EXECUTABLE)

clean:
	rm -rf $(BUILD_DIR)

