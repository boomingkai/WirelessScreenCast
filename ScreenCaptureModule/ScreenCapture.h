#pragma once

#ifdef ScreenCaptureModule_EXPORTS
#define SC_API __declspec(dllexport)
#else
#define SC_API __declspec(dllimport)
#endif

#include "ScreenCaptureCommon.h"
extern "C"
{
    SC_API void InitSC(int displayIndex = 0);
    SC_API void ShutDownSC();
    SC_API void StartCapture(FrameCallback cb);
}