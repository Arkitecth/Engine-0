#pragma once
#include "Texture.h"
#include "Vector.h"
#include <string>
#include <string_view>

namespace E0
{
	static int current_entity_id = 0; 
	const std::string_view UNDEFINED_TYPE = "undefined_entity_type";
	class Entity
	{
		private:
			int entityID{}; 
			Vector position{}; 
			std::string entity_type{}; 
			float attackScore{}; 
			float defenseScore{}; 
			float movementSpeed{}; 
			//Animation extension should be added somewhere around here
			std::string texturePath{}; 
			Texture enemyTexture{};
			
		public:
			Entity(); 
			Entity(Vector new_position, std::string new_entity_type, float new_attack_score, float new_defense_score, float new_movement_speed, std::string new_texture_path); 
			~Entity() = default; 

			Vector getPosition(); 
			void setPosition(Vector new_position); 

			float getAttackScore(); 
			void setAttackScore(float new_attack_score); 

			float getMovementSpeed(); 
			void setMovementSpeed(float new_movement_speed); 

			float getDefenseScore(); 
			void setDefenseScore(float new_defense_score); 

			std::string getTexturePath(); 
			void setTexturePath(std::string new_texture_path); 


			std::string getEntityType(); 
			void setEntityType(std::string new_entity_type); 

			int getEntityID(); 

			bool operator==(const Entity& rhs); 
	
	}; 
}
