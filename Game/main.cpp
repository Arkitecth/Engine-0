#include <Engine.h>
#include "Enemy.h"
#include "Level.h"
#include <DisplayManager.h>

int main()
{
	DM.setWindowTitle("Tower Defense"); 
	Engine.startUp();
		E0::Level level{};
		Enemy enemy{};
		level.setLevelsName("Level 1"); 
		level.setTexturePath("./Assets/game_background_1.png"); 
		level.addEntity(&enemy); 
	Engine.run(); 
}
