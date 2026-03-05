#include "Enemy.h"
#include "DisplayManager.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Vector.h"

Enemy::Enemy()
{
	E0::Entity::setPosition(E0::Vector{100, 25}); 
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(65.0f);
	E0::Entity::setWidth(65.0f);
	E0::Entity::setTexture("./Assets/enemy.png");
}


Enemy::~Enemy()
{

}

void Enemy::draw()
{
	E0::Rectangle srcRect{};
	E0::Rectangle dstRect{E0::Entity::getPosition(), E0::Entity::getWidth(), E0::Entity::getHeight()};
	DM.drawTexture(E0::Entity::getTexture(), srcRect, dstRect); 
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
