#include "Entity.h"
#include "Rectangle.h"
#include "Vector.h"

bool CheckForIntersection(E0::Rectangle rectA, E0::Rectangle rectB); 
bool CheckForIntersection(E0::Vector pointA, float center_x, float center_y, int radius); 
E0::Rectangle getBox(const E0::Entity*); 
E0::Rectangle getBox(const E0::Entity*, E0::Vector where); 



