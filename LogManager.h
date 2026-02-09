#include <string>
#define LM E0::LogManager::get()
namespace E0
{
	struct LogManager
	{
		private:
			LogManager(); 
			LogManager(const LogManager&) = delete; 
			void operator=(const LogManager&) = delete; 
			int verbosity{};

		public:
			~LogManager(); 
			void log(std::string fmt, ...); 
			void fileLog(std::string_view fmt, std::string_view filePath, ...); 
			void startUp(); 
			int shutDown(); 
			static LogManager& get(); 
	}; 
}
