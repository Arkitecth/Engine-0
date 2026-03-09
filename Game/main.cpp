#include <Engine.h>
#include "Enemy.h"
#include "Level.h"
#include <DisplayManager.h>
#include <ResourceManager.h>

int main()
{
	Engine.startUp(1000, 1000, "My Engine");
	Engine.setFrameRate(60); 
		E0::Level level{};
		Enemy enemy{};
		level.setLevelsName("Level 1"); 
		level.setTexturePath("./Assets/game_background_1.png"); 
		level.addEntity(&enemy); 
	Engine.run(); 
}
