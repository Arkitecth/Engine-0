CC= g++
CFLAGS= -std=c++14 
EXECUTABLE= main
ENGINE_SRC= .
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp')


test:
	$(CC) $(CFLAGS) $(FILES) -o $(EXECUTABLE) 


