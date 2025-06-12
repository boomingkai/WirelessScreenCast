#include "LogLib.h"
#include "LogInternal.h"

static Logger g_logger;

bool InitLogger(const char* logFilePath)
{
    return g_logger.Init(logFilePath);
}

void LogMessage(LogLevel level, const std::string& message)
{
    g_logger.Log(static_cast<int>(level), message);
}

void ShutdownLogger()
{
    g_logger.Shutdown();
}
