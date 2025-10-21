cmake_minimum_required(VERSION 3.5)

project(vane LANGUAGES CXX)

set(CMAKE_CXX_STANDARD "20")
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers")

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gfx/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/platform/")

add_library(
    ${PROJECT_NAME} STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/config.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vane.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/log.cpp"
    $<TARGET_OBJECTS:vane_core>
    $<TARGET_OBJECTS:vane_gfx>
    $<TARGET_OBJECTS:vane_platform>
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    SDL2::SDL2
    SDL2::SDL2main
    GLEW::GLEW
    OpenGL::GL
)
