#include "Entity.h"
#include "Texture.h"
#include <string_view>

class Projectile: public E0::Entity
{
	private:
		E0::Entity* target;
		E0::Texture texture{};

	public:
		void eventHandler(const E0::Event* e);
		void draw(); 
		~Projectile();
		Projectile(E0::Vector new_position, std::string_view new_texture_path, E0::Entity* new_target);
		void setTarget(E0::Vector new_target);
		void move(); 
}; 
