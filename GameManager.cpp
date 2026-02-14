#include "GameManager.h"
#include <chrono>
#include <iostream>
#include <thread>


int E0::GameManager::getFrameRate()
{
	return frameRate; 
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


void E0::run(E0::GameManager& gm)
{
	using clock = std::chrono::steady_clock; 
	const auto frameTime = std::chrono::milliseconds(1000 / gm.getFrameRate());
	auto nextFrame = clock::now(); 
	while (!gm.getGameOver()) 
	{
		nextFrame += frameTime;

		std::cout << "Hello" << '\n';

		std::this_thread::sleep_until(nextFrame); 


	}
}

