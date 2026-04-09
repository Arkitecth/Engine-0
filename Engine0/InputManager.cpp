#include "InputManager.h"
#include <SDL3/SDL.h>
#include "Cursor.h"
#include "DisplayManager.h"
#include "Engine.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "LevelManager.h"

void E0::InputManager::startUp()
{

}

void E0::InputManager::shutDown()
{

}

E0::InputManager& E0::InputManager::getInstance()
{
	static InputManager im; 

	return im;
}

E0::InputManager::InputManager()
{
	startUp();
}

E0::InputManager::~InputManager()
{
}

void E0::InputManager::pollInput(E0::Cursor& cursor)
{
	SDL_Event e;  
	while (SDL_PollEvent(&e)) {
		
		if (e.type == SDL_EVENT_QUIT) {
			Engine.setGameOver(true); 
		}

		if (e.type == SDL_EVENT_MOUSE_MOTION) 
		{
			EventMouse mouseEvent; 
			E0::Vector new_position = E0::Vector{e.motion.x, e.motion.y};
			float relative_x = cursor.getCursorPosition().getX() + e.motion.xrel;
			float relative_y = cursor.getCursorPosition().getY() + e.motion.yrel;
			int render_w{}; 
			int render_h{};
			SDL_GetRenderOutputSize(DM.getRenderer(), &render_w, &render_h); 

			if (relative_x < 0) relative_x = 0;
			if (relative_x > render_w) relative_x = render_w;
			if (relative_y < 0) relative_y = 0;
			if (relative_y > render_h) relative_y = render_h;

			E0::Vector boundedPosition{relative_x, relative_y};
			mouseEvent.setMousePosition(boundedPosition);
			if (dragging) 
			{
				mouseEvent.setMouseAction(MouseAction::MOUSE_DRAGGED);
			}
			cursor.setVectorPosition(boundedPosition);
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&mouseEvent)); 
		}

		if (e.type == SDL_EVENT_KEY_DOWN) {
			EventKeyboard keyboardEvent; 
			keyboardEvent.setKey(SDL_GetKeyName(e.key.key));
			keyboardEvent.setKeyboardAction(KeyboardAction::KEY_PRESSED); 
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&keyboardEvent)); 
		}


		else if (e.type == SDL_EVENT_KEY_UP) {
			EventKeyboard keyboardEvent; 
			keyboardEvent.setKey(SDL_GetKeyName(e.key.key));
			keyboardEvent.setKeyboardAction(KeyboardAction::KEY_RELEASED);
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&keyboardEvent)); 
		}

		else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			EventMouse mouseEvent; 
			if (e.button.button == SDL_BUTTON_LEFT) {	
				mouseEvent.setKey(MouseKey::MOUSE_LEFT_BUTTON); 
			} else if (e.button.button == SDL_BUTTON_RIGHT) {
				mouseEvent.setKey(MouseKey::MOUSE_RIGHT_BUTTON); 
			}
			mouseEvent.setMouseAction(MouseAction::MOUSE_CLICKED); 
			dragging = true;
			SDL_Log("X:%f: Y:%f", e.button.x, e.button.y);
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&mouseEvent)); 
		}

		else if (e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
			EventMouse mouseEvent; 
			if (e.button.button == SDL_BUTTON_LEFT) {	
				mouseEvent.setKey(MouseKey::MOUSE_LEFT_BUTTON); 
			} else if (e.button.button == SDL_BUTTON_RIGHT) {
				mouseEvent.setKey(MouseKey::MOUSE_RIGHT_BUTTON); 
			} 
			mouseEvent.setMouseAction(MouseAction::MOUSE_RELEASED); 
			dragging = false;
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&mouseEvent)); 
		}


	}
}
