#include "Entity.h"
#include "Level.h"
#include "ResourceManager.h"
#include "Texture.h"
#pragma once



class Tower: public E0::Entity
{
	enum State 
	{
		IDLE, 
		ATTACK, 
	};
	private:
		int attackScore{};
		E0::Texture roofTexture{};	
		E0::Texture bodyTexture{};
		E0::Texture headTexture{};
		E0::Animation animation{};
		float coolDownTimer{};
		State currentState{};
		E0::Level* currentLevel;
	public:
		 Tower(std::string_view path_to_tower_roof, std::string_view path_to_tower_body, std::string_view path_to_head_texture, E0::Level* level); 
		 void eventHandler(const E0::Event* e);
		 void draw();
		 void attack();
};
