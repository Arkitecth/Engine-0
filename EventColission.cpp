#include "Entity.h"
#include "Event.h"
#include "EventCollision.h"
#include "Vector.h"

E0::EventColission::EventColission()
{
	E0::Event::setType(EVENT_COLISSION); 
	entity_01 = nullptr; 
	entity_02 = nullptr;
}


void E0::EventColission::setEntity01(E0::Entity* new_entity)
{
	entity_01 = new_entity;
}

void E0::EventColission::setEntity02(E0::Entity* new_entity)
{
	entity_02 = new_entity;
}


E0::Entity* E0::EventColission::getEntity01()
{
	return entity_01; 
}

E0::Entity* E0::EventColission::getEntity02()
{
	return entity_02; 
}

E0::Vector E0::EventColission::getPosition()
{
	return position;
}

void E0::EventColission::setPosition(E0::Vector new_position)
{
	position = new_position; 
}



