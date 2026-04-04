#include "ArcherIcon.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "Vector.h"
#include <iostream>

ArcherIcon::ArcherIcon()
{
}

ArcherIcon::ArcherIcon(E0::Vector position, E0::Texture& texture)
{

	E0::Widget::setPosition(position); 

	E0::Widget::setTexture(texture);

	E0::Widget::setHeight(texture.getHeight());

	E0::Widget::setWidth(texture.getWidth());

}

void ArcherIcon::draw()
{
	E0::Rectangle rect{E0::Widget::getPosition(), E0::Widget::getWidth(), E0::Widget::getHeight()};

	DM.drawRectangle(rect);
		
	DM.drawTexture(*this->getTexture(), rect);
}

void ArcherIcon::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::MSE_EVENT) 
	{
		const E0::EventMouse* mouseEvent = dynamic_cast<const E0::EventMouse*>(e);

		if (mouseEvent->getAction() == E0::MouseAction::MOUSE_DRAGGED) 
		{
			float mouse_x = mouseEvent->getMousePosition().getX();
			float mouse_y = mouseEvent->getMousePosition().getY();

			//float offset_x = this->getWidth() / 2.0f;
			//float offset_y = this->getHeight() / 2.0f;

			E0::Vector new_position{mouse_x, mouse_y};

			this->setPosition(new_position);

		}

		if (mouseEvent->getAction() == E0::MouseAction::MOUSE_CLICKED) 
		{
			std::cout <<  "MOUSE WAS CLICKED" << '\n';
		}



	}
}

