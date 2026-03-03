#include "Entity.h"
class Enemy: public E0::Entity
{
	public:
		 Enemy(); 
		 void eventHandler(const E0::Event* e);
		 void draw();
		 void move(); 
		~Enemy();
}; 
