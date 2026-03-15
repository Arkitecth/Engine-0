#include "SDL3/SDL_error.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include <Level.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_dialog.h>
#include <DisplayManager.h>


static const SDL_DialogFileFilter filters[] = 
{
		{"PNG Images ", "png"},  
		{"JPEG Images ", "jpg;jpeg"},  
}; 

E0::Level level{};
std::string fileName{};
bool levelAdded = false;

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
	if (*fileList) 
	{
		level.setTexturePath(*fileList); 
		SDL_Log("Full path texture selected file: '%s'", *fileList);
		fileName = *fileList;
	}

	if (filter < 0) {
		SDL_Log("The current platform does not support fetching the selected filter, or the user did not select any filter");
	} else if(filter < SDL_arraysize(filters)) {
		SDL_Log("The filter selected by the user is '%s' (%s).", 
			filters[filter].pattern, filters[filter].name);
	}
}

void loadBackground()
{

}


int main()
{
	int width = 800;
	int height = 450; 
	char levelsName[100]{}; 
	DM.startUp(width, height, "Level Editor"); 

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io; 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; 

	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForSDLRenderer(DM.getWindow(), DM.getRenderer());
	ImGui_ImplSDLRenderer3_Init(DM.getRenderer());
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
			ImGui::BeginTabBar("Levels");
			if(ImGui::Button("Add Level"))
			{
				ImGui::OpenPopup("LevelEntry"); 
			}
			if (ImGui::BeginPopup("LevelEntry")) 
			{
				ImGui::InputText("Level Name", levelsName, 100);
				if(ImGui::Button("Create Level"))
				{
					SDL_ShowOpenFileDialog(callback, nullptr, DM.getWindow(), filters, 1, "./", false); 
					levelAdded = true;
					ImGui::CloseCurrentPopup();
				}
				ImGui::EndPopup();
			}
		} 
			if (levelAdded) 
			{
				if(ImGui::BeginTabItem(levelsName))
				{
					ImGui::EndTabItem(); 
				}
			}
			ImGui::EndTabBar();
			ImGui::End(); 


		ImGui::Render(); 
		SDL_SetRenderScale(DM.getRenderer(), io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
		SDL_RenderClear(DM.getRenderer()); 
		level.draw();
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), DM.getRenderer());
		SDL_RenderPresent(DM.getRenderer()); 

	}

	ImGui_ImplSDLRenderer3_Shutdown(); 
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
	DM.shutDown();
	SDL_Quit(); 
}

