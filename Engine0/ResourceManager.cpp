#include "ResourceManager.h"
#include "LogManager.h"
#include <filesystem>

E0::ResourceManager::ResourceManager()
{

}

E0::ResourceManager::~ResourceManager()
{

}


void E0::ResourceManager::startUp()
{

}

void E0::ResourceManager::shutDown()
{

}

std::vector<std::string> E0::ResourceManager::getAnimation(std::string_view directory_path)
{
	std::vector<std::string> animationFilePaths{};
	if (!std::filesystem::is_directory(directory_path)) 
	{
		LM.logError("RM: Animation Directory Path is invalid or not a directory"); 
		return animationFilePaths;
	}

	for (const auto& filePath : std::filesystem::directory_iterator(directory_path)) 
	{
		if (filePath.path().stem() == ".png") 
		{
			animationFilePaths.push_back(filePath.path()); 
		}
	}
	return animationFilePaths;
}
