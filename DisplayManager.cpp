#include "DisplayManager.h"

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


void E0::DisplayManager::setWidth(int new_width)
{
	width = new_width;
}

void E0::DisplayManager::setHeight(int new_height)
{
	height = new_height; 
}

SDL_Window* E0::DisplayManager::getWindow()
{
	return m_window; 
}

void E0::DisplayManager::setTitle(std::string new_title)
{
	title = new_title; 
}

void E0::DisplayManager::startUp()
{
	width = 500; 
	height = 500; 
	title = "Engine 0";
	if (m_window == nullptr) 
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

void E0::DisplayManager::drawRectangle(float x, float y, float width, float height, Color color)
{
	SDL_FRect fillRect = {x, y, width, height};

	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha); 

	SDL_RenderFillRect(m_renderer, &fillRect); 
}

void E0::DisplayManager::drawTexture()
{

}

void E0::DisplayManager::swapBuffer()
{
	SDL_RenderPresent(m_renderer); 
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF); 
	SDL_RenderClear(m_renderer); 
}

int E0::DisplayManager::getWidth()
{
	return width; 
}

int E0::DisplayManager::getHeight()
{
	return height; 
}










