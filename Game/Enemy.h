#include "Entity.h"
#include "ResourceManager.h"
class Enemy: public E0::Entity
{
	private:
		int healthPoints{};
		std::vector<E0::Vector> waypoints{};
		E0::Animation animation;
		E0::Texture healthTexture{};
	public:
		 Enemy(); 
		 Enemy(E0::Vector new_spawn_position,float new_width, float new_height, E0::Animation new_animation, std::string_view path_to_health_texture); 
		 void eventHandler(const E0::Event* e);
		 E0::Entity* duplicate(); 
		 std::vector<E0::Vector> getWaypoints();
		 void moveTowards(E0::Vector destination); 
		 void setWaypoints(std::vector<E0::Vector> new_waypoint);
		 void draw();
		~Enemy();
}; 
