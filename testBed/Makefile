CC= g++
INCDIR= -I../engine
LINKDIR= -L../engine
CFLAGS:= -std=c++17 -Wall -g
CFLAGS += -Wl,-rpath,@executable_path/../engine
ENGINE_SRC= ./
LIBS = -lengine
EXECUTABLE= test 
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp') 

.PHONY: all clean

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(FILES) $(INCDIR) $(LINKDIR) $(LIBS) -o main 

clean:
	rm -rf main 
