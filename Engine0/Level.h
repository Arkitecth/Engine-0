#pragma once
#include <vector>
#include "Event.h"
#include "Entity.h"
#include "Widget.h"
#include "Vector.h"
#include "Spawner.h"
namespace E0
{
	class Level 
	{
		private:
			std::string levelName{}; 
			std::string levelTexturePath{}; 
			std::vector<Entity*> entities{}; 
			std::vector<E0::Vector> waypoints{};
			std::vector<E0::Vector> towerPoints{};
			std::vector<E0::Widget*> uiLayout{};
			Texture levelTexture{};
			float spawnTimer{};
			E0::Entity* spawnPrototype = nullptr;
		
		public:
			Level(); 
			~Level();
			std::string getLevelsName(); 
			void destroy(); 
			void setLevelsName(std::string new_level_name); 	
			std::string getTexturePath(); 

			void setTexturePath(std::string new_texture_path); 

			std::vector<E0::Vector> getWaypoints(); 

			std::vector<E0::Vector> getTowerpoints(); 

			void setPrototype(E0::Entity* new_prototype); 

			void spawn(float rate); 

			void addWayPoint(E0::Vector vector); 

			void addTowerPoint(E0::Vector vector); 

			void addWidget(E0::Widget* widget); 

			void setWaypoint(std::vector<E0::Vector> waypoints); 

			void setTowerPoints(std::vector<E0::Vector> towerPoints); 

			std::vector<Entity*> getEntitiesOfType(std::string entity_type); 

			std::vector<Entity*> getColissions(Vector where, Entity* entity);  

			std::vector<Entity*> getAllEntities();

			void setEntities(std::vector<Entity*> new_entities);

			void setUILayout(std::vector<Widget*> new_ui_layout);

			std::vector<Widget*> getUILayout();

			void update(); 

			void draw(); 

			void broadcastEvent(const E0::Event* event); 

			void addEntity(Entity* entity); 

			void destroyEntity(Entity* entity); 

	}; 
}
