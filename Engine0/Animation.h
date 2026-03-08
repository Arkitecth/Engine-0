#include "Texture.h"
#include <vector>
namespace E0
{
	class Animation
	{
		private:
			int animationIndex{};
			float animationTimer{};
			std::vector<Texture> animationTextures{};
		public:
			Animation(); 
			Animation(std::vector<std::string> animation_file_paths); 
			~Animation(); 
			int  getAnimationIndex(); 
			void setAnimationTimer(float new_animation_timer); 
			float getAnimationTimer(); 
			int getAnimationSize(); 
			const Texture& getCurrentTexture() const; 
			void setAnimationIndex(int new_index); 
			const std::vector<Texture>* getAnimationTextures() const; 
			void insertAnimationTexture(Texture texture); 
			void clearAnimationTextures(); 
	}; 

}
