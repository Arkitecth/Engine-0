#include "Level.h"
#include "Entity.h"
#include <algorithm>
#include <iostream>
#include <vector>

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

std::vector<E0::Entity> E0::Level::getEntitiesOfType(std::string entity_type)
{
	std::vector<Entity> entities_copy; 
	for(int i = 0; i < entities.size(); i++)
	{
		if (entities[i].getEntityType() == entity_type) {	
			entities_copy.push_back(entities[i]); 
		}
	}

	return entities_copy;
}

std::vector<E0::Entity>& E0::Level::getEntities()
{
	return entities;
}

void E0::Level::setEntities(std::vector<Entity> new_entities)
{
	entities = new_entities; 
}


void E0::addEntity(Level& level, Entity& entity)
{
	std::vector<Entity> entities = level.getEntities(); 
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		std::cout << "Duplicate Entities Not Allowed " << '\n';
		return;
	} 

	entities.push_back(entity); 
	level.setEntities(entities); 
}

void E0::destroyEntity(Level& level, Entity& entity)
{
	auto it = level.getEntities().begin() + entity.getEntityID();
	level.getEntities().erase(it);
}




