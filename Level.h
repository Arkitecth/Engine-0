#include <vector>
#include "Entity.h"
namespace E0
{
	class Level 
	{
		private:
			std::string levelName{}; 
			std::string levelTexturePath{}; 
			std::vector<Entity> entities{}; 
		
		public:
			Level() = default; 
			~Level() = default;
			std::string getLevelsName(); 
			void setLevelsName(std::string new_level_name); 	

			std::string getTexturePath(); 
			void setTexturePath(std::string new_texture_path); 

			std::vector<Entity> getEntities(); 
	}; 
			void addEntity(std::vector<Entity>&); 

			void destroyEntity(int entity_id, std::vector<Entity>&); 

}
