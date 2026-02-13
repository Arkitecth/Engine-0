#include "Level.h"
#include "Entity.h"
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

std::vector<E0::Entity> E0::Level::getEntities(std::string entity_type)
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

std::vector<E0::Entity>& E0::Level::getAllEntities()
{
	return entities;
}


void E0::addEntity(std::vector<Entity>& entities, Entity& entity)
{
	entities.push_back(entity); 
}

void E0::destroyEntity(int entity_id, std::vector<Entity>& entities)
{
	auto it = entities.begin() + entity_id;
	entities.erase(it);
}




