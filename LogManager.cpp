#include "LogManager.h"
#include "iostream"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string_view>

std::string getTimeStamp()
{
	auto now = std::chrono::system_clock::now(); 
	auto time = std::chrono::system_clock::to_time_t(now);  
	std::tm tm; 

	localtime_r(&time, &tm);  
	std::ostringstream ss; 

	ss << std::put_time(&tm, "%H:%M:%S"); 

	return ss.str();
}

E0::LogManager::LogManager()
{
	log_file.open(log_file_name, std::ios::out | std::ios::app); 
	consoleFlush = true;
}

E0::LogManager::~LogManager()
{
	if (log_file.is_open()) {
		log_file.close();
	}
}

void E0::LogManager::logError(std::string_view msg)
{
	if (consoleFlush) {
		std::cout << "[" << getTimeStamp() << "]" << " [ERROR] " << msg << '\n';
	}

	log_file << "[" << getTimeStamp() << "]" << " [ERROR] " << msg << '\n';
	log_file.flush();
}

void E0::LogManager::logInfo(std::string_view msg)
{
	if (consoleFlush) {
		std::cout << "[" << getTimeStamp() << "]" << " [INFO] " << msg << '\n';
	}

	log_file << "[" << getTimeStamp() << "]" << " [INFO] " << msg << '\n';
	log_file.flush();

}
