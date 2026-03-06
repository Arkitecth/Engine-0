#include "Frame.h"
#include "DisplayManager.h"
#include "Rectangle.h"
#include "Vector.h"

E0::Frame::Frame()
{
}

E0::Frame::~Frame()
{

}

void E0::Frame::setHeight(float new_height)
{
	height = new_height;
}

void E0::Frame::setWidth(float new_width)
{
	width = new_width;
}

void E0::Frame::setPosition(E0::Vector new_position)
{
	position = new_position;
}

void E0::Frame::setTexture(std::string_view texture_path)
{
	texture.setLoadedTexture(texture_path); 
}


float E0::Frame::getHeight() const
{
	return height;
}

float E0::Frame::getWidth() const
{
	return width;
}

E0::Vector E0::Frame::getPosition() const
{
	return position;
}

void E0::Frame::draw()
{
	Rectangle dstRectangle{position, width, height}; 

	DM.drawTexture(&texture, dstRectangle);
}




