project(ScreenCaptureModule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(ScreenCaptureModule SHARED ${SRC_FILES})

link_directories("${CMAKE_SOURCE_DIR}/Build/lib/Debug")  # 添加库搜索路径
target_link_libraries(ScreenCaptureModule PRIVATE LogModule)  # 链接具体库

set(FFMPEG_LIB_DIR "${CMAKE_SOURCE_DIR}/ThirdParty/ffmpeg-7.1.1-install/lib")
target_link_directories(ScreenCaptureModule PRIVATE ${FFMPEG_LIB_DIR})

# 显式链接FFMpeg库
target_link_libraries(ScreenCaptureModule PRIVATE
  avcodec avformat avutil swresample swscale avdevice postproc
)

# 输出 DLL 到统一 bin 目录
set_target_properties(ScreenCaptureModule PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

add_dependencies(ScreenCaptureModule LogModule)

set(FFMPEG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/ffmpeg-7.1.1-install/include")
target_include_directories(ScreenCaptureModule PRIVATE ${FFMPEG_INCLUDE_DIR})

set(MODULE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}")
target_include_directories(ScreenCaptureModule PRIVATE ${MODULE_INCLUDE_DIR})