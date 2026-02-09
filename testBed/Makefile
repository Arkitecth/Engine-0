CC= g++
CFLAGS:= -std=c++17 -Wall -g
ENGINE_SRC= ./
EXECUTABLE= test 
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp') 

.PHONY: all clean

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(FILES) -o main

clean:
	rm -rf main 
