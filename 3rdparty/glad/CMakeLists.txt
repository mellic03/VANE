cmake_minimum_required(VERSION 3.11)

project(glad)

add_library(
    glad STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c"
)

target_include_directories(
    glad PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

install(
    TARGETS glad
    LIBRARY DESTINATION "bin/"
    ARCHIVE DESTINATION "lib/"
    INCLUDES DESTINATION "include/"
)

install(
    DIRECTORY "include/"
    DESTINATION "include/"
)
