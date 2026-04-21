#include "Spawner.h"
#include "Engine.h"

E0::Spawner::Spawner()
{
	spawnRate = 0.0f; 
}

E0::Spawner::Spawner(E0::Entity* new_prototype, float new_spawn_rate)
{
	prototype = new_prototype;
	spawnRate = new_spawn_rate;
}

void E0::Spawner::setPrototype(E0::Entity* new_prototype)
{
	prototype = new_prototype;
}

E0::Entity* E0::Spawner::spawn(float rate)
{
	spawnTimer += Engine.getDeltaTime() / 1000;
	if (spawnTimer >= rate) 
	{
		E0::Entity* entity = prototype->duplicate();
		spawnTimer = 0.0f;
		return entity;
	} 
	return nullptr;
}

void E0::Spawner::setSpawnTimer(float new_spawn_timer)
{
	spawnTimer = new_spawn_timer;
}

float E0::Spawner::getSpawnTimer()
{
	return spawnTimer;
}

float E0::Spawner::getSpawnRate()
{
	return spawnRate;
}

void E0::Spawner::setSpawnRate(float new_spawn_rate)
{
	spawnRate = new_spawn_rate;
}


