#include <string_view>
namespace E0
{
	struct LogManager
	{
		private:
			LogManager(); 
			LogManager(const LogManager&); 
			void operator=(const LogManager&); 
			int verbosity{};

		public:
			~LogManager(); 
			void print(std::string_view fmt, ...); 
			void print(std::string_view fmt, std::string_view filePath, ...); 
			void startUp(); 
			int shutDown(); 
			static LogManager& get(); 
	}; 
}
