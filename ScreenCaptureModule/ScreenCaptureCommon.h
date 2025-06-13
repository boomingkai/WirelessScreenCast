#pragma once
#include <functional>

const int k_frame_rate = 30;
using FrameCallback = std::function<void(const char* frame_data, int frame_size)>;