#include "Vector.h"
namespace E0
{
	const Vector UP = Vector{0, 1 }; 
	const Vector DOWN = Vector{0, -1}; 
	const Vector LEFT = Vector{-1, 0}; 
	const Vector RIGHT = Vector{0, 1}; 

	class Velocity 
	{
		private:
			Vector direction{}; 
			float speed{}; 
		public:
			Velocity(); 
			Velocity(Vector new_direction, float new_speed); 
			Vector getVelocity(); // Get the Velocity Vector (Scaled With Speed)
			void setVelocity(Vector new_velocity); 
			Vector getDirection(); 
			float getSpeed(); 
			void setSpeed(float new_speed); 
			void setDirection(Vector new_direction); 
	}; 
}
