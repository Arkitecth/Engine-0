#include "Animation.h"
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
		insertAnimationTexture(&entityTexture); 
	}
}

E0::Texture* E0::Animation::getCurrentTexture() const
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

int E0::Animation::getAnimationSize()
{
	return animationTextures.size();
}

const std::vector<E0::Texture*>* E0::Animation::getAnimationTextures() const
{
	return &animationTextures;
}

void E0::Animation::insertAnimationTexture(E0::Texture* texture)
{
	animationTextures.push_back(texture); 
	animationIndex += 1; 
}

void E0::Animation::clearAnimationTextures()
{
	animationTextures.clear();
}

