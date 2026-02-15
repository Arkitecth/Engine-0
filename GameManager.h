#pragma once

#define GM E0::GameManager::getInstance()
const int DEFAULT_FRAME_RATE = 30;

namespace E0
{
	class GameManager 
	{
		private:
			int frameRate{}; 
			bool isGameOver{}; 
			GameManager(); 

		public:
			static GameManager& getInstance(); 
			~GameManager(); 
			void startUp(); 
			void shutDown(); 
			int  getFrameRate(); 
			bool getGameOver(); 
			void setFrameRate(int new_frame_rate); 
			void setGameOver(bool new_is_game_over); 
	}; 

			void run(); 
}
