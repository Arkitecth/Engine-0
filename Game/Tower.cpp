#include "Tower.h"
#include "Color.h"
#include "DisplayManager.h"
#include "Engine.h"
#include "LevelManager.h"
#include "Projectile.h"
#include "Rectangle.h"
#include <EventCollision.h>
#include "ResourceManager.h"
#include "utility.h"
#include "Vector.h"

Tower::Tower(std::string_view path_to_tower_roof, std::string_view path_to_tower_body, std::string_view path_to_head_texture, E0::Level* level)
{
	animation = RM.getAnimationFiles("./Assets/ArcherAnimation/", ""); 
	animation.setSlowdownTimer(60.0f);
	roofTexture.setLoadedTexture(path_to_tower_roof);
	bodyTexture.setLoadedTexture(path_to_tower_body);
	headTexture.setLoadedTexture(path_to_head_texture);
	currentLevel = level;
	coolDownTimer = 0.0f;
	this->setEntityType("Tower"); 
	this->setWidth(roofTexture.getWidth());
	this->setHeight(bodyTexture.getHeight());
	this->setDetectionRadius(140.0f); 
}

void Tower::draw()
{
	float center_x = this->getPosition().getX() + (this->getWidth() / 2.0f);
	float center_y = this->getPosition().getY() + (this->getHeight() / 2.0f);
	E0::Rectangle bodyRect{this->getPosition(), bodyTexture.getWidth(), bodyTexture.getHeight()};
	E0::Rectangle roofRect{E0::Vector{this->getPosition().getX() + 10, this->getPosition().getY() - 25}, roofTexture.getWidth(), roofTexture.getHeight()};
	E0::Rectangle headRect{E0::Vector{this->getPosition().getX() + 50, this->getPosition().getY() - 30}, headTexture.getWidth(), headTexture.getHeight()};
	DM.drawTexture(bodyTexture, bodyRect);
	DM.drawTexture(roofTexture, roofRect);
	DM.drawHollowCircle(center_x, center_y, this->getDetectionRadius(), E0::BLUE);
	if (currentState == IDLE) 
	{
		DM.drawTexture(headTexture, headRect);
	} 
	else 
	{
		animation.animate(headRect); 
	}
}

void Tower::eventHandler(const E0::Event* e)
{
	if (e->getType() == E0::EVENT_COLISSION) 
	{
		const E0::EventColission* colissionEvent = dynamic_cast<const E0::EventColission*>(e);

		if (colissionEvent->getEntity02()->getEntityType() == "Enemy") 
		{
			currentState = ATTACK;
			coolDownTimer = coolDownTimer + Engine.getDeltaTime();
			if (coolDownTimer >= 300.0f) 
			{
				Projectile* projectile = new Projectile{this->getPosition(), "./Assets/Arrow.png", colissionEvent->getEntity02()}; 
				LEM.getCurrentLevel()->addEntity(projectile);
				coolDownTimer = 0.0f;
			}
		}
	} 
	else 
	{
		currentState = IDLE;
	}
}
