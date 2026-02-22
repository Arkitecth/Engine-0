#include <string>
#include "Event.h"
#pragma once
namespace E0
{
	const std::string mouse_event = "MSE_EVENT"; 


	enum class MouseAction
	{
		MOUSE_CLICKED,
		MOUSE_RELEASED, 
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
			MouseAction action; 
		
		public:
			EventMouse(); 
			EventMouse(MouseKey new_key, MouseAction new_action); 
			MouseKey getKey(); 
			void setKey(MouseKey new_key); 
			MouseAction getAction(); 
			void setMouseAction(MouseAction new_key_action); 
	}; 
}
