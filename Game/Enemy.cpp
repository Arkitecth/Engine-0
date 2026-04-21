#include "Enemy.h"
#include "DisplayManager.h"
#include "Entity.h"
#include "LevelManager.h"
#include "Rectangle.h"
#include "Texture.h"
#include "Vector.h"
#include <utility.h>
#include "EventCollision.h"
#include <ResourceManager.h>
#include <EventStep.h>

Enemy::Enemy(): 
	animation{RM.getAnimationFiles("./Assets/Goblin/", "run")}
{
	E0::Entity::setEntityType("Enemy"); 
	E0::Entity::setHeight(160.0f);
	E0::Entity::setWidth(160.0f);
	E0::Entity::setVelocity(E0::Velocity{E0::RIGHT, 1}); 
	healthTexture.setLoadedTexture("./Assets/health_bar-04.png");
	healthPoints = 100; 
}

Enemy::Enemy(E0::Vector new_spawn_position, float new_width, float new_height, E0::Animation animation, std::string_view pathToTexture):
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
	E0::Vector position = E0::Vector{this->getPosition().getX(), this->getPosition().getY() + 10};
	E0::Rectangle healthRect{position, float(healthPoints), 10}; 
	DM.drawRectangle(healthRect);
	DM.drawTexture(healthTexture, healthRect);
	// DM.drawRectangle(box);
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
	if (e->getType() == E0::EVENT_COLISSION) 
	{
		const E0::EventColission* colissionEvent = dynamic_cast<const E0::EventColission*>(e);
		if (colissionEvent->getEntity02()->getEntityType() == "Projectile") 
		{
			healthPoints -= 1;
			if (healthPoints == 0) 
			{
				LEM.getCurrentLevel()->destroyEntity(this); 
			}
		}
	}
}

void Enemy::setWaypoints(std::vector<E0::Vector> new_waypoints) 
{
	waypoints = new_waypoints;
}

std::vector<E0::Vector> Enemy::getWaypoints()
{
	return waypoints;
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

