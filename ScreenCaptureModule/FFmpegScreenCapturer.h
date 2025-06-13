#pragma once
#include "IScreenCapturer.h"
#include <atomic>
#include <thread>

class AVFormatContext;
class AVDictionary;


class FFmpegScreenCapturer : public IScreenCapturer
{
public:
    FFmpegScreenCapturer() = default;
    ~FFmpegScreenCapturer() = default;
    virtual bool Init(int displayIndex);
    virtual bool Start(FrameCallback cb);
    virtual bool ShutDown();

private:
    void GetFrameData(FrameCallback cb);
    bool SetCapturerPara();
private:
    AVFormatContext* m_fmt_ctx = nullptr;
    AVDictionary* m_options = nullptr;
    int m_video_stream_index = -1;
    std::atomic_bool m_is_running = false;
    std::thread m_screen_capture_thread;
};