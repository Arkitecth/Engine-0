#pragma once
#include <vector>
#include "Event.h"
#include "Entity.h"
namespace E0
{
	class Level 
	{
		private:
			std::string levelName{}; 
			std::string levelTexturePath{}; 
			std::vector<Entity> entities{}; 
		
		public:
			Level(); 
			~Level() = default;
			std::string getLevelsName(); 
			void setLevelsName(std::string new_level_name); 	

			std::string getTexturePath(); 
			void setTexturePath(std::string new_texture_path); 

			std::vector<Entity> getEntitiesOfType(std::string entity_type); 

			std::vector<Entity>& getEntities();

			void setEntities(std::vector<Entity> new_entities);
			void broadcastEvent(E0::Event* event); 
	}; 
			
			void addEntity(Level& level, Entity& entity); 

			void destroyEntity(Level& level, Entity& entity); 

}
