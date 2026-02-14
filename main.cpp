#include "Entity.h"
#include "LevelManager.h"
#include "GameManager.h"
#include "LogManager.h"
#include "Vector.h"
#include <iostream>
int main()
{
	E0::Level level1 {};
	level1.setLevelsName("Level 1"); 

	std::vector<E0::Entity> entities = level1.getAllEntities(); 

	E0::Entity enemy{}; 
	enemy.setEntityType("enemy"); 
	enemy.setTexturePath(".."); 
	enemy.setPosition(E0::Vector{100, 100}); 
	enemy.setMovementSpeed(1.0f); 

	E0::addEntity(entities, enemy); 

	E0::destroyEntity(enemy.getEntityID(), entities);

	std::cout << entities.size() << '\n';

	E0::LogManager logManager{};

	logManager.logInfo("Hey There");

	logManager.logError("Hey There");


	E0::GameManager gm {};
	gm.setFrameRate(30); 

	//E0::run(gm); 

}
