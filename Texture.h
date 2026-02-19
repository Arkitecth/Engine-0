#include <SDL3/SDL.h>
#include <string_view>
#pragma once

namespace E0
{
	class Texture 
	{
		private:
			std::string_view filePath; 
			SDL_Texture* loadedTexture; 
			float width; 
			float height; 
		public:
			Texture();
			const SDL_Texture* getLoadedTexture();
			Texture(std::string_view new_file_path);
			void setTexture(std::string_view new_file_path); 
			float getWidth(); 
			float getHeight();
			std::string getFilePath(); 
			~Texture(); 
	}; 
}
