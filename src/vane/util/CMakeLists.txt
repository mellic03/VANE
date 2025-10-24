cmake_minimum_required(VERSION 3.11)

project(vane_util LANGUAGES CXX)

add_library(
    ${PROJECT_NAME} OBJECT
    "${CMAKE_CURRENT_SOURCE_DIR}/cfgparser.cpp"
)
