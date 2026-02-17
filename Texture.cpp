#include "Texture.h"
#include "DisplayManager.h"
#include <string_view>

E0::Texture::Texture()
{
	filePath = "";
	loadedTexture = nullptr;
}

E0::Texture::Texture(std::string_view new_file_path)
{
	setTexture(new_file_path); 
}

E0::Texture::~Texture()
{
	SDL_DestroyTexture(loadedTexture); 
}

void E0::Texture::setTexture(std::string_view new_file_path)
{
	filePath = new_file_path; 
	SDL_Surface* loadedSurface = SDL_LoadPNG(new_file_path.data());
	loadedTexture = SDL_CreateTextureFromSurface(DM.getRenderer(), loadedSurface); 
	SDL_DestroySurface(loadedSurface); 
}

std::string E0::Texture::getFilePath()
{
	return std::string(filePath);
}



