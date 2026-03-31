#include "Entity.h"
namespace E0
{
	class Spawner
	{
		private:
			E0::Entity prototype{};
			float spawnTimer{};

		public:
			Spawner();
			Spawner(E0::Entity new_prototype); 
			void setPrototype(E0::Entity new_prototype); 
			void setSpawnTimer(float new_spawn_timer); 
			float getSpawnTimer(); 
	}; 

}

