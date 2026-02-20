#include "Level.h"
#include "Entity.h"
#include "LevelManager.h"
#include <algorithm>
#include <iostream>
#include <vector>

std::string E0::Level::getLevelsName()
{
	return levelName; 
}

E0::Level::Level()
{
	LEM.addLevel(this); 
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

std::vector<E0::Entity*> E0::Level::getEntitiesOfType(std::string entity_type)
{
	std::vector<Entity*> entities_copy; 
	for(int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == entity_type) {	
			entities_copy.push_back(entities[i]); 
		}
	}

	return entities_copy;
}

std::vector<E0::Entity*> E0::Level::getAllEntities()
{
	return entities;
}

void E0::Level::setEntities(std::vector<Entity*> new_entities)
{
	entities = new_entities; 
}


void E0::addEntity(Level& level, Entity* entity)
{
	std::vector<Entity*> entities = level.getAllEntities(); 
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		std::cout << "Duplicate Entities Not Allowed " << '\n';
		return;
	} 

	entities.push_back(entity); 
	level.setEntities(entities); 
}

void E0::destroyEntity(Level& level, Entity* entity)
{
	auto it = level.getAllEntities().begin() + entity->getEntityID();
	level.getAllEntities().erase(it);
}

void E0::Level::broadcastEvent(E0::Event* event)
{
	for (Entity* entity : entities) {
		entity->eventHandler(event); 
	}
}




