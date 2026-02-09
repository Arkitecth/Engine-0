#include "LogManager.h"
#include <cstdarg>
#include <cstdio>
#include "SDL3/SDL_log.h"

E0::LogManager::~LogManager()
{

}

E0::LogManager::LogManager()
{
}

void E0::LogManager::startUp()
{
    verbosity = 0; 
}

int E0::LogManager::shutDown()
{
    return -1; 
}

E0::LogManager& E0::LogManager::get()
{
    static LogManager logManager; 

    return logManager; 
}


void E0::LogManager::log(std::string fmt, ...)
{
    va_list args; 
    va_start(args, fmt); 
    vprintf(fmt.c_str(), args);
    va_end(args);
}


// void E0::LogManager::print(std::string_view fmt, std::string_view filePath, ...)
// {
//
// }

