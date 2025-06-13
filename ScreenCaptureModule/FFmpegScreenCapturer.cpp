#include "FFmpegScreenCapturer.h"
extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavutil/avutil.h"
#include <libavdevice/avdevice.h>
#include <libavutil/pixfmt.h>
#include <libavutil/pixdesc.h>
}

#include <string>
#include <sstream>
#include <thread>
#include "LogModule/Loglib.h"

bool FFmpegScreenCapturer::Init(int displayIndex)
{
    avdevice_register_all();
    return true;
}

bool FFmpegScreenCapturer::Start(FrameCallback cb)
{
    if (m_is_running || !SetCapturerPara())
    {
        return false;
    }

    m_is_running = true;

    m_screen_capture_thread = std::thread([this, cb = std::move(cb)]()
    {
        while (m_is_running) {
            GetFrameData(cb);
            std::this_thread::sleep_for(std::chrono::milliseconds(33)); // 30fps
        }
    });
    return true;
}

bool FFmpegScreenCapturer::SetCapturerPara()
{
    // set input format for gdigrab
    const AVInputFormat* inputFormat = av_find_input_format("gdigrab");
    if (!inputFormat)
    {
        LogMessage(LOG_ERROR, "Cannot find gdigrab input format.");
        return false;
    }

    // set fps
    av_dict_set(&m_options, "framerate", std::to_string(k_frame_rate).c_str(), 0);
    // set capture resolution
    av_dict_set(&m_options, "video_size", "2560x1440", 0);

    if (avformat_open_input(&m_fmt_ctx, "desktop", inputFormat, &m_options) != 0)
    {
        LogMessage(LOG_ERROR, "Failed to open input device.");
        return false;
    }

    if (avformat_find_stream_info(m_fmt_ctx, nullptr) < 0)
    {
        LogMessage(LOG_ERROR, "Failed to get stream info.");
        avformat_close_input(&m_fmt_ctx);
        return false;
    }

    for (unsigned int i = 0; i < m_fmt_ctx->nb_streams; ++i)
    {
        if (m_fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            m_video_stream_index = i;
            break;
        }
    }
    if (m_video_stream_index == -1)
    {
        LogMessage(LOG_ERROR, "Cannot find video stream.");
        avformat_close_input(&m_fmt_ctx);
        return false;
    }

    av_dump_format(m_fmt_ctx, 0, "desktop", 0);
}

void FFmpegScreenCapturer::GetFrameData(FrameCallback cb)
{
    AVPacket pkt;
    if (av_read_frame(m_fmt_ctx, &pkt) < 0)
    {
        LogMessage(LOG_ERROR, "Failed to read frame data.");
        return;
    }

    if (pkt.stream_index == m_video_stream_index)
    {
        cb(reinterpret_cast<const char*>(pkt.data), pkt.size);
    }
    av_packet_unref(&pkt);
}

bool FFmpegScreenCapturer::ShutDown()
{
    if (!m_is_running)
    {
        return false;
    }

    m_is_running = false;

    if (m_screen_capture_thread.joinable())
    {
        LogMessage(LOG_INFO, "Screen Capture thread exiting...");
        m_screen_capture_thread.join();
    }
    avformat_close_input(&m_fmt_ctx);
    av_dict_free(&m_options);
    m_fmt_ctx = nullptr;
    m_options = nullptr;
    m_video_stream_index = -1;
    LogMessage(LOG_INFO, "Screen Capture thread exited");
    return true;
}
