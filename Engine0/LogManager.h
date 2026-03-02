#pragma once
#include <fstream>
#define LM E0::LogManager::getInstance()
namespace E0
{
	const std::string log_file_name = "engine0.log"; 
	class LogManager 
	{
		private:	
			std::fstream log_file; 
			bool consoleFlush{};
			LogManager(); 
		
		public:
			static LogManager& getInstance(); 
			void startUp(); 
			void shutDown(); 
			~LogManager(); 
			void logError(std::string_view msg); 
			void logInfo(std::string_view msg); 
	}; 


}
