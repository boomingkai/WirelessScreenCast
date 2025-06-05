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

add_dependencies(WirelessScreenCastApplication ScreenCaptureModule)

add_custom_command(TARGET WirelessScreenCastApplication POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:ScreenCaptureModule>"
    "$<TARGET_FILE_DIR:WirelessScreenCastApplication>"
)