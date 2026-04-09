#include "utility.h"
#include "Color.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Vector.h"

bool CheckForIntersection(E0::Rectangle rectA, E0::Rectangle rectB)
{
	//Rect A
	float leftA   = rectA.position.getX();
	float rightA  = rectA.position.getX() + rectA.width;
	float topA    = rectA.position.getY();
	float bottomA = rectA.position.getY() + rectA.height;

	//Rect B
	float leftB   = rectB.position.getX();
	float rightB  = rectB.position.getX() + rectB.width;
	float topB    = rectB.position.getY();
	float bottomB = rectB.position.getY() + rectB.height;


	return leftA <= rightB && rightA >= leftB && topA <= bottomB && bottomA >= topB;
}


bool CheckForIntersection(E0::Vector point, float center_x, float center_y, int radius)
{
	int dx = point.getX() - center_x;
	int dy = point.getY() - center_y;
	float decision = (dx * dx) + (dy * dy) - radius * radius;

	return decision <= 0; 
}


E0::Rectangle getBox(const E0::Entity* entity) 
{
	E0::Rectangle box{entity->getPosition(), entity->getWidth(), entity->getHeight(), E0::BLACK};

	return box; 
}

E0::Rectangle getBox(E0::Entity* entity, E0::Vector where)
{
	E0::Rectangle box{where, entity->getWidth(), entity->getHeight(), E0::BLACK};

	return box; 
}


