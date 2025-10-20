cmake_minimum_required(VERSION 3.5)

project(vane_io LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} OBJECT ${SOURCES})
