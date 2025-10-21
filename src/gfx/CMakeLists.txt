cmake_minimum_required(VERSION 3.5)

project(vane_gfx LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/gl.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/render.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp"
)

add_library(
    ${PROJECT_NAME} OBJECT
    ${SOURCES}
)
