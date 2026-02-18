CC= g++
CLAGS=-std=c++14 
EXECUTABLE=main
LIBS=-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
LIBS+=`pkg-config --libs sdl3`
CFLAGS+=`pkg-config --cflags sdl3`
CFLAGS+=-I/opt/local/include
ENGINE_SRC= .
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp')


test:
	$(CC) $(CFLAGS) $(FILES) $(LIBS) -o $(EXECUTABLE)  -g


