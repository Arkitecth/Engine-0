#include <SDL3/SDL.h>
#include "string"
#define DM E0::DisplayManager::getInstance() 
namespace E0
{
	class DisplayManager
	{
		private:
			DisplayManager(); 
			SDL_Window* m_window; 
			int width; 
			std::string title; 
			int height; 

		public:
			static DisplayManager& getInstance(); 
			~DisplayManager(); 
			void startUp(); 
			void shutDown(); 
			SDL_Window* getWindow(); 
			int getWidth(); 
			void setWidth(int new_width); 
			std::string getTitle(); 
			void setTitle(std::string new_title); 
			int getHeight(); 
			void setHeight(int new_height); 
	}; 

}
