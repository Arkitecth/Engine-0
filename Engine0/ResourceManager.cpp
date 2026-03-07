#include "ResourceManager.h"
#include "LogManager.h"
#include <algorithm>
#include <filesystem>
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

E0::Animation E0::ResourceManager::getAnimation(std::string_view directory_path, std::string_view animation_qualifier)
{
	std::vector<std::string> animationFilePaths{};
	Animation entityAnimation{};
	if (!std::filesystem::is_directory(directory_path)) 
	{
		LM.logError("RM: Animation Directory Path is invalid or not a directory"); 
		return Animation{};
	}

	for (const auto& filePath : std::filesystem::directory_iterator(directory_path)) 
	{
		if (filePath.path().extension() == ".png" && filePath.path().string().find(animation_qualifier) != std::string::npos) 
		{
			animationFilePaths.push_back(filePath.path()); 
		}
	}

	std::sort(animationFilePaths.begin(), animationFilePaths.end());
	for(int i = 0; i < animationFilePaths.size(); i++)
	{
		Texture entityTexture{animationFilePaths[i]};
		entityAnimation.insertAnimationTexture(&entityTexture); 
	}

	return entityAnimation;
}
