#pragma once
#include <functional>

using FrameCallback = std::function<void(const char* frame_data, int frame_size)>;