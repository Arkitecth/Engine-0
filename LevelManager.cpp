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

void addLevel(E0::LevelManager& levelManager, E0::Level& level)
{
	std::vector<E0::Level> levels = levelManager.getLevels(); 
	levels.push_back(level); 
}

void removeLevel(E0::LevelManager& levelManager, E0::Level& level)
{
	std::vector<E0::Level> levels = levelManager.getLevels(); 
	levels.erase(std::remove(levels.begin(), levels.end(), level.getLevelsName())); 
}

