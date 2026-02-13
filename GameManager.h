namespace E0
{
	class GameManager 
	{
		private:
			int frameTime{}; 
			bool isGameOver{}; 

		public:
			GameManager() = default; 
			~GameManager() = default; 
			int  getFrameTime(); 
			bool getGameOver(); 
			void setFrameTime(int new_frame_time); 
			void setGameOver(bool new_is_game_over); 
	}; 

			void run(GameManager& gm); 
}
