#include "Vector.h"
namespace E0
{
	class Velocity 
	{
		private:
			Vector direction{}; 
			float speed{}; 
		public:
			Velocity(); 
			Velocity(Vector new_direction, float new_speed); 
			Vector getDirection(); 
			float getSpeed(); 
			void setSpeed(float new_speed); 
			void setDirection(Vector new_direction); 
	}; 
}
