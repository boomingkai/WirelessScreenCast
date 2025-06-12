#pragma once


#ifdef LogModule_EXPORTS
#define LOGLIB_API __declspec(dllexport)
#else
#define LOGLIB_API __declspec(dllimport)
#endif

#include <string>

extern "C" {
    enum LogLevel
    {
        LOG_INFO,
        LOG_WARN,
        LOG_ERROR
    };

    LOGLIB_API bool InitLogger(const char* logFilePath);

    LOGLIB_API void LogMessage(LogLevel level, const std::string& message);

    LOGLIB_API void ShutdownLogger();
}
