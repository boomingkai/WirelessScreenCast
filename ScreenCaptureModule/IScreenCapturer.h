#pragma once

#include "ScreenCaptureCommon.h"

class IScreenCapturer {
public:
    virtual ~IScreenCapturer() = default;
    virtual bool Init(int displayIndex) = 0;
    virtual bool Start(FrameCallback cb) = 0;
    virtual bool ShutDown() = 0;
};
