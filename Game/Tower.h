#include "Entity.h"
#pragma once
class Tower: public E0::Entity
{
	private:
		int attackScore{};
		E0::Texture roofTexture{};	
		E0::Texture bodyTexture{};
	public:
		 Tower(std::string_view path_to_tower_roof, std::string_view path_to_tower_body); 
		 void eventHandler(const E0::Event* e);
		 void draw();
};
