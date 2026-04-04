#include "Widget.h"
#include "Texture.h"

E0::Widget::Widget(){}

void E0::Widget::draw()
{
}

void E0::Widget::eventHandler(const E0::Event* e)
{

}

E0::Widget::Widget(E0::Vector new_position, float new_width, float new_height, E0::Texture new_texture)
{
	position = new_position;
	width = new_width;
	height = new_height;
	texture = new_texture;
}

void E0::Widget::setTexture(E0::Texture& new_texture)
{
	texture = new_texture;
}


E0::Texture* E0::Widget::getTexture()
{
	return &texture;
}

float E0::Widget::getWidth()
{
	return width;
}

float E0::Widget::getHeight()
{
	return height;
}

void E0::Widget::setWidth(float new_width)
{
	width = new_width;
}


void E0::Widget::setHeight(float new_height)
{
	height = new_height;
}

E0::Vector E0::Widget::getPosition()
{
	return position;
}

void E0::Widget::setPosition(E0::Vector new_position)
{
	position = new_position;
}



