#include "Texture.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include <string>
#include <string_view>


E0::Texture::Texture()
{
	filePath = "";
	loadedTexture = nullptr;
	width = 0.0f; 
	height = 0.0f; 
}

E0::Texture::Texture(std::string new_file_path)
{
	setLoadedTexture(new_file_path);
}

E0::Texture::Texture(const Texture& rhs)
{
	setLoadedTexture(rhs.filePath); 
}

void E0::Texture::operator=(const Texture& rhs)
{
	setLoadedTexture(rhs.filePath); 
}

E0::Texture::~Texture()
{
	if (loadedTexture != nullptr) {
		SDL_DestroyTexture(loadedTexture); 
	}
}

void E0::Texture::setLoadedTexture(std::string_view new_file_path)
{
	filePath = new_file_path; 
	SDL_Surface* loadedSurface = SDL_LoadPNG(new_file_path.data());
	loadedTexture = SDL_CreateTextureFromSurface(DM.getRenderer(), loadedSurface); 
	if (loadedTexture == nullptr) {
		LM.logError("An error occurred with Setting Texture"); 
		return;
	}
	width = loadedTexture->w; 
	height = loadedTexture->h;
	SDL_DestroySurface(loadedSurface); 
}

std::string E0::Texture::getFilePath()
{
	return std::string(filePath);
}

float E0::Texture::getWidth()
{
	return float(loadedTexture->w);
}

SDL_Texture* E0::Texture::getLoadedTexture()
{
	return loadedTexture;
}

float E0::Texture::getHeight()
{
	return float(loadedTexture->h);
}


