#include <Engine.h>
#include "Enemy.h"
#include "Texture.h"
#include "Level.h"
#include "Vector.h"
#include <DisplayManager.h>
#include "Projectile.h"
#include "ArcherIcon.h"
#include <ResourceManager.h>

int main()
{
	Engine.startUp(800, 450, "My Engine", "../Engine0/");
	Engine.setFrameRate(60);
	E0::Level level = RM.loadLevel("../LevelEditor/Levels/Level 1.lvl");
	E0::Texture texture{"./Assets/Archer_Tower_UI/Archer_Icon.png"};
	//Projectile* projectile = new Projectile{E0::Vector{300, 500}, "./Assets/Arrow.png", E0::Vector{700, 200}}; 

	//<a href="https://www.flaticon.com/free-icons/select" title="select icons">Select icons created by Icon Hubs - Flaticon</a>
	ArcherIcon archerIcon{E0::Vector{100, 400}, texture, level.getTowerpoints(), level};
	level.addWidget(&archerIcon);

	//level.addEntity(projectile);

	Enemy* prototype = new Enemy{};
	prototype->setPosition(E0::Vector{-300, 82});
	prototype->setWaypoints(level.getWaypoints());

	level.setPrototype(prototype);
	Engine.run(); 
}


