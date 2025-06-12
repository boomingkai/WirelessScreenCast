#include "CastSenderCore.h"
#include "LogModule/Loglib.h"
#include "ScreenCaptureModule/ScreenCapture.h"
#include <fstream>

void Init()
{
    InitLogger("../../log.txt");
    LogMessage(LOG_INFO, "Init logger complete");

    InitSC(0);
    LogMessage(LOG_INFO, "Init screen capture complete");

}

void StartCast()
{
    StartCapture(SCFrameCallBack);
}

void ShutDownCast()
{
    ShutDownSC();
    LogMessage(LOG_INFO, "Screen capture exited");

    ShutdownLogger();
    LogMessage(LOG_INFO, "Logger exited");
}

void SCFrameCallBack(const char* frame_data, int frame_size)
{
    static bool is_dumped = false;
    if (is_dumped)
    {
        return;
    }
    std::ofstream s;
    s.open("1.bmp",std::ios::binary);
    s.write(frame_data, frame_size);
    s.close();
    is_dumped = true;
}