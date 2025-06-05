#pragma once
#include <fstream>
#include <mutex>
#include <string>

class Logger {
public:
    bool Init(const std::string& path);
    void Log(int level, const std::string& message);
    void Shutdown();
    void PrintToConsole(int level, const std::string& msg);

private:
    std::ofstream logFile;
    std::mutex logMutex;
    std::string LevelToString(int level);
};
