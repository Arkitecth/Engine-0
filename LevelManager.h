#include <vector>
#include "Level.h"
#pragma once
namespace E0
{
	class LevelManager
	{
		private:
			std::vector<Level> levels{}; 
			int current_level{};
		
		public:
			LevelManager() = default; 
			~LevelManager() = default; 
			int getCurrentLevel(); 
			void setCurrentLevel(int new_level); 
			std::vector<Level>& getLevels();
			void setLevels(std::vector<Level>& new_levels); 
	}; 
			void addLevel(LevelManager& levelManager,  Level& level); 
			void removeLevel(LevelManager& levelManager, Level& level); 
}
