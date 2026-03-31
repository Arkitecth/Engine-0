#include "Entity.h"
#include "ResourceManager.h"
class Enemy: public E0::Entity
{
	private:
		int attackScore{};
		int defenseScore{};
		std::vector<E0::Vector> waypoints{};
		E0::Animation animation;
	public:
		 Enemy(); 
		 Enemy(E0::Vector new_spawn_position,float new_width, float new_height, E0::Animation new_animation); 
		 void eventHandler(const E0::Event* e);
		 E0::Entity* duplicate(); 
		 std::vector<E0::Vector> getWaypoints();
		 void moveTowards(E0::Vector destination); 
		 void setWaypoints(std::vector<E0::Vector> new_waypoint);
		 int getAttackScore(); 
		 void setAttackScore(int new_attack_score); 
		 int getDefenseScore(); 
		 void setDefenseScore(int new_defense_score); 
		 void draw();
		~Enemy();
}; 
