CC= g++
CFLAGS:= -std=c++17 -fPIC -dynamiclib -install_name '@rpath/libengine.dylib' -Wall -g
ENGINE_SRC= ./
EXECUTABLE= engine 
FILES= $(shell find $(ENGINE_SRC) -maxdepth 1 -name '*.cpp') 

.PHONY: all clean

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(FILES) -o libengine.dylib 

clean:
	rm -rf engine
