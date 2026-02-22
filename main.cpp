#include "Entity.h"
#include "GameManager.h"
#include "Level.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Rectangle.h"
#include "Vector.h"
#include <iostream>
#include "utility.h"


void TestRectangle()
{
	E0::Rectangle rectA{E0::Vector{100, 100}, 100, 100};

	E0::Rectangle rectB{E0::Vector{100, 100}, 100, 100};

	if (CheckForIntersection(rectA, rectB)) {
		std::cout << "Test Passed " << '\n';
	} else {
		std::cout << "Test Failed" << '\n';
	}
}


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
	
	TestRectangle();
	class Enemy: public E0::Entity
	{
		public:
			Enemy(){
				E0::Entity::setEntityType("Enemy"); 
				E0::Entity::setAttackScore(10); 
				E0::Entity::setDefenseScore(10); 
			}

			~Enemy()
			{
				
			}
			
			void eventHandler(E0::Event* e)
			{
				if (e->getType() == E0::keyboard_event) {
					E0::EventKeyboard* keyboardEvent = dynamic_cast<E0::EventKeyboard*>(e); 
					std::cout << "Enemy listened to keyboard event " << int(keyboardEvent->getKey()) << '\n';
				}
				else if (e->getType() == E0::mouse_event) {
					E0::EventMouse* mseEvent = dynamic_cast<E0::EventMouse*>(e); 
					std::cout << "Enemy listened to mouse event " << int(mseEvent->getKey()) << '\n';
				}


			}
	};
	GM.startUp();
	E0::Level level{};
	Enemy enemy{};
	E0::addEntity(level, &enemy);
	E0::run();


}



