cmake_minimum_required(VERSION 3.11)

project(GLEW)

add_library(
    ${PROJECT_NAME} STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/glew.c"
)
