#pragma once
#include "Vector.h"
#include <string>
#include <string_view>
namespace E0
{
	class Entity
	{
		private:
			Vector position{}; 
			float attackScore{}; 
			float defenseScore{}; 
			float movementSpeed{}; 
			//Animation extension should be added somewhere around here
			std::string texturePath{}; 
		public:
			Entity() = default; 
			Entity(Vector new_position, float new_attack_score, float new_defense_score, float new_movement_speed, std::string new_texture_path); 
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
		
	}; 
}
