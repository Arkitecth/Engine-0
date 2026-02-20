#include "LevelManager.h"
#include "LogManager.h"
#include <vector>


E0::LevelManager::LevelManager()
{
	startUp(); 
}

E0::LevelManager::~LevelManager()
{
	shutDown(); 
}

E0::Level* E0::LevelManager::getCurrentLevel()
{
	return levels[current_level];
}

void E0::LevelManager::setCurrentLevel(int new_level)
{
	if (new_level <= levels.size()) {
		current_level = new_level;
	} else {
		LM.logError("Current Level Should Not Exceed the Maximum amount of Levels");
	}
}

void E0::LevelManager::startUp()
{
	current_level = 0; 
	levels = {};
}

void E0::LevelManager::shutDown()
{
}


E0::LevelManager& E0::LevelManager::getInstance()
{
	static LevelManager levelManager; 

	return levelManager;
}


std::vector<E0::Level>& E0::LevelManager::getLevels()
{
	return levels;
}

void E0::LevelManager::setLevels(std::vector<Level>& new_levels)
{
	levels = new_levels; 
	current_level = 0; 
}


void E0::LevelManager::addLevel(E0::Level* level)
{
	levels.push_back(level); 
}

void E0::LevelManager::removeLevel(E0::Level* level)
{
	std::vector<E0::Level*> new_levels{};

	for(int i = 0; i < levels.size(); i++)
	{
		if (levels[i]->getLevelsName() == level->getLevelsName()) {	
			continue;
		}
		new_levels.push_back(level); 
	}
	LEM.setLevels(new_levels); 
}




