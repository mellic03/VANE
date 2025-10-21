cmake_minimum_required(VERSION 3.5)

set(VANE_SDK_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vane_sdk/")
set(VANE_PROJ_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${VANE_SDK_DIRECTORY}/lib/")

add_definitions(-DGLEW_STATIC)
set(GLEW_USE_STATIC_LIBS ON)
set(VANE_GLEW_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/libGLEW.a")
find_package(OpenGL REQUIRED)

add_subdirectory("${CMAKE_SOURCE_DIR}/external/")
include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${CMAKE_SOURCE_DIR}/lib")

add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vane_sdk/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")
