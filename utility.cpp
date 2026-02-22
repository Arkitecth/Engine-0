#include "utility.h"
#include "Vector.h"

bool CheckForIntersection(E0::Rectangle& rectA, E0::Rectangle& rectB)
{
	E0::Vector a1{rectA.position.getX(), rectA.position.getY()};

	E0::Vector a2{rectB.position.getX(), rectB.position.getY()};

	E0::Vector b1{rectA.position.getX() + rectA.width, rectB.position.getY()};

	E0::Vector b2{rectB.position.getX() + rectB.width, rectB.position.getY()};

	E0::Vector c1{rectA.position.getX(), rectB.position.getY() + rectA.height};

	E0::Vector c2{rectB.position.getX(), rectB.position.getY() + rectB.height};

	E0::Vector d1{rectA.position.getX() + rectA.width, rectA.position.getY() + rectA.height};

	E0::Vector d2{rectB.position.getX() + rectB.width, rectB.position.getY() + rectB.height};


	return a2 >= a1 || b1 >= b2 || c2 >= c1 || d1 >= d2;
}

