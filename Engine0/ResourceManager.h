#pragma once
#include "Animation.h"
#include <string_view>
#define RM E0::ResourceManager::getInstance()
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
			Animation getAnimation(std::string_view directory_path, std::string_view animation_qualifier); 
	}; 
}
