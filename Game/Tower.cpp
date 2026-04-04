#include "Tower.h"
#include "DisplayManager.h"
#include "Rectangle.h"
#include "Vector.h"
Tower::Tower(std::string_view path_to_tower_roof, std::string_view path_to_tower_body)
{
	roofTexture.setLoadedTexture(path_to_tower_roof);
	bodyTexture.setLoadedTexture(path_to_tower_body);
	this->setPosition(E0::Vector{368, 130}); 
}

void Tower::draw()
{
	E0::Rectangle bodyRect{this->getPosition(), bodyTexture.getWidth(), bodyTexture.getHeight()};
	E0::Rectangle roofRect{E0::Vector{this->getPosition().getX() + 10, this->getPosition().getY() - 25}, roofTexture.getWidth(), roofTexture.getHeight()};
	DM.drawTexture(bodyTexture, bodyRect);
	DM.drawTexture(roofTexture, roofRect);
}

void Tower::eventHandler(const E0::Event* e)
{
}
