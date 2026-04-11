#include "Editor.h"
#include "Color.h"
#include "DisplayManager.h"
#include "Level.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "Vector.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <algorithm>
#include "InputManager.h"
#include "utility.h"
#include <chrono>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

Editor::Editor(int new_width, int new_height)
{
	width = new_width;
	height = new_height;
	DM.startUp(width, height, "Level Editor"); 
	DM.toggleCursor();
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

void Editor::edit()
{
	if (ImGui::Button("Edit Points")) 
	{
		wayPointMode = false;
		editMode = !editMode; 
	}
	if (!io->WantCaptureMouse) 
	{
		if (editMode) 
		{
			std::vector<E0::Vector> waypoints = currentLevel.getWaypoints();
			E0::Vector mousePosition {io->MousePos.x, io->MousePos.y};
			for (auto& vector : waypoints) 
			{
				if (CheckForIntersection(mousePosition, vector.getX(), vector.getY(), 10)) 
				{
					if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
						vector.setXY(mousePosition.getX(), mousePosition.getY());
					}
				}
			}
			currentLevel.setWaypoint(waypoints); 
		}
	}

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
		if (levelFile.is_open()) { 
			levelFile << "- Name:" << currentLevel->getLevelsName() << '\n';
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
	std::string waypointTag = "- Waypoints:";
	std::string towerpointTag = "- Towerpoints:";
	std::string openingParantheses = "("; 
	std::string closingParantheses= ")";
	std::vector<E0::Vector> waypoints{};
	std::vector<E0::Vector> towerpoints{};
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
			float scaleX = 0.0f; 
			float scaleY = 0.0f; 
			SDL_GetRenderScale(DM.getRenderer(), &scaleX, &scaleY); 
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

				std::size_t wayPointPos = line.find(waypointTag); 
				if (wayPointPos != std::string::npos) 
				{
					std::string wayPointLine = line;
					while (wayPointLine.find(closingParantheses) != std::string::npos) {
						//Get everything after the opening & closing parantheses
						std::size_t openingParanthesesPos= wayPointLine.find(openingParantheses);
						std::size_t closingParanthesesPos = wayPointLine.find(closingParantheses); 
						std::string vectorPosition = wayPointLine.substr(openingParanthesesPos + 1, closingParanthesesPos - openingParanthesesPos - 1); 
						std::size_t commaPosition  = vectorPosition.find(",");
						float vectorXPosition = std::stof(vectorPosition.substr(0, commaPosition)); 
						float vectorYPosition = std::stof(vectorPosition.substr(commaPosition + 1, closingParanthesesPos - commaPosition)); 
						E0::Vector vector{vectorXPosition / scaleX, vectorYPosition / scaleY};
						wayPointLine.erase(openingParanthesesPos, closingParanthesesPos - openingParanthesesPos + 2);
						waypoints.push_back(vector);
					}
					currentLevel->setWaypoint(waypoints); 
				}

				std::size_t towerPointPos = line.find(towerpointTag); 
				if (towerPointPos != std::string::npos) 
				{
					std::string towerPointLine = line;
					while (towerPointLine.find(closingParantheses) != std::string::npos) {
						//Get everything after the opening & closing parantheses
						std::size_t openingParanthesesPos= towerPointLine.find(openingParantheses);
						std::size_t closingParanthesesPos = towerPointLine.find(closingParantheses); 
						std::string vectorPosition = towerPointLine.substr(openingParanthesesPos + 1, closingParanthesesPos - openingParanthesesPos - 1); 
						std::size_t commaPosition  = vectorPosition.find(",");
						float vectorXPosition = std::stof(vectorPosition.substr(0, commaPosition)); 
						float vectorYPosition = std::stof(vectorPosition.substr(commaPosition + 1, closingParanthesesPos - commaPosition)); 
						E0::Vector vector{vectorXPosition / scaleX, vectorYPosition / scaleY};
						towerPointLine.erase(openingParanthesesPos, closingParanthesesPos - openingParanthesesPos + 2);
						towerpoints.push_back(vector);
					}
					currentLevel->setTowerPoints(towerpoints);
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

void Editor::save()
{
	if (!currentLevel.getLevelsName().empty()) {
		std::fstream levelFile{};
		levelFile.open("./Levels/" + currentLevel.getLevelsName() + ".lvl", std::ios::out | std::ios::in);
		if (!levelFile.is_open()) {
			SDL_Log("An error occurred opening the file"); 
			return;
		}
		if (ImGui::Button("Save")) 
		{
			float scaleX = 0.0f; 
			float scaleY = 0.0f; 
			SDL_GetRenderScale(DM.getRenderer(), &scaleX, &scaleY); 
			levelFile << "- Name:" << currentLevel.getLevelsName() << '\n';
			levelFile << "- Texture Path:" << currentLevel.getTexturePath() << '\n';
			levelFile << "- Waypoints:";
			for (auto& vector : currentLevel.getWaypoints()) 
			{
				levelFile << "(" << vector.getX() * scaleX << "," << vector.getY() * scaleY << ")" << " ";
			}
			levelFile << '\n';
			levelFile << "- Towerpoints:" ;
			for (auto& vector : currentLevel.getTowerpoints()) 
			{
				levelFile << "(" << vector.getX() * scaleX << "," << vector.getY() * scaleY << ")" << " ";
			}


		}
	}
}

void Editor::run()
{
	const auto frameTime = std::chrono::milliseconds(1000 / 60);
	auto nextFrame = std::chrono::steady_clock::now(); 
	isRunning = true;
	while (isRunning) 
	{
		nextFrame += frameTime;

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
		pushLayout();
		ImGui::End();
		std::this_thread::sleep_until(nextFrame);
		render();
	}
}

void Editor::render()
{
	ImGui::Render(); 
	SDL_SetRenderScale(DM.getRenderer(), io->DisplayFramebufferScale.x, io->DisplayFramebufferScale.y);
	SDL_RenderClear(DM.getRenderer()); 
	currentLevel.draw();
	E0::Texture texture{"./Assets/dot.png"};
	if (wayPointMode) 
	{
		DM.drawCircle(io->MousePos.x, io->MousePos.y, 10.0f, E0::RED); 
	}
	if (wayPointMode || editMode) 
	{
		for (auto vector : currentLevel.getWaypoints()) {
			DM.drawCircle(vector.getX(), vector.getY(), 10.0f, E0::RED); 
		}
	}
	if (towerPointMode) {
		for (auto vector : currentLevel.getTowerpoints()) {
			E0::Rectangle rect{vector, texture.getWidth() / 2.0f, texture.getHeight() / 2.0f};
			DM.drawTexture(texture, rect);
			//DM.drawCircle(vector.getX(), vector.getY(), 10.0f, E0::BLUE); 
		}
	}

	if (wayPointMode || towerPointMode) {
		E0::Vector position{io->MousePos.x, io->MousePos.y};
		E0::Rectangle rect{position, texture.getWidth() / 2.0f, texture.getHeight() / 2.0f};
		DM.drawTexture(texture, rect);
		//DM.drawCircle(io->MousePos.x, io->MousePos.y, 10.0f, E0::BLUE); 
	}

	if (simulationMode) {
		entity.draw();
	}
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), DM.getRenderer());
	SDL_RenderPresent(DM.getRenderer());
}


void Editor::addWayPoint()
{
	if (ImGui::Button("Add Waypoint")) {
		if (!currentLevel.getTexturePath().empty()) 
		{
			wayPointMode = !wayPointMode;
			towerPointMode = false;
			editMode = false;
		}
	}
	if (wayPointMode) 
	{
		if (!io->WantCaptureMouse) 
		{
		
			if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
				E0::Vector mousePosition {io->MousePos.x, io->MousePos.y};
				currentLevel.addWayPoint(mousePosition); 
			}
		}
	}
}

