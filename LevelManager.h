#include <vector>
#include "Level.h"
#pragma once
#define LEM E0::LevelManager::getInstance()
namespace E0
{
	class LevelManager
	{
		private:
			std::vector<Level> levels{}; 
			int current_level{};
			LevelManager() = default; 
		
		public:
			~LevelManager() = default; 
			static LevelManager& getInstance(); 
			int getCurrentLevel(); 
			void setCurrentLevel(int new_level); 
			std::vector<Level>& getLevels();
			void setLevels(std::vector<Level>& new_levels); 
	}; 
			void addLevel(Level& level); 
			void removeLevel(Level& level); 
}
