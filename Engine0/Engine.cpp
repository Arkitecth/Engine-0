#include "Engine.h"
#include "Color.h"
#include "DisplayManager.h"
#include "LevelManager.h"
#include "LogManager.h"
#include "InputManager.h"
#include <chrono>
#include <thread>


E0::GameManager::GameManager()
{
	frameRate = DEFAULT_FRAME_RATE; 
	isGameOver = false;
}

E0::GameManager::~GameManager()
{
	shutDown();
}


int E0::GameManager::getFrameRate()
{
	return frameRate; 
}

void E0::GameManager::startUp()
{
	LM.startUp(); 
	LEM.startUp(); 
	DM.startUp();
	IM.startUp();
	LM.logInfo("Engine has been booted"); 
}


void::E0::GameManager::shutDown()
{

	LM.logInfo("Engine is now shutting down"); 
	setGameOver(true); 
	IM.shutDown();
	DM.shutDown();
	LEM.shutDown(); 
	LM.shutDown(); 

}

void E0::GameManager::setFrameRate(int new_frame_rate)
{
	frameRate = new_frame_rate; 
}

void E0::GameManager::setGameOver(bool new_game_over)
{
	isGameOver = new_game_over;
}

bool E0::GameManager::getGameOver()
{
	return isGameOver;
}

E0::GameManager& E0::GameManager::getInstance()
{
	static GameManager gm; 

	return gm; 
}


void E0::GameManager::run()
{
	using clock = std::chrono::steady_clock; 
	const auto frameTime = std::chrono::milliseconds(1000 / frameRate);
	auto nextFrame = clock::now(); 
	LM.logInfo("Engine is now running"); 
	while (!isGameOver) 
	{
		nextFrame += frameTime;

		IM.pollInput(); 

		if (LEM.getLevels().size() == 0) 
		{	
			LM.logError("No Level was added."); 
			Engine.shutDown();
			return;
		}

		LEM.getCurrentLevel()->update(); 

		LEM.getCurrentLevel()->draw(); 

		std::this_thread::sleep_until(nextFrame); 

		DM.swapBuffer(E0::BLACK); 
	}
}

