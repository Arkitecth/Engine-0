# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# You will need SDL3 (http://www.libsdl.org) which is still unreleased/unpackaged.

#CXX = g++
#CXX = clang++

EXE = editor 
IMGUI_DIR = ../../../imgui/
ENGINE_DIR= ../Engine0/

BIN = bin
#SDL_DIR = /opt/homebrew/Cellar/sdl3/3.4.0/
SOURCES = main.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += Editor.cpp
DYNAMIC_LIB_PATH=-Wl,-rpath,@executable_path/../Engine0
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl3.cpp $(IMGUI_DIR)/backends/imgui_impl_sdlrenderer3.cpp
LIBS = -lengine0
OBJS =  $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)
LINUX_GL_LIBS = -lGL
CXXFLAGS = -std=c++17 -I$(IMGUI_DIR) -I$(ENGINE_DIR) -I$(IMGUI_DIR)/backends 
CXXFLAGS += -g -Wall -Wformat

##---------------------------------------------------------------------
## OPENGL ES
##---------------------------------------------------------------------

## This assumes a GL ES library available in the system, e.g. libGLESv2.so
# CXXFLAGS += -DIMGUI_IMPL_OPENGL_ES2
# LINUX_GL_LIBS = -lGLESv2
## If you're on a Raspberry Pi and want to use the legacy drivers,
## use the following instead:
# LINUX_GL_LIBS = -L/opt/vc/lib -lbrcmGLESv2

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += $(LINUX_GL_LIBS) -ldl `pkg-config sdl3 --libs`

	LIBS += -L $(ENGINE_DIR)

	CXXFLAGS += `pkg-config sdl3 --cflags`
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS += -framework Cocoa -framework IOKit -framework CoreVideo
	LIBS += `pkg-config --libs sdl3`
	LIBS += -L/usr/local/lib -L/opt/local/lib
	LIBS += -L $(ENGINE_DIR)

	CXXFLAGS += `pkg-config --cflags sdl3`
	CXXFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lgdi32 -lopengl32 -limm32 `pkg-config --static --libs sdl3`
	LIBS += -L $(ENGINE_DIR)

	CXXFLAGS += `pkg-config --cflags sdl3`
	CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)
	mv *.o bin

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(ENGINE_INCLUDE_DIR) $(ENGINE_LINK_DIR) $(LIBS) $(DYNAMIC_LIB_PATH)

clean:
	rm -f $(EXE) $(OBJS)
