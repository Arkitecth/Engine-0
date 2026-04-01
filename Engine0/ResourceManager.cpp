#include "ResourceManager.h"
#include "Level.h"
#include "LogManager.h"
#include <algorithm>
#include <filesystem>
#include <ios>
#include "Texture.h"

E0::ResourceManager::ResourceManager()
{

}

E0::ResourceManager::~ResourceManager()
{

}


E0::ResourceManager& E0::ResourceManager::getInstance()
{
	static ResourceManager rm;
	return rm;
}


void E0::ResourceManager::startUp()
{

}

void E0::ResourceManager::shutDown()
{

}

std::vector<std::string> E0::ResourceManager::getAnimationFiles(std::string_view directory_path, std::string_view animation_qualifier)
{
	std::vector<std::string> animationFilePaths{};
	if (!std::filesystem::is_directory(directory_path)) 
	{
		LM.logError("RM: Animation Directory Path is invalid or not a directory"); 
		return {};
	}

	for (const auto& filePath : std::filesystem::directory_iterator(directory_path)) 
	{
		if (filePath.path().extension() == ".png" && filePath.path().string().find(animation_qualifier) != std::string::npos) 
		{
			animationFilePaths.push_back(filePath.path()); 
		}
	}

	std::sort(animationFilePaths.begin(), animationFilePaths.end());
	return animationFilePaths;
}

E0::Level E0::ResourceManager::loadLevel(std::string_view filePath)
{
	std::fstream levelFile{};
	Level level{};
	levelFile.open(filePath, std::ios::in | std::ios::out); 
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
	if (!levelFile.is_open()) 
	{
		LM.logError("An error occurred opening the file"); 
		return level;
	}
	if (levelFile.is_open()) 
	{
		while (std::getline(levelFile, line)) 
		{
			std::size_t namePos= line.find(nameTag); 
			if (namePos != std::string::npos) 
			{
				level.setLevelsName(line.substr(nameTag.size()));
			}
			std::size_t texturePos = line.find(textureTag); 
			if (texturePos != std::string::npos) 
			{
				level.setTexturePath(line.substr(textureTag.size()));
			}

			std::size_t wayPointPos = line.find(waypointTag); 
			if (wayPointPos != std::string::npos) 
			{
				std::string wayPointLine = line;
				while (wayPointLine.find(closingParantheses) != std::string::npos) 
				{
					//Get everything after the opening & closing parantheses
					std::size_t openingParanthesesPos= wayPointLine.find(openingParantheses);
					std::size_t closingParanthesesPos = wayPointLine.find(closingParantheses); 
					std::string vectorPosition = wayPointLine.substr(openingParanthesesPos + 1, closingParanthesesPos - openingParanthesesPos - 1); 
					std::size_t commaPosition  = vectorPosition.find(",");
					float vectorXPosition = std::stof(vectorPosition.substr(0, commaPosition)); 
					float vectorYPosition = std::stof(vectorPosition.substr(commaPosition + 1, closingParanthesesPos - commaPosition)); 
					E0::Vector vector{vectorXPosition, vectorYPosition};
					wayPointLine.erase(openingParanthesesPos, closingParanthesesPos - openingParanthesesPos + 2);
					waypoints.push_back(vector);
				}
					level.setWaypoint(waypoints); 
			}

			std::size_t towerPointPos = line.find(towerpointTag); 
			if (towerPointPos != std::string::npos) 
			{
				std::string towerPointLine = line;
				while (towerPointLine.find(closingParantheses) != std::string::npos) 
				{
					//Get everything after the opening & closing parantheses
					std::size_t openingParanthesesPos= towerPointLine.find(openingParantheses);
					std::size_t closingParanthesesPos = towerPointLine.find(closingParantheses); 
					std::string vectorPosition = towerPointLine.substr(openingParanthesesPos + 1, closingParanthesesPos - openingParanthesesPos - 1); 
					std::size_t commaPosition  = vectorPosition.find(",");
					float vectorXPosition = std::stof(vectorPosition.substr(0, commaPosition)); 
					float vectorYPosition = std::stof(vectorPosition.substr(commaPosition + 1, closingParanthesesPos - commaPosition)); 
					E0::Vector vector{vectorXPosition, vectorYPosition};
					towerPointLine.erase(openingParanthesesPos, closingParanthesesPos - openingParanthesesPos + 2);
					towerpoints.push_back(vector);
				}
					level.setTowerPoints(towerpoints);
			}
		}
	}
	return level;
}
