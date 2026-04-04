#include <Engine.h>
#include "Color.h"
#include "Enemy.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Texture.h"
#include "Tower.h"
#include "Level.h"
#include "Vector.h"
#include <DisplayManager.h>
#include "ArcherIcon.h"
#include "EventMouse.h"
#include <ResourceManager.h>


class Cursor: public E0::Entity
{
	public:
		void draw()
		{
			E0::Rectangle rect{E0::Vector{this->getPosition().getX(), this->getPosition().getY()}, 30, 30, E0::RED};
			DM.drawRectangle(rect);
		}

		void eventHandler(const E0::Event* e)
		{

			const E0::EventMouse* mouseEvent = dynamic_cast<const E0::EventMouse*>(e);
			if (e->getType() == E0::MSE_EVENT) 
			{
				float mouse_x = mouseEvent->getMousePosition().getX();
				float mouse_y = mouseEvent->getMousePosition().getY();
				float offset_x = this->getWidth() / 2.0f;
				float offset_y = this->getHeight() / 2.0f;
				E0::Vector new_position{mouse_x + offset_x, mouse_y + offset_y};
				this->setPosition(new_position);
			}
		}
}; 
int main()
{
	Engine.startUp(800, 450, "My Engine");
	Engine.setFrameRate(60);
	E0::Level level = RM.loadLevel("../LevelEditor/Levels/Level 1.lvl");
	Tower* tower = new Tower{"./Assets/Archer/1.png", "./Assets/Archer/2.png"};
	E0::Texture texture{"./Assets/Archer_Tower_UI/Archer_Icon.png"};

	ArcherIcon archerIcon{E0::Vector{100, 400}, texture};
	level.addWidget(&archerIcon);

	Cursor* cursor{new Cursor};

	Enemy* prototype = new Enemy{};
	prototype->setPosition(E0::Vector{-300, 82});
	prototype->setWaypoints(level.getWaypoints());

	level.setPrototype(prototype);
	level.addEntity(tower);
	level.addEntity(cursor);
	Engine.run(); 
}
