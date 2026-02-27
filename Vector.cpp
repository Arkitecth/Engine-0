#include "Vector.h"
#include <cmath>

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


E0::Vector E0::Vector::normalize()
{
	float mag = magnitude();
	Vector unitVector{ pos_x / mag, pos_y / mag}; 

	return unitVector; 
}

float E0::Vector::magnitude()
{
	return std::sqrt(pos_x * pos_x + pos_y * pos_y);
}


void E0::Vector::setXY(float new_pos_x, float new_pos_y)
{
	pos_x = new_pos_x; 
	pos_y = new_pos_y;  
}
void E0::Vector::operator=(const Vector& rhs)
{
	this->setXY(rhs.pos_x, rhs.pos_y); 

}
E0::Vector E0::Vector::operator+(const Vector& rhs)
{
	Vector newVector{this->pos_x + rhs.pos_x, this->pos_y + rhs.pos_y}; 

	return newVector;
}

E0::Vector E0::Vector::operator-(const Vector& rhs)
{
	Vector newVector{rhs.pos_x - this->pos_x, rhs.pos_y - this->pos_y}; 

	return newVector;
}
bool E0::Vector::operator>(const Vector& rhs)
{
	return this->pos_x > rhs.pos_x && this->pos_y > rhs.pos_y;
}
bool E0::Vector::operator<(const Vector& rhs)
{
	return this->pos_x < rhs.pos_x && this->pos_y < rhs.pos_y;
}

bool E0::Vector::operator>=(const Vector& rhs)
{
	return this->pos_x >= rhs.pos_x && this->pos_y >= rhs.pos_y;
}
bool E0::Vector::operator<=(const Vector& rhs)
{
	return this->pos_x <= rhs.pos_x && this->pos_y <= rhs.pos_y;
}

bool E0::Vector::operator==(const Vector& rhs)
{
	return this->pos_x == rhs.pos_x && this->pos_y == rhs.pos_y;
}

