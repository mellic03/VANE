cmake_minimum_required(VERSION 3.11)

project(vane_devel)

find_package(OpenGL REQUIRED)
add_subdirectory("${CMAKE_SOURCE_DIR}/external" EXCLUDE_FROM_ALL)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_debug")
    set(VANE_COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers)
else()
    set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_release")
    set(VANE_COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin")

if(TARGET SDL2::SDL2main)
    set(VANE_SDL2_OPENGL_LIBRARIES GLEW OpenGL::GL SDL2::SDL2main SDL2::SDL2)
else()
    set(VANE_SDL2_OPENGL_LIBRARIES GLEW OpenGL::GL SDL2::SDL2)
endif()


include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${CMAKE_SOURCE_DIR}/external/GLEW/include/")

add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")


file(COPY "${CMAKE_SOURCE_DIR}/vaneroot/" DESTINATION "${VANE_OUTPUT_DIR}/")
