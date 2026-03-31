#include "Enemy.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Texture.h"
#include "Vector.h"
#include <utility.h>
#include <ResourceManager.h>
#include <EventStep.h>

Enemy::Enemy(): 
	animation{RM.getAnimationFiles("./Assets/Goblin/", "run")}
{
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(160.0f);
	E0::Entity::setWidth(160.0f);
	E0::Entity::setVelocity(E0::Velocity{E0::RIGHT, 1}); 
}

Enemy::Enemy(E0::Vector new_spawn_position, float new_width, float new_height, E0::Animation animation):
	animation{animation}
{
	E0::Entity::setPosition(new_spawn_position); 
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(new_height);
	E0::Entity::setWidth(new_width);
	E0::Entity::setVelocity(E0::Velocity{E0::RIGHT, 1}); 
}
Enemy::~Enemy()
{

}

E0::Entity* Enemy::duplicate()
{
	Enemy* new_enemy = new Enemy{};
	new_enemy->setEntityType(this->getEntityType()); 
	new_enemy->setHeight(this->getHeight());
	new_enemy->setWidth(this->getWidth());
	new_enemy->setPosition(this->getPosition());
	new_enemy->setVelocity(this->getVelocity());
	new_enemy->animation = animation;
	new_enemy->waypoints = waypoints;
	return new_enemy;
}

void Enemy::draw()
{
	E0::Rectangle box = getBox(this); 
	//DM.drawRectangle(box);
	animation.animate(box);
}
void Enemy::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::EVENT_STEP) 
	{
		if (waypoints.size() > 0) 
		{
			moveTowards(waypoints[0]); 
			E0::Entity::setPosition(E0::Entity::predictPosition()); 
		}
	}
}

int Enemy::getAttackScore()
{
	return attackScore;
}

void Enemy::setWaypoints(std::vector<E0::Vector> new_waypoints) 
{
	waypoints = new_waypoints;
}

std::vector<E0::Vector> Enemy::getWaypoints()
{
	return waypoints;
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

void Enemy::moveTowards(E0::Vector destination)
{
	E0::Vector rectCenter{getPosition().getX() + getWidth() / 2.0f, getPosition().getY() + getHeight() / 2.0f};
	E0::Vector delta = destination - rectCenter; 
	E0::Velocity newVelocity{delta.normalize(), getVelocity().getSpeed()}; 
	if (newVelocity.getDirection().getX() <= 0) 
	{
		animation.getCurrentTexture().setFlipMode(E0::TextureDirection::HORIZONTAL);
	} else {
		animation.getCurrentTexture().setFlipMode(E0::TextureDirection::NONE);

	}
	int distance = delta.magnitude();
	if (distance <= 0) {
		waypoints.erase(waypoints.begin());
	}
	setVelocity(newVelocity);
}
