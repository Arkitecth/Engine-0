#include "Entity.h"
#include "Vector.h"
E0::Entity::Entity()
{
	entity_type = UNDEFINED_TYPE;  
	entityID = current_entity_id; 
	current_entity_id += 1; 
}

E0::Entity::~Entity()
{
	delete this;
}

E0::Vector E0::Entity::getPosition() const
{
	return position;
}

void E0::Entity::draw()
{

}

E0::Entity* E0::Entity::duplicate()
{
	return nullptr;
}

float E0::Entity::getWidth() const
{
	return width;
}

float E0::Entity::getHeight() const
{
	return height; 
}

void E0::Entity::setWidth(float new_width)
{
	width = new_width;
}

void E0::Entity::setHeight(float new_height)
{
	height = new_height;
}

void E0::Entity::setVelocity(E0::Velocity new_velocity)
{
	velocity = new_velocity;
	velocity.setVelocityVector(new_velocity.getVelocityVector()); 
}

E0::Velocity E0::Entity::getVelocity() const
{
	return velocity;
}

E0::Vector E0::Entity::predictPosition()
{
	Vector new_vector{position.getX() + velocity.getVelocityVector().getX(), position.getY() + velocity.getVelocityVector().getY()}; 

	return new_vector;
}

void E0::Entity::setPosition(E0::Vector new_position)
{
	position.setXY(new_position.getX(), new_position.getY()); 
}

void E0::Entity::eventHandler(const Event* e) 
{

}

std::string E0::Entity::getEntityType() const
{
	return entity_type; 
}

void E0::Entity::setEntityType(std::string new_entity_type)
{
	entity_type = new_entity_type; 
}

int E0::Entity::getEntityID() const
{
	return entityID; 
}

bool E0::Entity::operator==(const Entity& rhs)
{
	return rhs.entityID == this->entityID; 
}
