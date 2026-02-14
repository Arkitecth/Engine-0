#include <fstream>
namespace E0
{
	const std::string log_file_name = "engine0.log"; 
	class LogManager 
	{
		private:	
			std::fstream log_file; 
			bool consoleFlush{};
		
		public:
			LogManager(); 
			~LogManager(); 
			void logError(std::string_view msg); 
			void logInfo(std::string_view msg); 
	}; 


}
