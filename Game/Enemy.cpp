#include "Enemy.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Vector.h"
#include <utility.h>
#include <ResourceManager.h>
#include <EventStep.h>

Enemy::Enemy(): 
	animation{RM.getAnimationFiles("./Assets/Goblin/", "run")}
{
	E0::Entity::setPosition(E0::Vector{100, 25}); 
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(160.0f);
	E0::Entity::setWidth(160.0f);
	E0::Entity::setVelocity(E0::Velocity{E0::RIGHT, 1}); 
}
Enemy::~Enemy()
{

}

void Enemy::draw()
{
	E0::Rectangle box = getBox(this); 
	animation.animate(box);
}

void Enemy::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::EVENT_STEP && animation.isFrameFinished()) 
	{
		E0::Entity::setPosition(E0::Entity::predictPosition()); 
	}
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
