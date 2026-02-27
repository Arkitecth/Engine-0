#pragma once
#include "Rectangle.h"
#include "Texture.h"
#include "Vector.h"
#include "Velocity.h"
#include <string>
#include "Event.h"
#include <string_view>
namespace E0
{
	static int current_entity_id = 0; 
	const std::string_view UNDEFINED_TYPE = "undefined_entity_type";
	class Entity
	{
		private:
			int entityID; 
			Vector position{}; 
			std::string entity_type{}; 
			float attackScore{}; 
			float defenseScore{}; 
			Velocity velocity{};
			float width{}; 
			float height{};
			//Animation extension should be added somewhere around here
			Texture entityTexture{};

		public:
			Entity(); 
			Entity(Vector new_position, Velocity new_velocity, std::string entity_type, float width, float height); 
			virtual ~Entity(); 
			virtual void eventHandler(Event* e); 
			virtual void draw(); 
			virtual void update(); 

			Vector getPosition(); 
			void setPosition(Vector new_position); 

			float getAttackScore(); 
			void setAttackScore(float new_attack_score); 

			float getDefenseScore(); 
			void setDefenseScore(float new_defense_score); 

			Texture getTexture(); 
			void setTexture(std::string new_texture_path); 

			float getWidth(); 
			float getHeight(); 

			void setWidth(); 
			void setHeight(); 

			std::string getEntityType(); 
			void setEntityType(std::string new_entity_type); 

			Vector predictPosition(); 

			int getEntityID(); 

			bool operator==(const Entity& rhs); 
	
	}; 
}
