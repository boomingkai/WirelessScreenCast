#include "LogInternal.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <windows.h>

bool Logger::Init(const std::string& path)
{
    logFile.open(path, std::ios::app);
    return logFile.is_open();
}

void Logger::Log(int level, const std::string& message)
{
    if (!logFile.is_open()) return;

    std::lock_guard<std::mutex> lock(logMutex);

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    logFile << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] "
        << "[" << LevelToString(level) << "] "
        << message << std::endl;

    std::ostringstream logStream;
    logStream << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] "
        << "[" << LevelToString(level) << "] "
        << message;
    std::string fullLog = logStream.str();
            
    logFile << fullLog << std::endl;

    PrintToConsole(level, fullLog);
}

void Logger::Shutdown()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

std::string Logger::LevelToString(int level)
{
    switch (level)
    {
        case 0: return "INFO";
        case 1: return "WARN";
        case 2: return "ERROR";
        default: return "UNKNOWN";
    }
}

void Logger::PrintToConsole(int level, const std::string& msg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

    switch (level)
    {                       
        case 0: color = FOREGROUND_GREEN; break; // White (INFO)
        case 1: color = FOREGROUND_RED | FOREGROUND_GREEN; break; // Yellow (WARN)
        case 2: color = FOREGROUND_RED; break; // Red (ERROR)
    }

    SetConsoleTextAttribute(hConsole, color);
    std::cout << msg << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset
}