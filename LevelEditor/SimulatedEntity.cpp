#include "SimulatedEntity.h"
#include "Color.h"
#include "DisplayManager.h"
#include "Rectangle.h"
#include "Vector.h"

void SimulatedEntity::draw()
{
	// E0::Rectangle rect{position, 30, 30, E0::GREEN};
	// DM.drawRectangle(rect);
	DM.drawCircle(position.getX(), position.getY(), 10.0f, E0::GREEN); 
}

void SimulatedEntity::moveTowardsWaypoint()
{
	E0::Vector delta {waypoints[0] - position};

	int distance = delta.magnitude();

	if (distance <= 0) 
	{
		waypoints.erase(waypoints.begin()); 
	}

	E0::Velocity newVelocity{delta.normalize(), 1};

	velocity = newVelocity;

	position.setXY(position.getX() + velocity.getVelocityVector().getX(), position.getY() + velocity.getVelocityVector().getY());
}



