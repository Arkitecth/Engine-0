#include "Level.h"
#include "DisplayManager.h"
#include "Entity.h"
#include "Engine.h"
#include "LevelManager.h"
#include "EventCollision.h"
#include "Texture.h"
#include "Vector.h"
#include <algorithm>
#include <iostream>
#include "Widget.h"
#include "utility.h"
#include <vector>

std::string E0::Level::getLevelsName()
{
	return levelName; 
}

E0::Level::Level()
{
	LEM.addLevel(this); 
}

E0::Level::~Level()
{}

void E0::Level::destroy()
{
	for (auto entity : entities) {
		delete entity;
	}
}


void E0::Level::setLevelsName(std::string new_level_name)
{
	levelName = new_level_name; 
}

std::string E0::Level::getTexturePath()
{
	return levelTexturePath; 
}

void E0::Level::setWaypoint(std::vector<E0::Vector> new_waypoints)
{
	waypoints = new_waypoints;
}

void E0::Level::setTowerPoints(std::vector<E0::Vector> new_tower_points)
{
	towerPoints = new_tower_points;
}

std::vector<E0::Vector> E0::Level::getWaypoints()
{
	return waypoints;
}

std::vector<E0::Vector> E0::Level::getTowerpoints()
{
	return towerPoints;
}

void E0::Level::addWayPoint(E0::Vector vector)
{
	waypoints.push_back(vector);
}

void E0::Level::addTowerPoint(E0::Vector vector)
{
	towerPoints.push_back(vector);
}

void E0::Level::setPrototype(E0::Entity* prototype)
{
	spawnPrototype = prototype;
}

void E0::Level::setTexturePath(std::string new_texture_path)
{
	levelTexturePath = new_texture_path;
	levelTexture.setLoadedTexture(new_texture_path); 
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


void E0::Level::addEntity(Entity* entity)
{
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		std::cout << "Duplicate Entities Not Allowed " << '\n';
		return;
	} 

	entities.push_back(entity); 
}

void E0::Level::destroyEntity(Entity* entity)
{
	auto it = std::find(entities.begin(), entities.end(), entity);
	entities.erase(it);
	delete entity;
}

void E0::Level::broadcastEvent(const E0::Event* event)
{
	for (Entity* entity : entities) {
		entity->eventHandler(event); 
	}
	for (Widget* widget : uiLayout) {
		widget->eventHandler(event); 
	}

}

std::vector<E0::Entity*> E0::Level::getColissions(E0::Vector where, Entity* entity)
{
	std::vector<E0::Entity*> colissionList{}; 
	for (auto current_entity : entities) {
		if (current_entity == entity) {
			continue;
		}
		if (CheckForIntersection(getBox(entity, where), getBox(current_entity))) {
			colissionList.push_back(current_entity); 
		}

		float center_x = entity->getPosition().getX() + (entity->getWidth() / 2.0f);
		float center_y = entity->getPosition().getY() + (entity->getHeight() / 2.0f);
		if (CheckForIntersection(current_entity->getPosition(), center_x,  center_y, entity->getDetectionRadius())) {
			colissionList.push_back(current_entity); 
		}
	}

	return colissionList;
}

void E0::Level::draw()
{
	if (!levelTexturePath.empty()) 
	{
		DM.drawBackgroundTexture(&levelTexture); 
	}

	for(Widget* widget: uiLayout)
	{
		widget->draw();
	}


	for (Entity* entity : entities) {
		entity->draw();
	}

	
}

void E0::Level::update()
{
	std::vector<Entity*> current_entities = getAllEntities();
	for (Entity* entity : current_entities) {
		if (!entity) {
			continue;
		}
		std::vector<E0::Entity*> collidedEntities= getColissions(entity->predictPosition(), entity); 
		EventColission colissionEvent{}; 
		colissionEvent.setPosition(entity->predictPosition()); 
		for (Entity* collidedEntity : collidedEntities) {
			colissionEvent.setEntity01(entity); 
			colissionEvent.setEntity02(collidedEntity); 
		}
		if (collidedEntities.size() != 0) {
			entity->eventHandler(dynamic_cast<const Event*>(&colissionEvent)); 
		}
	}
}

void E0::Level::addWidget(E0::Widget* widget)
{
	uiLayout.push_back(widget);
}

void E0::Level::spawn(float rate)
{
	spawnTimer += Engine.getDeltaTime() / 1000;
	if (spawnTimer >= rate) 
	{
		this->addEntity(spawnPrototype->duplicate()); 

		spawnTimer = 0.0f;
	} 
}

void E0::Level::setUILayout(std::vector<Widget*> new_ui_layout)
{
	uiLayout = new_ui_layout;
}

std::vector<E0::Widget*> E0::Level::getUILayout()
{
	return uiLayout;
}

