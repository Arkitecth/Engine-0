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
			Velocity(Vector direction, float speed); 
			Vector getDirection(); 
			float getSpeed(); 
			void setSpeed(float new_speed); 
			void setDirection(Vector new_direction); 
	}; 
}
