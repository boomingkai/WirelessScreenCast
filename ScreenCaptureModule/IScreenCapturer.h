#pragma once

#include "ScreenCaptureCommon.h"

class IScreenCapturer {
public:
    virtual ~IScreenCapturer() = default;
    virtual void Init(int displayIndex) = 0;
    virtual void Start(FrameCallback cb) = 0;
    virtual void ShutDown() = 0;
};
