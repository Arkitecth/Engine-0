#include "DisplayManager.h"
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

void E0::DisplayManager::drawTexture(std::string filePath)
{
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










