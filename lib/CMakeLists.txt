
add_library(libGPCGLWrappers INTERFACE)

target_include_directories(libGPCGLWrappers INTERFACE $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

export(TARGETS libGPCGLWrappers FILE libGPCGLWrappers-targets.cmake)
configure_file(libGPCGLWrappers-config.cmake.in libGPCGLWrappers-config.cmake @ONLY)
export(PACKAGE libGPCGLWrappers)
