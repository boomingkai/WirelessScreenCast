project(CastSenderCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(CastSenderCore SHARED ${SRC_FILES})

link_directories("${CMAKE_SOURCE_DIR}/Build/lib/Debug")  # 添加库搜索路径
target_link_libraries(CastSenderCore PRIVATE LogModule)  # 链接具体库
target_link_libraries(CastSenderCore PRIVATE ScreenCaptureModule)  # 链接具体库
target_link_libraries(CastSenderCore PRIVATE RingBufferModule)  # 链接具体库

# 输出 DLL 到统一 bin 目录
set_target_properties(CastSenderCore PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

add_dependencies(CastSenderCore LogModule)
add_dependencies(CastSenderCore ScreenCaptureModule)
add_dependencies(CastSenderCore RingBufferModule)

set(MODULE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}")
target_include_directories(CastSenderCore PRIVATE ${MODULE_INCLUDE_DIR})