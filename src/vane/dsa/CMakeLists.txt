cmake_minimum_required(VERSION 3.11)

project(vane_dsa LANGUAGES CXX)

add_library(
    ${PROJECT_NAME} OBJECT
    "${CMAKE_CURRENT_SOURCE_DIR}/node.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tree.cpp"
)
