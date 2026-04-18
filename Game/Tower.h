#include "Entity.h"
#include "Texture.h"
#pragma once
class Tower: public E0::Entity
{
	private:
		int attackScore{};
		E0::Texture roofTexture{};	
		E0::Texture bodyTexture{};
		E0::Texture headTexture{};
	public:
		 Tower(std::string_view path_to_tower_roof, std::string_view path_to_tower_body, std::string_view path_to_head_texture); 
		 void eventHandler(const E0::Event* e);
		 void draw();
};
