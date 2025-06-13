#pragma once

#ifdef ScreenCaptureModule_EXPORTS
#define SC_API __declspec(dllexport)
#else
#define SC_API __declspec(dllimport)
#endif

#include "ScreenCaptureCommon.h"
extern "C"
{
    SC_API bool InitSC(int displayIndex = 0);
    SC_API bool ShutDownSC();
    SC_API bool StartCapture(FrameCallback cb);
}