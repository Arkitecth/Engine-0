#include "LevelManager.h"
#include <algorithm>
#include <iostream>
#include <vector>


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

std::vector<E0::Level>& E0::LevelManager::getLevels()
{
	return levels;
}

void E0::LevelManager::setLevels(std::vector<Level>& new_levels)
{
	levels = new_levels; 
	current_level = 0; 
}


void addLevel(E0::LevelManager& levelManager, E0::Level& level)
{
	std::vector<E0::Level> levels = levelManager.getLevels(); 
	levels.push_back(level); 
}

void removeLevel(E0::LevelManager& levelManager, E0::Level& level)
{
	std::vector<E0::Level> levels = levelManager.getLevels(); 
	std::vector<E0::Level> new_level{};

	for(int i = 0; i < levels.size(); i++)
	{
		if (levels[i].getLevelsName() == level.getLevelsName()) {	
			continue;
		}
		new_level.push_back(level); 
	}

	levelManager.setLevels(new_level); 
}

