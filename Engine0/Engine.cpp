#include "Engine.h"
#include "Color.h"
#include "Cursor.h"
#include "DisplayManager.h"
#include "EventStep.h"
#include "LevelManager.h"
#include "ResourceManager.h"
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
	return 1000 / frameRate; 
}

float E0::GameManager::getDeltaTime()
{
	return deltaTime; 
}

void E0::GameManager::startUp(int window_width, int window_height, std::string_view title, std::string_view base_path)
{
	LM.startUp(); 
	RM.startUp();
	LEM.startUp(); 
	DM.startUp(window_width, window_height, title.data());
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
	RM.shutDown();
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
	Cursor cursor{};
	auto lastTime = clock::now();
	EventStep stepEvent{};
	auto nextFrame = clock::now(); 
	LM.logInfo("Engine is now running"); 
	while (!isGameOver) 
	{
		const auto currentTime = clock::now(); 
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime);
		deltaTime = static_cast<float>(duration.count());
		lastTime = currentTime;

		stepEvent.increment();

		nextFrame += frameTime;

		IM.pollInput(cursor); 

		if (LEM.getLevels().size() == 0) 
		{	
			LM.logError("No Level was added."); 
			Engine.shutDown();
			return;
		}

		LEM.getCurrentLevel()->broadcastEvent(dynamic_cast<const Event*>(&stepEvent));

		LEM.getCurrentLevel()->spawn(3.0f);

		LEM.getCurrentLevel()->update(); 

		LEM.getCurrentLevel()->draw(); 

		cursor.draw(); 

		std::this_thread::sleep_until(nextFrame); 

		DM.swapBuffer(E0::BLACK); 
	}
}

