#include "Spawner.h"

E0::Spawner::Spawner(E0::Entity new_prototype)
{
	prototype = new_prototype;
}

void E0::Spawner::setPrototype(E0::Entity new_prototype)
{
	prototype = new_prototype;
}


void E0::Spawner::setSpawnTimer(float new_spawn_timer)
{
	spawnTimer = new_spawn_timer;
}

float E0::Spawner::getSpawnTimer()
{
	return spawnTimer;
}


