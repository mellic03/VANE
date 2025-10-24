cmake_minimum_required(VERSION 3.11)

project(vane_devel)

find_package(OpenGL REQUIRED)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_debug")
else()
    set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_release")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin")
set(VANE_COMPILE_OPTIONS -Wno-missing-field-initializers)

add_subdirectory("${CMAKE_SOURCE_DIR}/external")

if(TARGET SDL2::SDL2main)
    set(SDL2_OPENGL_LIBRARIES "/usr/x86_64-w64-mingw32/lib/libopengl32.a" OpenGL::GL SDL2::SDL2main SDL2::SDL2 GLEW)
else()
    set(SDL2_OPENGL_LIBRARIES "/usr/x86_64-w64-mingw32/lib/libopengl32.a" OpenGL::GL SDL2::SDL2 GLEW)
endif()


include_directories("${CMAKE_SOURCE_DIR}/include/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")


file(COPY "${CMAKE_SOURCE_DIR}/vaneroot/" DESTINATION "${VANE_OUTPUT_DIR}/")
