#include "Editor.h"
#include "DisplayManager.h"
#include "SDL3/SDL_log.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"


Editor::Editor(int new_width, int new_height)
{
	width = new_width;
	height = new_height;
	DM.startUp(width, height, "Level Editor"); 

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO(); (void)io; 
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; 

	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForSDLRenderer(DM.getWindow(), DM.getRenderer());
	ImGui_ImplSDLRenderer3_Init(DM.getRenderer());
	isRunning = false;
}

Editor::~Editor()
{
	ImGui_ImplSDLRenderer3_Shutdown(); 
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
	DM.shutDown();
	SDL_Quit(); 
}

void SDLCALL Editor::createLevel(void* userdata, const char* const* fileList, int filter)
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
		E0::Level* currentLevel = reinterpret_cast<E0::Level*>(userdata); 
		currentLevel->setTexturePath(*fileList); 
		SDL_Log("Level was succesfully created"); 
	}

	if (filter < 0) {
		SDL_Log("The current platform does not support fetching the selected filter, or the user did not select any filter");
	} else if(filter < SDL_arraysize(filters)) {
		SDL_Log("The filter selected by the user is '%s' (%s).", 
			filters[filter].pattern, filters[filter].name);
	}
}



void Editor::run()
{
	isRunning = true;
	while (isRunning) 
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			ImGui_ImplSDL3_ProcessEvent(&event);
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Level Manager"); 
			drawLayout();
		ImGui::End();

		ImGui::Render(); 
		SDL_SetRenderScale(DM.getRenderer(), io->DisplayFramebufferScale.x, io->DisplayFramebufferScale.y);
		SDL_RenderClear(DM.getRenderer()); 
		currentLevel.draw();
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), DM.getRenderer());
		SDL_RenderPresent(DM.getRenderer());


	
	}
}


void Editor::drawLayout()
{
	if(ImGui::Button("Add Level"))
	{
		ImGui::OpenPopup("LevelEntry"); 
	}
	if (ImGui::BeginPopup("LevelEntry")) 
	{
		char buf[100];
		ImGui::InputText("Levels Name", buf, 100);
		currentLevel.setLevelsName(buf);
		if(ImGui::Button("Create Level"))
		{
			SDL_ShowOpenFileDialog(createLevel, &currentLevel, DM.getWindow(), filters, 1, "./", false); 
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	if (!currentLevel.getLevelsName().empty()) 
	{
		ImGui::Text("%s", currentLevel.getLevelsName().c_str());
	}
}



