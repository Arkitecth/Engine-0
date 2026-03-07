#include "Enemy.h"
#include "DisplayManager.h"
#include "Engine.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Vector.h"
#include <utility.h>
#include <ResourceManager.h>

Enemy::Enemy(): 
	animation{RM.getAnimationFiles("./Assets/Goblin/", "run")}
{
	E0::Entity::setPosition(E0::Vector{100, 25}); 
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(80.0f);
	E0::Entity::setWidth(80.0f);

}

Enemy::~Enemy()
{

}

void Enemy::draw()
{
	E0::Rectangle rect = getBox(this);
	// for(int i = 0; i < animation.getAnimationSize(); i++)
	// {
	// 	animation.setAnimationIndex(i); 
	// 	DM.drawTexture(animation.getCurrentTexture(), rect); 
	// }
	static float timer = 0.0f;
	float frameDuration = 0.0f; // 100ms per frame
	timer += 60.0f/ 1000;
	if (timer >= frameDuration) {
		animation.setAnimationIndex((animation.getAnimationIndex() + 1) % animation.getAnimationSize());
		timer = 0.0f;
	}
	DM.drawTexture(animation.getCurrentTexture(), rect);
}


void Enemy::eventHandler(const E0::Event* e)
{

}

int Enemy::getAttackScore()
{
	return attackScore;
}

void Enemy::setAttackScore(int new_attack_score)
{
	attackScore = new_attack_score;
}

int Enemy::getDefenseScore()
{
	return defenseScore;
}

void Enemy::setDefenseScore(int new_defense_score)
{
	defenseScore = new_defense_score;
}
