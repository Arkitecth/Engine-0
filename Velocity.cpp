#include "Velocity.h"
#include "Vector.h"


E0::Velocity::Velocity()
{
}


E0::Velocity::Velocity(Vector new_direction, float new_speed)
{
	direction = new_direction; 
	speed = new_speed; 
}


E0::Vector E0::Velocity::getDirection()
{
	return direction; 
}


float E0::Velocity::getSpeed()
{
	return speed; 
}

void E0::Velocity::setSpeed(float new_speed)
{
	speed = new_speed; 
}

void E0::Velocity::setDirection(E0::Vector new_direction)
{
	direction = new_direction; 
}

