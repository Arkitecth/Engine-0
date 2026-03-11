#include <SDL3/SDL.h>
#include <string>
#pragma once
namespace E0
{
	class Texture 
	{
		private:
			std::string filePath; 
			SDL_Texture* loadedTexture; 
			float width{}; 
			float height{}; 
		public:
			Texture();
			Texture(const Texture& rhs);
			void operator=(const Texture& rhs);
			SDL_Texture* getLoadedTexture();
			Texture(std::string_view new_file_path);
			void setLoadedTexture(std::string_view new_file_path); 
			float getWidth(); 
			float getHeight();
			std::string getFilePath(); 
			~Texture(); 
	}; 
}