void Editor::addTowerPoint()
{
	if (ImGui::Button("Add Towerpoint")) 
	{
		if (!currentLevel.getTexturePath().empty()) 
		{
			towerPointMode = !towerPointMode;
			editMode = false; 
			wayPointMode = false;
		}
	}

	if (towerPointMode) {
		if (!io->WantCaptureMouse) 
		{
		
			if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
				E0::Vector mousePosition {io->MousePos.x, io->MousePos.y};
				currentLevel.addTowerPoint(mousePosition); 
			}
		}
	}
}

void Editor::fileManagement()
{
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
}

void Editor::simulateWaypoint()
{
	if (ImGui::Button("Simulate Pathfinding")) 
	{
		simulationMode = !simulationMode;
		entity.waypoints = currentLevel.getWaypoints();
	}

	if (simulationMode && entity.waypoints.size() != 0) {
		entity.moveTowardsWaypoint(); 
	}
}

void Editor::clear()
{
	if (ImGui::Button("Clear")) 
	{
		currentLevel.setWaypoint(std::vector<E0::Vector>{});
	}
}


void Editor::pushLayout()
{
	if (ImGui::BeginTabBar("Editor Tab Bar")) {

		if (ImGui::BeginTabItem("File")) 
		{
			fileManagement(); 
			ImGui::EndTabItem();
		}
		if(ImGui::BeginTabItem("Tool Box"))
		{
			addWayPoint(); 
			addTowerPoint();
			save();
			edit();
			clear();
			simulateWaypoint(); 
			ImGui::EndTabItem(); 
		}
		ImGui::EndTabBar();

	}
}






