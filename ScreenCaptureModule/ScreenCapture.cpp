#include "ScreenCapture.h"
#include "ScreenCapturerFactory.h"

static IScreenCapturer* SC_Instance;
void InitSC(int displayIndex)
{
    SC_Instance = ScreemCaptureFactory::GetScreenCaptureInstance();
    SC_Instance->Init(displayIndex);
}

void ShutDownSC()
{
    SC_Instance->ShutDown();
}

void StartCapture(FrameCallback cb)
{
    SC_Instance->Start(cb);
}


