#include "Entity.h"

E0::Entity::Entity(E0::Vector new_position, float new_attack_score, float new_defense_score, float new_movement_speed, std::string new_texture_path)
{
	position = new_position; 
	attackScore = new_attack_score; 
	defenseScore = new_defense_score;
	movementSpeed = new_movement_speed; 
	texturePath = new_texture_path; 
}

E0::Vector E0::Entity::getPosition()
{
	return position;
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

float E0::Entity::getMovementSpeed()
{
	return movementSpeed; 
}

void E0::Entity::setMovementSpeed(float new_movement_speed)
{
	movementSpeed = new_movement_speed; 
}

float E0::Entity::getDefenseScore()
{
	return defenseScore; 
}

void E0::Entity::setDefenseScore(float new_defense_score)
{
	defenseScore = new_defense_score; 
}


std::string E0::Entity::getTexturePath()
{
	return texturePath;
}

void E0::Entity::setTexturePath(std::string new_texture_path)
{
	texturePath = new_texture_path; 
}





