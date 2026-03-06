#include "Vector.h"
#include "Frame.h"
#include <vector>
namespace E0
{
	class Animation
	{
		private:
			int animationIndex{};
			std::vector<Frame*> animationFrames{};
		public:
			Animation(); 
			~Animation(); 
			int  getAnimationIndex(); 
			void setAnimationIndex(int new_index); 
			std::vector<Frame*> getAnimationFrames() const; 
			void insertAnimationFrame(Frame* frame); 
			void clearAnimationFrames(); 
			void animate(E0::Vector position);
	}; 

}
