#include "Projectile.h"
#include "DisplayManager.h"
#include "Entity.h"
#include "EventCollision.h"
#include "EventStep.h"
#include "LevelManager.h"
#include "utility.h"


Projectile::Projectile(E0::Vector new_position, std::string_view new_texture, E0::Entity* new_target)
{
	this->setPosition(new_position);
	texture.setLoadedTexture(new_texture); 
	target = new_target;
	this->setWidth(texture.getWidth());
	this->setHeight(texture.getHeight());
	this->setVelocity(E0::Velocity{E0::RIGHT, 3.0f});
	this->setEntityType("Projectile");
}

Projectile::~Projectile()
{

}

void Projectile::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::EVENT_STEP) 
	{
		move();
	}
	if (e->getType() == E0::EVENT_COLISSION) 
	{
		const E0::EventColission* colissionEvent = dynamic_cast<const E0::EventColission*>(e);
		if (colissionEvent->getEntity02()->getEntityType() == "Enemy") 
		{
			LEM.getCurrentLevel()->destroyEntity(this);
		}
	}
}

void Projectile::draw()
{
	E0::Rectangle rect = getBox(this); 
	DM.drawTexture(texture, rect); 
}

void Projectile::move()
{
	E0::Vector rectCenter{this->getPosition().getX() + getWidth() / 2.0f, this->getPosition().getY() + getHeight() / 2.0f};
	E0::Vector delta = target->getPosition() - rectCenter; 
	E0::Velocity newVelocity{delta.normalize(), this->getVelocity().getSpeed()}; 
	setVelocity(newVelocity); 
	E0::Entity::setPosition(E0::Entity::predictPosition()); 
}




