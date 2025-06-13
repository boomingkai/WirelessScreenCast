#include "CastSenderCore.h"
#include "LogModule/Loglib.h"
#include "ScreenCaptureModule/ScreenCapture.h"
#include <fstream>
#include <sstream>
#include "RingBufferModule/RingBuffer.h"

static ThreadSafeRingBuffer <const char*> s_bmp_queue(k_frame_rate);
static ThreadSafeRingBuffer <const char*> s_yuv_queue(k_frame_rate);
static ThreadSafeRingBuffer <const char*> s_h264_queue(k_frame_rate);

void Init()
{
    if (InitLogger("../../log.txt"))
    {
        LogMessage(LOG_INFO, "Init logger complete. 1/2");
    }
    
    if (InitSC(0))
    {
        LogMessage(LOG_INFO, "Init screen capture complete. 2/2");
    }




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
    s_bmp_queue.push(frame_data);



    /*static bool is_dumped = false;
    if (is_dumped)
    {
        return;
    }
    std::ofstream s;
    s.open("1.bmp",std::ios::binary);
    s.write(frame_data, frame_size);
    s.close();
    is_dumped = true;*/
}