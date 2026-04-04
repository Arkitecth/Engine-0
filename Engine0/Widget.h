#include "Event.h"
#include "Texture.h"
#include "Vector.h"
#pragma once
namespace E0
{
	class Widget 
	{
		private:
			E0::Vector position{};
			E0::Texture texture{};
			float width{};
			float height{};

		public:
			Widget(); 
			Widget(E0::Vector position, float width, float height, E0::Texture texture); 
			virtual void draw(); 
			virtual void eventHandler(const E0::Event* e); 
			void setTexture(E0::Texture& texture); 
			Texture* getTexture(); 
			float getWidth(); 
			void setWidth(float new_width);
			float getHeight(); 
			void setHeight(float new_height);
			void setPosition(E0::Vector new_position); 
			E0::Vector getPosition();

	}; 
}

