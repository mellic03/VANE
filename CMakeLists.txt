cmake_minimum_required(VERSION 3.11)
project(vane_devel)

if(DEFINED ENV{VANE_OUTPUT_DIR})
    set(VANE_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/$ENV{VANE_OUTPUT_DIR}")
    message("VANE_OUTPUT_DIR=${VANE_OUTPUT_DIR}")
else()
    message(FATAL_ERROR "VANE_OUTPUT_DIR must be set!")
endif()

set(VANE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/")
set(VANE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${VANE_LIBRARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin")

set(VANE_LIBRARIES "${VANE_LIBRARY_DIR}/libvane.a")
set(SDL2_LIBRARIES "${VANE_LIBRARY_DIR}/libSDL2.a" "${VANE_LIBRARY_DIR}/libSDL2main.a")
set(GLEW_LIBRARIES "${VANE_LIBRARY_DIR}/libGLEW.a")
set(OPENGL_LIBRARIES "OpenGL::GL")

set(GLEW_USE_STATIC_LIBS ON)
add_definitions(-DGLEW_STATIC)
find_package(OpenGL REQUIRED)

include_directories("${VANE_INCLUDE_DIR}")
link_directories("${VANE_LIBRARY_DIR}")

add_subdirectory("${CMAKE_SOURCE_DIR}/external/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")
