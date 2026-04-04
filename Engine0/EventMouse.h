#include <string>
#include "Event.h"
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
			float relative_x{}; //Used for dragging and offset from SDL
			float relative_y{};
			MouseAction action; 
		
		public:
			EventMouse(); 
			EventMouse(MouseKey new_key, MouseAction new_action); 
			MouseKey getKey() const; 

			void  setRelativeX(float new_relative_x);
			void  setRelativeY(float new_relative_y);

			float getRelativeX() const;
			float getRelativeY() const;

			void setKey(MouseKey new_key); 
			MouseAction getAction() const; 
			void setMouseAction(MouseAction new_key_action); 
	}; 
}
