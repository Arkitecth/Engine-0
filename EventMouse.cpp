#include "EventMouse.h"
#include "Event.h"

E0::EventMouse::EventMouse()
{
	Event::setType(mouse_event); 

	key = MouseKey::UNDEFINED_KEY;
	action = MouseAction::UNDEFINED_ACTION;
}

E0::EventMouse::EventMouse(E0::MouseKey new_key, MouseAction new_action)
{
	key = new_key;
	action = new_action;
}


E0::MouseKey E0::EventMouse::getKey()
{
	return key;
}

void E0::EventMouse::setKey(E0::MouseKey new_key)
{
	key = new_key;
}

E0::MouseAction E0::EventMouse::getAction()
{
	return action;
}

void E0::EventMouse::setMouseAction(E0::MouseAction new_action)
{
	action = new_action;
}
