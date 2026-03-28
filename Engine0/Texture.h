#include <SDL3/SDL.h>
#include <string>
#pragma once

namespace E0
{
enum class TextureDirection
{
	HORIZONTAL = SDL_FLIP_HORIZONTAL, 
	VERTICAL = SDL_FLIP_VERTICAL,
	NONE = SDL_FLIP_NONE,
}; 

	class Texture 
	{
		private:
			std::string filePath; 
			SDL_Texture* loadedTexture; 
			TextureDirection flipMode{};
			float width{}; 
			float height{}; 
		public:
			Texture();
			Texture(std::string new_file_path);
			Texture(const Texture& rhs);
			void operator=(const Texture& rhs);
			SDL_Texture* getLoadedTexture();
			void setLoadedTexture(std::string_view new_file_path); 
			void setFlipMode(TextureDirection new_flip_mode);
			SDL_FlipMode  getFlipMode();
			float getWidth(); 
			float getHeight();
			std::string getFilePath(); 
			~Texture(); 
	}; 
}
