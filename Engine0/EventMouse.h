#include <string>
#include "Event.h"
#include "Vector.h"
#pragma once
namespace E0
{
	const std::string MSE_EVENT = "E0::mouse_event"; 

	enum class MouseAction
	{
		MOUSE_CLICKED,
		MOUSE_RELEASED, 
		MOUSE_DRAGGED,
		UNDEFINED_ACTION
	}; 

	enum class MouseKey
	{
		MOUSE_LEFT_BUTTON, 
		MOUSE_RIGHT_BUTTON,
		UNDEFINED_KEY
	}; 

	
	class EventMouse: public Event 
	{
		private:
			MouseKey key; 
			Vector mouse_position{};
			MouseAction action; 
		
		public:
			EventMouse(); 
			EventMouse(MouseKey new_key, MouseAction new_action); 
			MouseKey getKey() const; 
			E0::Vector getMousePosition() const; 
			void setMousePosition(E0::Vector new_mouse_position);
			void setKey(MouseKey new_key); 
			MouseAction getAction() const; 
			void setMouseAction(MouseAction new_key_action); 
	}; 
}
