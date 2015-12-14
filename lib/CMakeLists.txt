project(libGPCGLWrappers)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}-targets.cmake)
configure_file(${PROJECT_NAME}-config.cmake.in ${PROJECT_NAME}-config.cmake @ONLY)
export(PACKAGE ${PROJECT_NAME} )
