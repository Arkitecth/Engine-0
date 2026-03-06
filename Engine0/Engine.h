#pragma once
#include <string_view>
#include "DisplayManager.h"
#define Engine E0::GameManager::getInstance()
const int DEFAULT_FRAME_RATE = 30;

namespace E0
{
	class GameManager 
	{
		private:
			int frameRate{}; 
			bool isGameOver{}; 
			std::string_view title{}; 
			GameManager(); 

		public:
			static GameManager& getInstance(); 
			~GameManager(); 
			void startUp(int window_width = WINDOW_WIDTH_DEFAULT, int window_height = WINDOW_HEIGHT_DEFAULT, std::string_view title = WINDOW_TITLE_DEFAULT);
			void shutDown(); 
			int  getFrameRate(); 
			bool getGameOver(); 
			void setFrameRate(int new_frame_rate); 
			void setGameOver(bool new_is_game_over); 
			void run(); 
	}; 

}
