#include "DisplayManager.h"
#include "Entity.h"
#include "GameManager.h"
#include "Rectangle.h"
#include "Texture.h"
#include <iostream>
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
	
	// DM.startUp(); 
	// SDL_Event e;  
	// E0::Texture texture{"./game_background_1.png"}; 
	// bool run = true;
	// while (run) {
	// 	while (SDL_PollEvent(&e)) {
	// 		if (e.type == SDL_EVENT_QUIT) {
	// 			run = false;
	// 		}
	// 	}
	// 	E0::Rectangle rect{70.0f, 50.0f, 100.0f, 100.0f, E0::GREEN};
	// 	DM.drawRectangle(rect); 
	//
	//
	// 	E0::Rectangle rectA{};
	// 	E0::Rectangle rectB{};
	// 	DM.drawTexture(texture, rectA, rectB); 
	// 	DM.swapBuffer(E0::BLACK);
	//
	// }
	
	E0::run();
}
