project(WirelessScreenCastApplication LANGUAGES CSharp)

file(GLOB_RECURSE CS_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cs"
)

file(GLOB_RECURSE XAML_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.xaml"
)

add_executable(WirelessScreenCastApplication 
    ${CS_FILES}
    ${XAML_FILES}
)

set_property(TARGET WirelessScreenCastApplication PROPERTY
    VS_DOTNET_APPLICATION_DEFINITION "App.xaml"
)

set_property(TARGET WirelessScreenCastApplication PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")
set_property(TARGET WirelessScreenCastApplication PROPERTY VS_DOTNET_ENABLE_WINDOWS_FORMS FALSE)
set_property(TARGET WirelessScreenCastApplication PROPERTY VS_DOTNET_USE_WPF TRUE)
set_property(TARGET WirelessScreenCastApplication PROPERTY 
    VS_DOTNET_STARTUP_OBJECT "WirelessScreenCastApplication.App"
)

set_target_properties(WirelessScreenCastApplication PROPERTIES
    VS_DOTNET_REFERENCES "System;System.Data;System.Xml;System.CodeDom;PresentationCore;PresentationFramework;WindowsBase;System.Xaml"
    VS_GLOBAL_OutputType "WinExe"
)

set_target_properties(WirelessScreenCastApplication PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_dependencies(WirelessScreenCastApplication CastSenderCore)

set(FFMPEG_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/ffmpeg-7.1.1-install/bin")
set(X264_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/x264-install/bin")
# 查找 .dll 文件
file(GLOB FFMPEG_DLLS "${FFMPEG_BIN_DIR}/*.dll")
file(GLOB X264_DLLS "${X264_BIN_DIR}/*.dll")

# 设置目标目录
set(TARGET_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Build/bin/Debug")

# 添加复制 FFMPEG DLL 的命令
foreach(dll ${FFMPEG_DLLS})
    add_custom_command(TARGET WirelessScreenCastApplication POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${dll}"
        "${TARGET_BIN_DIR}/"
    )
endforeach()

# 添加复制 X264 DLL 的命令
foreach(dll ${X264_DLLS})
    add_custom_command(TARGET WirelessScreenCastApplication POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${dll}"
        "${TARGET_BIN_DIR}/"
    )
endforeach()
