#include "Animation.h"
#include "DisplayManager.h"
#include "Entity.h"
#include "Rectangle.h"
#include "Texture.h"

E0::Animation::Animation()
{

}

E0::Animation::~Animation()
{

}

E0::Animation::Animation(std::vector<std::string> animation_file_paths)
{
	for(int i = 0; i < animation_file_paths.size(); i++)
	{
		Texture entityTexture{animation_file_paths[i]};
		insertAnimationTexture(entityTexture); 
	}
}

const E0::Texture& E0::Animation::getCurrentTexture() const
{
	return animationTextures[animationIndex];
}

int E0::Animation::getAnimationIndex()
{
	return animationIndex;
}

void E0::Animation::setAnimationIndex(int new_index)
{
	animationIndex = new_index;
}

float E0::Animation::getAnimationTimer()
{
	return animationTimer;
}

void E0::Animation::setAnimationTimer(float new_animation_timer)
{
	animationTimer = new_animation_timer;
}

int E0::Animation::getAnimationSize()
{
	return animationTextures.size();
}

const std::vector<E0::Texture>* E0::Animation::getAnimationTextures() const
{
	return &animationTextures;
}

void E0::Animation::insertAnimationTexture(E0::Texture texture)
{
	animationTextures.push_back(texture); 
}

void E0::Animation::clearAnimationTextures()
{
	animationTextures.clear();
}

void animate(E0::Rectangle& dst_rect)
{
	E0::Animation animation{};
	float timer = animation.getAnimationTimer(); 
	animation.setAnimationTimer(timer + delta); 

	if (animation.getAnimationTimer() >= expectedFrameTime) 
	{
		animation.setAnimationIndex(animation.getAnimationIndex() + 1 % animation.getAnimationSize());
	} 
	DM.drawTexture(animation.getCurrentTexture(), dst_rect); 
}
