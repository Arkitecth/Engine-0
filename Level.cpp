#include "Level.h"
#include "Entity.h"


std::string E0::Level::getLevelsName()
{
	return levelName; 
}

void E0::Level::setLevelsName(std::string new_level_name)
{
	levelName = new_level_name; 
}

std::string E0::Level::getTexturePath()
{
	return levelTexturePath; 
}

void E0::Level::setTexturePath(std::string new_texture_path)
{
	levelTexturePath = new_texture_path; 
}

std::vector<E0::Entity> E0::Level::getEntities()
{
	std::vector<Entity> entities_copy; 

	entities_copy = entities;

	return entities_copy;
}

void E0::addEntity(std::vector<Entity>& entities)
{

}


