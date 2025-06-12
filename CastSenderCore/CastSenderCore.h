#pragma once

#ifdef CastSenderCore_EXPORTS
#define CASTSENDERCORE_API __declspec(dllexport)
#else
#define CASTSENDERCORE_API __declspec(dllimport)
#endif

extern "C" {

    CASTSENDERCORE_API void Init();
    CASTSENDERCORE_API void StartCast();
    CASTSENDERCORE_API void ShutDownCast();
}

void SCFrameCallBack(const char* frame_data, int frame_size);