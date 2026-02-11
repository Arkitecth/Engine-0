#include "Vector.h"

E0::Vector::Vector()
{
	pos_x = 0.0f; 
	pos_y = 0.0f; 
}

E0::Vector::Vector(float new_pos_x, float new_pos_y)
{
	pos_x = new_pos_x; 
	pos_y = new_pos_y; 
}

float E0::Vector::getX()
{
	return pos_x; 
}


float E0::Vector::getY()
{
	return pos_y; 
}

void E0::Vector::setX(float new_pos_x)
{
	pos_x = new_pos_x;  
}

void E0::Vector::setY(float new_pos_y)
{
	pos_y = new_pos_y;  
}

void E0::Vector::setXY(float new_pos_x, float new_pos_y)
{
	pos_x = new_pos_x; 
	pos_y = new_pos_y;  
}

