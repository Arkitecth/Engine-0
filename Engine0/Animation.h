#include "Texture.h"
#include <vector>
namespace E0
{
	class Animation
	{
		private:
			int animationIndex{};
			std::vector<Texture*> animationTextures{};
		public:
			Animation(); 
			Animation(std::vector<std::string> animation_file_paths); 
			~Animation(); 
			int  getAnimationIndex(); 
			int getAnimationSize(); 
			Texture* getCurrentTexture() const; 
			void setAnimationIndex(int new_index); 
			const std::vector<Texture*>* getAnimationTextures() const; 
			void insertAnimationTexture(Texture* texture); 
			void clearAnimationTextures(); 
	}; 

}
