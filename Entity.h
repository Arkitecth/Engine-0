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
			virtual ~Entity(); 
			virtual void eventHandler(const Event* e);  
			virtual void draw(); 

			Vector getPosition() const; 
			void setPosition(Vector new_position); 

			float getAttackScore() const; 
			void setAttackScore(float new_attack_score); 

			Vector getVelocity() const; 
			void setVelocity(Velocity new_velocity); 

			float getDefenseScore() const; 
			void setDefenseScore(float new_defense_score); 

			Texture getTexture() const; 
			void setTexture(std::string new_texture_path); 

			float getWidth() const; 
			float getHeight() const; 

			void setWidth(float new_width); 
			void setHeight(float new_height); 

			std::string getEntityType() const; 
			void setEntityType(std::string new_entity_type); 

			Vector predictPosition(); 

			int getEntityID() const; 

			bool operator==(const Entity& rhs); 
	
	}; 
}
