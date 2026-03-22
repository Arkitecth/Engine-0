#include "DisplayManager.h"
#include "InputManager.h"
#include <Color.h>
#include <Vector.h>
#include <Engine.h>
#include <Rectangle.h>
#include <utility.h>
#include <iostream>

void TestRectangle()
{
	E0::Rectangle rect{E0::Vector{100, 100}, 100, 100, E0::RED}; 

	E0::Rectangle rectB{E0::Vector{100, 100}, 100, 100, E0::RED}; 


	if (CheckForIntersection(rect, rectB)) 
	{
		std::cout << "Test Passed" << '\n';
	} else {
		std::cout << "Test Failed" << '\n';
	}

}

void TestCircle()
{
	Engine.startUp();
	while (!Engine.getGameOver()) {
		IM.pollInput();
		DM.drawCircle(100, 100, 30, E0::RED);
		DM.swapBuffer(E0::BLACK); 
	}

}

int main()
{
	TestCircle();
}
