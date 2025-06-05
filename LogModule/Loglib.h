#pragma once

#ifdef LOGLIB_EXPORTS
#define LOGLIB_API __declspec(dllexport)
#else
#define LOGLIB_API __declspec(dllimport)
#endif

extern "C" {

    enum LogLevel
    {
        LOG_INFO,
        LOG_WARN,
        LOG_ERROR
    };

    LOGLIB_API bool InitLogger(const char* logFilePath);

    LOGLIB_API void LogMessage(LogLevel level, const char* message);

    LOGLIB_API void ShutdownLogger();
}
