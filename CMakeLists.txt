cmake_minimum_required(VERSION 3.11)
project(DummyProject)

set(VANE_SDK_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vane_sdk/")
set(VANE_PROJ_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${VANE_SDK_DIRECTORY}/lib/")

set(VANE_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/libvane.a")
set(GLEW_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/libGLEW.a")
set(SDL2_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/libSDL2.a" "${CMAKE_SOURCE_DIR}/lib/libSDL2main.a")
set(GLEW_USE_STATIC_LIBS ON)
add_definitions(-DGLEW_STATIC)
find_package(OpenGL REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${CMAKE_SOURCE_DIR}/lib")

# add_subdirectory("${CMAKE_SOURCE_DIR}/external/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vane_sdk/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")

add_library(
    DummyProject OBJECT dummy.cpp
)