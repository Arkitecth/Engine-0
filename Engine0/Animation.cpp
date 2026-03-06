#include "Animation.h"

E0::Animation::Animation()
{

}

E0::Animation::~Animation()
{

}


int E0::Animation::getAnimationIndex()
{
	return animationIndex;
}

void E0::Animation::setAnimationIndex(int new_index)
{
	animationIndex = new_index;
}

std::vector<E0::Frame*> E0::Animation::getAnimationFrames() const
{
	return animationFrames;
}

void E0::Animation::insertAnimationFrame(E0::Frame* frame)
{
	animationFrames.push_back(frame); 
}

void E0::Animation::clearAnimationFrames()
{
	animationFrames.clear();
}


void E0::Animation::animate(E0::Vector position)
{
	for (Frame* frame: animationFrames) 
	{
		frame->draw();
	}
}






