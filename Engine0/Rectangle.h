#pragma once
#include "Color.h"
#include "Vector.h"
namespace E0
{
	struct Rectangle 
	{
		Vector position{};
		float width{};
		float height{};
		Color color{};
	}; 
}
