#include "ArcherIcon.h"
#include "Color.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "Rectangle.h"
#include "Vector.h"
#include <iostream>
#include <vector>
#include "utility.h"

ArcherIcon::ArcherIcon()
{
}

ArcherIcon::ArcherIcon(E0::Vector position, E0::Texture& texture, std::vector<E0::Vector> tower_postions, E0::Level& level)
{
	E0::Widget::setPosition(position); 

	E0::Widget::setTexture(texture);

	E0::Widget::setHeight(texture.getHeight());

	E0::Widget::setWidth(texture.getWidth());

	this->towerPositions = tower_postions;

	this->currentLevel = &level;

}

void ArcherIcon::draw()
{
	E0::Rectangle rect{E0::Widget::getPosition(), E0::Widget::getWidth(), E0::Widget::getHeight()};
	DM.drawRectangle(rect);
	E0::Texture texture{"../LevelEditor/Assets/dot.png"};
	if (dragging) {
		for (auto points : towerPositions) 
		{
			E0::Rectangle rect{points, texture.getWidth(), texture.getHeight()}; 
			DM.drawTexture(texture, rect); 
		}
	}
		
	DM.drawTexture(*this->getTexture(), rect);

}

void ArcherIcon::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::MSE_EVENT) 
	{
		const E0::EventMouse* mouseEvent = dynamic_cast<const E0::EventMouse*>(e);

		if (mouseEvent->getAction() == E0::MouseAction::MOUSE_DRAGGED && dragging) 
		{
			float mouse_x = mouseEvent->getMousePosition().getX();
			float mouse_y = mouseEvent->getMousePosition().getY();

			float offset_x = this->getWidth() / 2.0f;
			float offset_y = this->getHeight() / 2.0f;

			E0::Vector new_position{mouse_x - offset_x, mouse_y - offset_y};

			currentTower->setPosition(new_position); 

			dragging = true;
		}

		if (mouseEvent->getAction() == E0::MouseAction::MOUSE_CLICKED) 
		{
			E0::Rectangle cursorRect{mouseEvent->getMousePosition(), 30, 30}; 

			E0::Rectangle rect{E0::Widget::getPosition(), E0::Widget::getWidth(), E0::Widget::getHeight()};

			bool didIntersect = CheckForIntersection(cursorRect, rect);
			if (didIntersect) 
			{
				Tower* tower = new Tower{"./Assets/Archer/1.png", "./Assets/Archer/2.png"};
				tower->setPosition(mouseEvent->getMousePosition());
				currentTower = tower;
				dragging = true;
				currentLevel->addEntity(tower); 
			}
		}
		if (mouseEvent->getAction() == E0::MouseAction::MOUSE_RELEASED) 
		{
			dragging = false;
			bool isValidPosition{};

			if (currentTower != nullptr) 
			{
				for (auto validPosition : towerPositions) 
				{
					E0::Rectangle rect{validPosition, 100, 100};
					E0::Rectangle towerbox = getBox(currentTower);
					if (CheckForIntersection(rect, towerbox)) 
					{
						isValidPosition = true;
						break;
					}
				}
				if (!isValidPosition) 
				{
					currentLevel->destroyEntity(currentTower);
					currentTower = nullptr;
				} 
			}
		}


	}
}

