#include "DisplayManager.h"
#include "Rectangle.h"
#include <iostream>
#include <string>

E0::DisplayManager::DisplayManager()
{
	m_window = nullptr;
	m_renderer = nullptr;
	startUp(); 
}

E0::DisplayManager::~DisplayManager()
{
	shutDown(); 
}

E0::DisplayManager& E0::DisplayManager::getInstance()
{
	static DisplayManager dm; 
	return dm; 
}


void E0::DisplayManager::setWindowWidth(int new_width)
{
	width = new_width;
}

void E0::DisplayManager::setWindowHeight(int new_height)
{
	height = new_height; 
}

SDL_Renderer* E0::DisplayManager::getRenderer()
{
	return m_renderer; 
}

void E0::DisplayManager::setWindowTitle(std::string new_title)
{
	title = new_title; 
}

void E0::DisplayManager::startUp()
{
	width = 500; 
	height = 500; 
	title = "Engine 0";
	if (m_window == nullptr && m_renderer == nullptr) 
	{
		m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE); 
		m_renderer = SDL_CreateRenderer(m_window, nullptr); 
	}

}

void E0::DisplayManager::shutDown()
{
	if (m_window != nullptr) {
		SDL_DestroyWindow(m_window); 
		SDL_Quit(); 
	}
}

void E0::DisplayManager::drawCircle(int x, int y, float radius)
{

}

void E0::DisplayManager::drawRectangle(E0::Rectangle& rect)
{
	SDL_FRect fillRect = {rect.x_position, rect.y_position, rect.width, rect.height};
	SDL_SetRenderDrawColor(m_renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha); 
	SDL_RenderFillRect(m_renderer, &fillRect); 
}

void E0::DisplayManager::drawTexture(Texture& texture, Rectangle& src, Rectangle& dst)
{
	SDL_FRect srcRect= {src.x_position, src.y_position, src.width, src.height};
	SDL_FRect dstRect = {dst.x_position, dst.y_position, dst.width, dst.height};
	SDL_FRect* p_srcRect = &srcRect;
	SDL_FRect* p_dstRect= &dstRect;

	if (srcRect.h == 0 && srcRect.w == 0) 
	{
		p_srcRect = nullptr;
	}
	if (dstRect.h == 0 && srcRect.w == 0) {
		p_dstRect = nullptr;
	}
	SDL_RenderTexture(m_renderer, texture.getLoadedTexture(), p_srcRect, p_dstRect);
	if (SDL_GetError()[0]) {
		SDL_Log("SDL Error: %s", SDL_GetError());
	}
}

void E0::DisplayManager::swapBuffer(Color color)
{
	SDL_RenderPresent(m_renderer); 
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha); 
	SDL_RenderClear(m_renderer); 

}

int E0::DisplayManager::getWindowWidth()
{
	return width; 
}

int E0::DisplayManager::getWindowHeight()
{
	return height; 
}










