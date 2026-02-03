#include "iostream"
#include <SDL3/SDL.h>
#include "imgui.h"

int main()
{
    SDL_Window* window; 
    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);




    window = SDL_CreateWindow("An SDL3 Window", 640, 480, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window %s\n",SDL_GetError());
        return 1; 
    }

    // const char* glsl_version = "#version 150";
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    // SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    //
    while (!done) {
        SDL_Event event; 

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true; 
            }
        }

    ImGui::Text("Hello World %d", 123);
    }

    SDL_DestroyWindow(window); 

    SDL_Quit();

    return 0;
}
