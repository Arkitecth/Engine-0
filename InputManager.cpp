#include "InputManager.h"
#include <SDL3/SDL.h>
#include <iostream>
#include "Entity.h"
#include "GameManager.h"
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

void E0::InputManager::pollInput()
{
	SDL_Event e;  
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_EVENT_QUIT) {
			GM.setGameOver(true); 
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
			LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<Event*>(&mouseEvent)); 
		}


	}
}
