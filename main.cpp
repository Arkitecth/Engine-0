#include "Entity.h"
#include "GameManager.h"
#include "LevelManager.h"
#include "vector"
#include "iostream"
int main()
{
	std::vector<E0::Entity> entities; 
	E0::Entity enemy{};
	E0::Entity enemy2{};
	enemy.setEntityType("Enemy"); 
	enemy2.setEntityType("Enemy"); 
	E0::Level level{}; 
	E0::addEntity(level, enemy); 
	E0::addEntity(level, enemy2); 

	E0::run(); 



	for(int i = 0; i < level.getEntities().size(); i++)
	{
		std::cout << level.getEntities().at(i).getEntityID() << '\n';
	}
}
