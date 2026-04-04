#include "EventMouse.h"
#include "Event.h"

E0::EventMouse::EventMouse()
{
	Event::setType(MSE_EVENT); 
	key = MouseKey::UNDEFINED_KEY;
	action = MouseAction::UNDEFINED_ACTION;
}

E0::EventMouse::EventMouse(E0::MouseKey new_key, MouseAction new_action)
{
	key = new_key;
	action = new_action;
}


E0::MouseKey E0::EventMouse::getKey() const
{
	return key;
}

void E0::EventMouse::setKey(E0::MouseKey new_key)
{
	key = new_key;
}

E0::MouseAction E0::EventMouse::getAction() const
{
	return action;
}

void E0::EventMouse::setMouseAction(E0::MouseAction new_action)
{
	action = new_action;
}

void E0::EventMouse::setRelativeX(float new_relative_x)
{
	relative_x = new_relative_x;
}

void E0::EventMouse::setRelativeY(float new_relative_y)
{
	relative_y = new_relative_y;
}

float E0::EventMouse::getRelativeX() const
{
	return relative_x;
}

float E0::EventMouse::getRelativeY() const
{
	return relative_y;
}

