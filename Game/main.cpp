#include <Engine.h>
#include "Enemy.h"
#include "Level.h"
#include "Vector.h"
#include <DisplayManager.h>
#include <ResourceManager.h>
int main()
{
	Engine.startUp(800, 450, "My Engine");
	Engine.setFrameRate(60); 
		E0::Level level = RM.loadLevel("../LevelEditor/Levels/Level 1.lvl");
		Enemy* prototype = new Enemy{};
		prototype->setPosition(E0::Vector{-300, 82});
		prototype->setWaypoints(level.getWaypoints());
		level.setPrototype(prototype);
	Engine.run(); 
}
