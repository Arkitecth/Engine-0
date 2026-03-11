#include "Entity.h"
#include "ResourceManager.h"
class Enemy: public E0::Entity
{
	private:
		int attackScore{};
		int defenseScore{};
		E0::Animation animation;
	public:
		 Enemy(); 
		 void eventHandler(const E0::Event* e);
		 int getAttackScore(); 
		 void setAttackScore(int new_attack_score); 
		 int getDefenseScore(); 
		 void setDefenseScore(int new_defense_score); 
		 void draw();
		~Enemy();
}; 
