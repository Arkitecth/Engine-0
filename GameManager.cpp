#include "GameManager.h"


int E0::GameManager::getFrameTime()
{
	return frameTime; 
}

void E0::GameManager::setFrameTime(int new_frame_time)
{
	frameTime = new_frame_time; 
}

void E0::GameManager::setGameOver(bool new_game_over)
{
	isGameOver = new_game_over;
}

bool E0::GameManager::getGameOver()
{
	return isGameOver;
}


void E0::run(E0::GameManager& gm)
{
	while (!gm.getGameOver()) 
	{
		//Run Display Code Over Here
		//Need to Refactor to Handle multiple Managers
		//Set Frame Rate
	}
}
