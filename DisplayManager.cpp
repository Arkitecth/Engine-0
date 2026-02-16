#include "DisplayManager.h"

E0::DisplayManager::DisplayManager()
{
	m_window = nullptr;
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
	}

}

void E0::DisplayManager::shutDown()
{
	if (m_window != nullptr) {
		SDL_DestroyWindow(m_window); 
		SDL_Quit(); 
	}
}

int E0::DisplayManager::getWidth()
{
	return width; 
}

int E0::DisplayManager::getHeight()
{
	return height; 
}










