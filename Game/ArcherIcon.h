#include <Widget.h>

class ArcherIcon: public E0::Widget
{
	public: 
		ArcherIcon();
		ArcherIcon(E0::Vector position, E0::Texture& texture); 
		void draw(); 
		void eventHandler(const E0::Event* e);
}; 
