
add_library(libGPCGLWrappers INTERFACE)

target_include_directories(libGPCGLWrappers INTERFACE $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
