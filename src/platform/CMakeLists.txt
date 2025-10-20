cmake_minimum_required(VERSION 3.5)

project(vane_platform LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/keyboard.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mouse.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/platform.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window.cpp"
)

add_library(
    ${PROJECT_NAME} OBJECT
    ${SOURCES}
)
