#include "LevelManager.h"
#include <iostream>
#include <vector>


E0::LevelManager::LevelManager()
{
	startUp(); 
}

E0::LevelManager::~LevelManager()
{
	shutDown(); 
}

int E0::LevelManager::getCurrentLevel()
{
	return current_level; 
}

void E0::LevelManager::setCurrentLevel(int new_level)
{
	if (new_level <= levels.size()) {
		current_level = new_level;
	} else {
		std::cerr << "Current Level Should Not Exceed the Maximum amount of Levels " << '\n';
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


void addLevel(E0::Level& level)
{
	std::vector<E0::Level> levels = LEM.getLevels(); 
	levels.push_back(level); 
}

void removeLevel(E0::Level& level)
{
	std::vector<E0::Level> levels = LEM.getLevels(); 
	std::vector<E0::Level> new_level{};

	for(int i = 0; i < levels.size(); i++)
	{
		if (levels[i].getLevelsName() == level.getLevelsName()) {	
			continue;
		}
		new_level.push_back(level); 
	}

	LEM.setLevels(new_level); 
}



