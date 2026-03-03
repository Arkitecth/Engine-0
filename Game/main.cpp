#include <Engine.h>
#include "Level.h"
#include <DisplayManager.h>

int main()
{
	DM.setWindowTitle("Tower Defense"); 
	Engine.startUp();
		E0::Level level{};
		level.setLevelsName("Level 1"); 
		level.setTexturePath("./game_background_1.png"); 
	Engine.run(); 
}
