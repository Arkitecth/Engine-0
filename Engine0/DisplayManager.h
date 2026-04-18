#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"
#include "Texture.h"
#include "string"
#include "Color.h"
#define DM E0::DisplayManager::getInstance()

namespace E0
{
	const int WINDOW_WIDTH_DEFAULT = 800;
	const int WINDOW_HEIGHT_DEFAULT = 500; 
	const std::string WINDOW_TITLE_DEFAULT = "Engine 0";
	class DisplayManager
	{
		private:
			DisplayManager(); 
			SDL_Window* m_window; 
			SDL_Renderer* m_renderer; 
			int win_width{}; 
			std::string title{}; 
			int win_height{}; 

		public:
			static DisplayManager& getInstance(); 
			~DisplayManager(); 
			void startUp(int new_width, int new_height, std::string new_title); 
			void shutDown(); 
			SDL_Renderer* getRenderer(); 
			SDL_Window* getWindow(); 
			int getWindowWidth(); 
			void setWindowWidth(int new_width); 
			std::string getWindowTitle(); 
			void setWindowTitle(std::string new_title); 
			int getWindowHeight(); 
			void setWindowHeight(int new_height); 
			void toggleCursor();
			void drawCircle(int center_x, int center_y, int radius, Color color); 
			void drawHollowCircle(int center_x, int center_y, int radius, Color color); 
			void drawRectangle(Rectangle& rect); 
			void drawTexture(E0::Texture& texture, Rectangle& dst); 
			void drawBackgroundTexture(E0::Texture* texture); 
			void swapBuffer(Color color); 
	}; 

}
