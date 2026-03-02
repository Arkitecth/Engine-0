CC=g++
CFLAGS= -std=c++17 -Wall
INCDIR= -I../Engine0
LINKDIR= -L../Engine0
DYNAMIC_LIB_PATH=-Wl,-rpath,@executable_path/../Engine0
LIBS= -lengine0
LIBS+=-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
LIBS+=`pkg-config --libs sdl3`
CFLAGS+=`pkg-config --cflags sdl3`
EXECUTABLE= test
TEST_SRC = ./
FILES= $(shell find $(TEST_SRC) -maxdepth 1 -name '*.cpp')

.PHONY: all clean

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(FILES) $(INCDIR) $(LINKDIR) $(DYNAMIC_LIB_PATH) $(LIBS) -o main

clean: 
	rm -rf main



