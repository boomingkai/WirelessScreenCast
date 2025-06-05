cmake_minimum_required(VERSION 3.15)
project(WirelessScreenCastSolution)

# 设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/lib)

add_subdirectory(ScreenCaptureModule)
add_subdirectory(ColorConvertModule)
add_subdirectory(ConfigModule)
add_subdirectory(LogModule)
add_subdirectory(RingBufferModule)
add_subdirectory(WirelessScreenCastApplication)
