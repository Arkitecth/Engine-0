#include "EventMouse.h"
#include "Event.h"
#include "Vector.h"

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

E0::Vector E0::EventMouse::getMousePosition()
{
	return mouse_position;
}

void E0::EventMouse::setMousePosition(E0::Vector new_mouse_position)
{
	mouse_position = new_mouse_position;
}
