#include "GameManager.h"
#include "LevelManager.h"
#include "LogManager.h"
#include <chrono>
#include <iostream>
#include <thread>


E0::GameManager::GameManager()
{
	frameRate = DEFAULT_FRAME_RATE; 
	isGameOver = false;
	startUp(); 

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
}


void::E0::GameManager::shutDown()
{
	setGameOver(true); 
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


void E0::run()
{
	using clock = std::chrono::steady_clock; 
	const auto frameTime = std::chrono::milliseconds(1000 / GM.getFrameRate());
	auto nextFrame = clock::now(); 
	while (!GM.getGameOver()) 
	{
		nextFrame += frameTime;

		std::cout << "Hello" << '\n';

		std::this_thread::sleep_until(nextFrame); 


	}
}

