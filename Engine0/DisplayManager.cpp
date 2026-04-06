#include "DisplayManager.h"
#include "Color.h"
#include "Rectangle.h"
#include <string>

E0::DisplayManager::DisplayManager()
{
	m_window = nullptr;
	m_renderer = nullptr;
	width = WINDOW_WIDTH_DEFAULT;
	height = WINDOW_HEIGHT_DEFAULT;
	title = WINDOW_TITLE_DEFAULT;
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

std::string E0::DisplayManager::getWindowTitle()
{
	return title;
}

void E0::DisplayManager::startUp(int new_width, int new_height, std::string new_title)
{
	if (m_window == nullptr && m_renderer == nullptr) 
	{
		width = new_width;
		height = new_height;
		title = new_title;
		m_window = SDL_CreateWindow(new_title.c_str(), new_width, new_height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY); 
		m_renderer = SDL_CreateRenderer(m_window, nullptr); 
		SDL_SetRenderVSync(m_renderer, 1); 
	}
}

void E0::DisplayManager::shutDown()
{
	if (m_window != nullptr) {
		SDL_DestroyWindow(m_window); 
		SDL_Quit(); 
	}
}

void E0::DisplayManager::drawCircle(int center_x, int center_y, int radius, Color color)
{
	int diameter = 2 * radius;
	int x = radius - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int decision = (tx - diameter);
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);
	while (x >= y) 
	{
		SDL_RenderLine(m_renderer, center_x - x, center_y - y, center_x + x, center_y - y);

		SDL_RenderLine(m_renderer, center_x - x, center_y + y, center_x + x, center_y + y);

		SDL_RenderLine(m_renderer, center_x - y, center_y - x, center_x + y, center_y - x);

		SDL_RenderLine(m_renderer, center_x - y, center_y + x, center_x + y, center_y + x);

		if (decision <= 0) 
		{
			y++;
			decision += ty;
			ty += 2;
		}
		if (decision > 0) {
			x--;
			tx += 2;
			decision += (tx - diameter);
		}
	}
}

void E0::DisplayManager::drawRectangle(E0::Rectangle& rect)
{
	SDL_FRect fillRect = {rect.position.getX(), rect.position.getY(), rect.width, rect.height};
	SDL_SetRenderDrawColor(m_renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha); 
	SDL_RenderFillRect(m_renderer, &fillRect); 
}

void E0::DisplayManager::drawTexture(Texture& texture, Rectangle& dst)
{
	SDL_FRect dstRect = {dst.position.getX(), dst.position.getY(), dst.width, dst.height};
	SDL_FRect* p_dstRect= &dstRect;
	SDL_RenderTextureRotated(m_renderer, texture.getLoadedTexture(), nullptr, p_dstRect, 0.0, nullptr, texture.getFlipMode());
	if (SDL_GetError()[0]) {
		SDL_Log("SDL Error: %s", SDL_GetError());
	}
}

void E0::DisplayManager::drawBackgroundTexture(Texture* texture)
{
	SDL_RenderTexture(m_renderer, texture->getLoadedTexture(), nullptr, nullptr);
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

SDL_Window* E0::DisplayManager::getWindow()
{
	return m_window;
}

int E0::DisplayManager::getWindowHeight()
{
	return height; 
}










