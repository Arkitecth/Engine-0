namespace E0
{
	class GameManager 
	{
		private:
			int frameRate{}; 
			bool isGameOver{}; 

		public:
			GameManager() = default; 
			~GameManager() = default; 
			int  getFrameRate(); 
			bool getGameOver(); 
			void setFrameRate(int new_frame_rate); 
			void setGameOver(bool new_is_game_over); 
	}; 

			void run(GameManager& gm); 
}
