CC= g++
CFLAGS:= -std=c++17 -Wall -g
ENGINE_SRC= ./
EXECUTABLE= engine 
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp') 

.PHONY: all clean

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(FILES) -o engine

clean:
	rm -rf engine
