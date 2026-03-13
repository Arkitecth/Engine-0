#include "SDL3/SDL_error.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "iostream"
#include <SDL3/SDL.h>
#include <SDL3/SDL_dialog.h>



static const SDL_DialogFileFilter filters[] = 
{
		{"PNG Images ", "png"},  
		{"JPEG Images ", "jpg;jpeg"},  
}; 



void SDLCALL callback(void* userdata, const char* const* fileList, int filter)
{
	if (!fileList) 
	{
		SDL_Log("An error occurred: %s\n", SDL_GetError()); 
		return;
	} else if(!*fileList) {
		SDL_Log("the user did not select any file"); 
		SDL_Log("Most likely, the dialog was canceled."); 
		return;
	}
	while (*fileList) 
	{
		SDL_Log("Full path to selected file: '%s'", *fileList);
		fileList++;
	}

	if (filter < 0) {
		SDL_Log("The current platform does not support fetching the selected filter, or the user did not select any filter");
	} else if(filter < SDL_arraysize(filters)) {
		SDL_Log("The filter selected by the user is '%s' (%s).", 
			filters[filter].pattern, filters[filter].name);
	}
}


int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) 
	{
		std::cout << "An error occurred during initialization" << '\n';
		return 1; 
	}

	int width = 800;
	int height = 450; 

	SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY;

	SDL_Window* window = SDL_CreateWindow("Level Editor", width, height, window_flags); 
	if (window == nullptr) 
	{
		std::cout << "Failed to Create Window" << '\n';
		return 1; 
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderVSync(renderer, 1);
	if (renderer == nullptr) 
	{
		std::cout << "Error: SDL_CreateRenderer: Failed to Create Renderer %s " << SDL_GetError() <<  '\n';
		return 1; 
	}
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io; 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; 

	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
	bool done = false;
	while (!done) 
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			ImGui_ImplSDL3_ProcessEvent(&event);
			if (event.type == SDL_EVENT_QUIT) {
				done = true;
			}
		}
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::Begin("Level Manager"); 
			if(ImGui::Button("Add Level"))
			{
				SDL_ShowOpenFileDialog(callback, nullptr, window, filters, 0, "./", false); 
			} 
			ImGui::End(); 
		}
		ImGui::Render(); 
		SDL_SetRenderScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
		SDL_RenderClear(renderer); 
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
		SDL_RenderPresent(renderer); 
	}
	ImGui_ImplSDLRenderer3_Shutdown(); 
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window); 
	SDL_Quit(); 
}

