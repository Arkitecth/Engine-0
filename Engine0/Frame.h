#include "Vector.h"
#include "Texture.h"
namespace E0
{
	class Frame
	{
		private:
			float width{};
			float height{};
			Vector position{};
			Texture texture{};	

		public:
			Frame(); 
			~Frame();
			float getWidth() const; 
			float getHeight() const; 
			Vector getPosition() const;
			Texture* getTexture() const;

			void setWidth(float new_width); 
			void setHeight(float new_height); 
			void setPosition(Vector new_position); 
			void setTexture(std::string_view texture_path); 

			void draw();
	};
}
