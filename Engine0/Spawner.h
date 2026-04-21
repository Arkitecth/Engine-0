#pragma once
#include "Entity.h"
namespace E0
{
	class Spawner
	{
		private:
			E0::Entity* prototype{};
			float spawnTimer{};
			float spawnRate{};
		public:
			Spawner();
			Spawner(E0::Entity* new_prototype, float new_spawn_rate); 
			void setPrototype(E0::Entity* new_prototype); 
			void setSpawnTimer(float new_spawn_timer); 
			float getSpawnTimer(); 
			float getSpawnRate(); 
			void setSpawnRate(float new_spawn_rate); 
			E0::Entity* spawn(float rate);
	}; 

}

