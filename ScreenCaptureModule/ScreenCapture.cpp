#include "ScreenCapture.h"
#include "ScreenCapturerFactory.h"

static IScreenCapturer* SC_Instance;
bool InitSC(int displayIndex)
{
    SC_Instance = ScreemCaptureFactory::GetScreenCaptureInstance();
    return SC_Instance->Init(displayIndex);
}

bool ShutDownSC()
{
    return SC_Instance->ShutDown();
}

bool StartCapture(FrameCallback cb)
{
    return SC_Instance->Start(cb);
}


