cmake_minimum_required(VERSION 3.5)

project(vane_core LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/A.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/B.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/C.cpp"
)

add_library(
    ${PROJECT_NAME} OBJECT
    ${SOURCES}
)
