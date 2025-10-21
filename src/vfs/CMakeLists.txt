cmake_minimum_required(VERSION 3.11)

project(vane_vfs LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/vfs.cpp"
)

add_library(
    ${PROJECT_NAME} OBJECT
    ${SOURCES}
)
