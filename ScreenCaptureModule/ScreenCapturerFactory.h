#pragma once

#include "FFmpegScreenCapturer.h"

class ScreemCaptureFactory
{
public:
	static IScreenCapturer* GetScreenCaptureInstance()
	{
		static IScreenCapturer* instance;
		instance = new FFmpegScreenCapturer();
		return instance;
	}

private:
	ScreemCaptureFactory() = default;
	ScreemCaptureFactory(const ScreemCaptureFactory&) = delete;
	ScreemCaptureFactory& operator=(const ScreemCaptureFactory&) = delete;
};