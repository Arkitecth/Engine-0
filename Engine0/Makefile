CC= g++

CFLAGS:=-std=c++17 -fPIC -dynamiclib -install_name '@rpath/libengine0.dylib' -Wall -g

LIB_NAME=libengine0.dylib

MAC_DEBUG_SYMBOLS=$(LIB_NAME).dSYM

LIBS=-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

LIBS+=`pkg-config --libs sdl3`

CFLAGS+=`pkg-config --cflags sdl3`

CFLAGS+=-I/opt/local/include

ENGINE_SRC= ./

FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp')

$(LIB_NAME):
	$(CC) $(CFLAGS) $(FILES) $(LIBS) -o $(LIB_NAME) 

clean:
	rm -rf $(LIB_NAME) $(MAC_DEBUG_SYMBOLS)


