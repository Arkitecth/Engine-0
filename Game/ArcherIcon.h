#include "Level.h"
#include "Vector.h"
#include <Widget.h>
#include "Tower.h"
#include <vector>
class ArcherIcon: public E0::Widget
{
	public: 
		bool dragging{};
		Tower* currentTower{};
		E0::Level* currentLevel{};
		std::vector<E0::Vector> towerPositions; 
		ArcherIcon();
		ArcherIcon(E0::Vector position, E0::Texture& texture, std::vector<E0::Vector> towerPositions, E0::Level& level); 
		void draw(); 
		void eventHandler(const E0::Event* e);
}; 
