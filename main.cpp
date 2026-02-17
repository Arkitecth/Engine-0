#include "DisplayManager.h"
int main()
{
	// GM.startUp();
	//
	// 	std::vector<E0::Entity> entities; 
	// 	E0::Entity enemy{};
	// 	E0::Entity enemy2{};
	// 	enemy.setEntityType("Enemy"); 
	// 	enemy2.setEntityType("Enemy"); 
	// 	E0::Level level{}; 
	// 	E0::addEntity(level, enemy); 
	// 	E0::addEntity(level, enemy2); 
	// GM.shutDown();
	//
	// for(int i = 0; i < level.getEntities().size(); i++)
	// {
	// 	std::cout << level.getEntities().at(i).getEntityID() << '\n';
	// }
	
	DM.startUp(); 
	SDL_Event e; 
	bool run = true;
	while (run) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				run = false;
			}
		}

		DM.drawRectangle(30.0f, 30.0f, 100.0f, 100.0f, E0::GREEN); 
		DM.swapBuffer(E0::BLACK);
	}
}
