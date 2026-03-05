#include "Entity.h"
class Enemy: public E0::Entity
{
	private:
		int attackScore{};
		int defenseScore{};
	public:
		 Enemy(); 
		 void eventHandler(const E0::Event* e);
		 int getAttackScore(); 
		 void setAttackScore(int new_attack_score); 
		 int getDefenseScore(); 
		 void setDefenseScore(int new_defense_score); 
		 void draw();
		 void move(); 
		~Enemy();
}; 
