#include "Cursor.h"
#include "DisplayManager.h"
#include "Rectangle.h"
#include "Texture.h"
#include <cstdlib>

E0::Cursor::Cursor()
{
	const char* basePath = SDL_GetBasePath();
	std::string fullPath = std::string(basePath) + "../Engine0/Assets/cursor.png";
	texture = Texture{fullPath};
	cursorVisible = true;
}

void E0::Cursor::toggleCursor(bool new_cursor_visibility)
{
	cursorVisible = new_cursor_visibility;
}

void E0::Cursor::draw()
{
	E0::Rectangle rect{position, 30, 30};
	DM.drawTexture(texture, rect); 
}

void E0::Cursor::update()
{	
	float x{};
	float y{};
	SDL_GetMouseState(&x, &y); 
	position.setXY(x, y); 
}

void E0::Cursor::setCursorTexture(E0::Texture new_texture)
{
	texture = new_texture;
}

void E0::Cursor::setVectorPosition(E0::Vector new_position)
{
	position = new_position; 
}


E0::Vector E0::Cursor::getCursorPosition()
{
	return position; 
}

bool E0::Cursor::getCursorVisibility()
{
	return cursorVisible;
}

E0::Texture E0::Cursor::getCursorTexture()
{
	return texture;
}




