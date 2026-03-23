#include "Editor.h"
#include "Color.h"
#include "DisplayManager.h"
#include "SDL3/SDL_log.h"
#include "Vector.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <algorithm>
#include "InputManager.h"
#include <iostream>
#include <fstream>
#include <string>

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
	std::fstream levelFile{};
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
		levelFile.open("./Levels/" + currentLevel->getLevelsName() + ".lvl", std::ios::out | std::ios::in);
		if (levelFile.is_open()) { levelFile << "- Name:" << currentLevel->getLevelsName() << '\n';
			levelFile << "- Texture Path:" << currentLevel->getTexturePath() << '\n';
			SDL_Log("Level was succesfully created"); 
			levelFile.close();
		}
	}
	if (filter < 0) {
		SDL_Log("The current platform does not support fetching the selected filter, or the user did not select any filter");
	} else if(filter < SDL_arraysize(filters)) {
		SDL_Log("The filter selected by the user is '%s' (%s).", 
			filters[filter].pattern, filters[filter].name);
	}
}

void SDLCALL Editor::loadLevel(void* userdata, const char* const* fileList, int filter)
{
	std::fstream levelFile{};
	std::string line{};
	std::string levelName; 
	std::string nameTag = "- Name:"; 
	std::string textureTag = "- Texture Path:"; 
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
		levelFile.open(*fileList, std::ios::in);
		if (levelFile.is_open()) {
			while (std::getline(levelFile, line)) {
				std::size_t namePos= line.find(nameTag); 
				if (namePos != std::string::npos) 
				{
					currentLevel->setLevelsName(line.substr(nameTag.size()));
				}
				std::size_t texturePos = line.find(textureTag); 
				if (texturePos != std::string::npos) 
				{
					currentLevel->setTexturePath(line.substr(textureTag.size()));
					std::cout << currentLevel->getTexturePath() << '\n';
				}
			}
		}
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
		addSpawnPoint();
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
		if (spawnPointMode) {
			DM.drawCircle(io->MousePos.x, io->MousePos.y, 10.0f, E0::RED); 
			for (auto vector : spawnPoints) {
				DM.drawCircle(vector.getX(), vector.getY(), 10.0f, E0::RED); 
			}
		}
		
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), DM.getRenderer());
		SDL_RenderPresent(DM.getRenderer());
	}
}

void Editor::addSpawnPoint()
{
	if (spawnPointMode) 
	{
		if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
			E0::Vector mousePosition {io->MousePos.x, io->MousePos.y};
			spawnPoints.push_back(mousePosition); 
		}
	}
}

void Editor::drawLayout()
{
	if (ImGui::BeginTabBar("Editor Tab Bar")) {

		if (ImGui::BeginTabItem("File")) {
			if(ImGui::Button("Create Level"))
			{
				ImGui::OpenPopup("LevelEntry"); 
			}
			ImGui::SameLine(120.0f);
			if (ImGui::Button("Load Level")) 
			{
				SDL_ShowOpenFileDialog(loadLevel, &currentLevel, DM.getWindow(), levelFilter, 1, "./Levels/", false); 
				currentLevel.setLevelsName(inputBuffer);
				std::fill(inputBuffer, inputBuffer + sizeof(inputBuffer), '\0'); 
			}

			if (ImGui::BeginPopup("LevelEntry")) 
			{
				ImGui::InputText("Levels Name", inputBuffer, 100);
				if(ImGui::Button("Create"))
				{
					currentLevel.setLevelsName(inputBuffer);
					SDL_ShowOpenFileDialog(createLevel, &currentLevel, DM.getWindow(), filters, 1, "./", false); 
					std::fill(inputBuffer, inputBuffer + sizeof(inputBuffer), '\0'); 
					ImGui::CloseCurrentPopup();
				}
				ImGui::SameLine(75.0f);
				if(ImGui::Button("Cancel"))
				{
					std::fill(inputBuffer, inputBuffer + sizeof(inputBuffer), '\0'); 
					ImGui::CloseCurrentPopup();
				}
				ImGui::EndPopup();
			}
			if (!currentLevel.getLevelsName().empty()) 
			{
				ImGui::Text("%s", currentLevel.getLevelsName().c_str());
			}

			ImGui::EndTabItem();
		}

		if(ImGui::BeginTabItem("Tool Box"))
		{
			if (ImGui::Button("Add Spawn Point")) 
			{
				if (!currentLevel.getTexturePath().empty()) 
				{
					spawnPointMode = !spawnPointMode;
				}
			}

			if (ImGui::Button("Add Tower Point")) {
			}
			if (ImGui::Button("Add Waypoint")) {
			
			}

			ImGui::EndTabItem(); 
		}
		ImGui::EndTabBar();

	}
}






