#include "iostream"
#include "Vector.h"

int main()
{
	E0::Vector vector{10.0f, 20.0f};
	std::cout << vector.getX() << '\n'; 
	std::cout << vector.getY() << '\n';
}
