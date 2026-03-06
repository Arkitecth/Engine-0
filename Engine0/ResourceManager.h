#include <string_view>
#include <vector>
#define RM ResourceManager::getInstance()
namespace E0
{
	class ResourceManager
	{
		private:
			ResourceManager(); 

		public:	
			static ResourceManager& getInstance(); 
			~ResourceManager(); 
			void startUp();
			void shutDown(); 
			std::vector<std::string> getAnimation(std::string_view directory_path); 
	}; 
}
