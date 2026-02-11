#include "iostream"
#include "Vector.h"
#include "Enemy.h"

int main()
{
	E0::Vector vector{10.0f, 20.0f};
	std::cout << vector.getX() << '\n'; 
	std::cout << vector.getY() << '\n';

	E0::Enemy enemy{};
	std::cout << enemy.getPosition().getX() << '\n';
	std::cout << enemy.getPosition().getY() << '\n';
	enemy.setPosition(E0::Vector{100.0f, 200.0f}); 
	std::cout << enemy.getPosition().getX() << '\n';
	std::cout << enemy.getPosition().getY() << '\n';
}
