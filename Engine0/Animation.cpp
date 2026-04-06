#include "Animation.h"
#include "DisplayManager.h"
#include "Engine.h"
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
	slowdownTime = 0.5f;
}

E0::Texture& E0::Animation::getCurrentTexture()
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

void E0::Animation::setSlowdownTimer(float new_slowdown_time)
{
	slowdownTime = new_slowdown_time;
}

float E0::Animation::getSlowdownTimer()
{
	return slowdownTime;
}

int E0::Animation::getAnimationSize()
{
	return animationTextures.size();
}

bool E0::Animation::isFrameFinished()
{
	return frameFinished;
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

void E0::Animation::animate(E0::Rectangle& dst_rect)
{
	setAnimationTimer(animationTimer + Engine.getDeltaTime()); 

	if (getAnimationTimer() > getSlowdownTimer()) 
	{
		setAnimationIndex((getAnimationIndex() + 1) % getAnimationSize());
		setAnimationTimer(0.0f);
		frameFinished = true;
	}  
	else {
		frameFinished = false;
	}
	DM.drawTexture(getCurrentTexture(), dst_rect); 
}
