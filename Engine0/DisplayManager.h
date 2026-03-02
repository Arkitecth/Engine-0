#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"
#include "Texture.h"
#include "string"
#include "Color.h"
#define DM E0::DisplayManager::getInstance() 
namespace E0
{
	class DisplayManager
	{
		private:
			DisplayManager(); 
			SDL_Window* m_window; 
			SDL_Renderer* m_renderer; 
			int width; 
			std::string title; 
			int height; 

		public:
			static DisplayManager& getInstance(); 
			~DisplayManager(); 
			void startUp(); 
			void shutDown(); 
			SDL_Renderer* getRenderer(); 
			int getWindowWidth(); 
			void setWindowWidth(int new_width); 
			std::string getWindowTitle(); 
			void setWindowTitle(std::string new_title); 
			int getWindowHeight(); 
			void setWindowHeight(int new_height); 
			void drawCircle(int x, int y, float radius); 
			void drawRectangle(Rectangle& rect); 
			void drawTexture(E0::Texture& texture, Rectangle& src, Rectangle& dst); 
			void swapBuffer(Color color); 
	}; 

}
