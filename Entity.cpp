#include "Entity.h"
#include "Texture.h"
#include "Vector.h"
E0::Entity::Entity()
{
	entity_type = UNDEFINED_TYPE;  
	entityID = current_entity_id; 
	current_entity_id += 1; 
}

E0::Entity::~Entity()
{
}

E0::Entity::Entity(Vector new_position, Velocity new_velocity, std::string new_entity_type, float new_width, float new_height)
{
	position = new_position; 
	entity_type = new_entity_type; 
	velocity = new_velocity; 
	width = new_width; 
	height = new_height;
	entityID = current_entity_id; 
	current_entity_id += 1; 
}

E0::Vector E0::Entity::getPosition()
{
	return position;
}

E0::Vector E0::Entity::predictPosition()
{
	Vector new_vector{position.getX() + velocity.getVelocity().getX(), position.getY() + velocity.getVelocity().getY()}; 

	return new_vector;
}


void E0::Entity::setPosition(E0::Vector new_position)
{
	position.setXY(new_position.getX(), new_position.getY()); 
}

float E0::Entity::getAttackScore()
{
	return attackScore; 
}

void E0::Entity::setAttackScore(float new_attack_score)
{
	attackScore = new_attack_score; 
}

float E0::Entity::getDefenseScore()
{
	return defenseScore; 
}

void E0::Entity::setDefenseScore(float new_defense_score)
{
	defenseScore = new_defense_score; 
}

void E0::Entity::eventHandler(const Event* e)
{

}

E0::Texture E0::Entity::getTexture()
{
	return entityTexture;
}

void E0::Entity::setTexture(std::string new_texture_path)
{
	entityTexture.setTexture(new_texture_path); 
}


std::string E0::Entity::getEntityType()
{
	return entity_type; 
}

void E0::Entity::setEntityType(std::string new_entity_type)
{
	entity_type = new_entity_type; 
}

int E0::Entity::getEntityID()
{
	return entityID; 
}

bool E0::Entity::operator==(const Entity& rhs)
{
	return rhs.entityID == this->entityID; 
}

void draw()
{

}









