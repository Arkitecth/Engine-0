#pragma once
#include <vector>
#include "Level.h"
#define LEM E0::LevelManager::getInstance()
namespace E0
{
	class LevelManager
	{
		private:
			std::vector<Level*> levels{}; 
			int current_level{};
			LevelManager(); 
		
		public:
			~LevelManager(); 
			static LevelManager& getInstance(); 
			void startUp(); 
			void shutDown(); 
			Level* getCurrentLevel(); 
			void setCurrentLevel(int new_level); 
			std::vector<Level*> getLevels();
			void setLevels(std::vector<Level*> new_levels); 
			void addLevel(E0::Level* level); 
			void removeLevel(E0::Level* level); 
	}; 
}
